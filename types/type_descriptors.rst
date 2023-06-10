Type Descriptors
================

Matching C++ classes to Alexandria types requires some manual work. To read and write properties, a class member
variable must be known. This information is stored in an :code:`alex::TypeDescriptor`. This type descriptor is used by
query objects to retrieve the tables in the database that belong to the type and find the appropriate class member
variables to write data to.

Consider a very simple type with just two primitive properties.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId id;
        float            x;
        int32_t          y;
    };

    alex::TypeLayout layout;
    layout.createPrimitiveProperty("x", alex::DataType::Float);
    layout.createPrimitiveProperty("y", alex::DataType::Int32);
    auto& fooType = *layout.commit(nameSpace, "foo").second;
    

A type descriptor can be defined through the :code:`alex::GenerateTypeDescriptor` utility. This generator takes a list
of :code:`alex::Member` types which hold pointers to member variables and a unique name by which to identify them. The
names can be used for writing :doc:`/queries/extended`. Note that although in all these examples the unique names match
the member variables of the structs, this is not required.

The order of these members as passed to the generator must match the order in which the properties were created. Also,
the first member must always be the identifier. A type descriptor instance can be created from an :code:`alex::Type`.
This will do a runtime check to see if the class members match the properties.

.. code-block:: cpp

    // Generate type descriptor typedef.
    using FooDescriptor = alex::GenerateTypeDescriptor<
        alex::Member<"id", &Foo::id>,
        alex::Member<"x", &Foo::x>,
        alex::Member<"y", &Foo::y>
    >;

    // Create instance of type descriptor from alex::Type.
    auto fooDesc = FooDescriptor(fooType);

Member Order
------------

The order of member variables in the class does not matter. Only the order in which they are passed to the type
descriptor is relevant. See the code snippet below, which is more or less equivalent to the previous.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId id;
        int32_t          y; // Flipped x and y.
        float            x;
    };

    using FooDescriptor = alex::GenerateTypeDescriptor<
        alex::Member<"id", &Foo::id>,
        alex::Member<"x", &Foo::x>, // x and y still in the same order to match alex::Type definition.
        alex::Member<"y", &Foo::y>
    >;

Nested Members
--------------

To facilitate typical class layouts with complex member variables, the generator can also receive a
:code:`alex::NestedMember` types.

.. code-block:: cpp

    struct float2
    {
        float x;
        float y;
    };

    struct mat2x2
    {
        alex::InstanceId id;
        float2           a;
        float2           b;
    };

    alex::TypeLayout float2Layout;
    float2Layout.createPrimitiveProperty("x", alex::DataType::Float);
    float2Layout.createPrimitiveProperty("y", alex::DataType::Float);
    auto& float2Type = *float2Layout.commit(nameSpace, "float2", alex::TypeLayout::Instantiable::False).second;

    alex::TypeLayout mat2x2Layout;
    mat2x2Layout.createNestedTypeProperty("a", float2Type);
    mat2x2Layout.createNestedTypeProperty("b", float2Type);
    auto& mat2x2Type = *mat2x2Layout.commit(nameSpace, "mat2x2", alex::TypeLayout::Instantiable::False).second;

In addition to a unique name and pointer to member variable, the :code:`alex::NestedMember` takes an
:code:`alex::MemberList` type. This list type itself takes a list of members. The generator expands all nested members.
Names are chained together using the :code:`'.'` character.

.. code-block:: cpp

    using Float2MemberList = alex::MemberList<alex::Member<"x", &float2::x>,
                                              alex::Member<"y", &float2::y>>;
    
    using MatrixDescriptor = alex::GenerateTypeDescriptor<
        alex::Member<"id", &mat2x2::id>,
        alex::NestedMember<"a", Float2MemberList, &mat2x2::a>, // Expands to alex::Member<"a.x", &mat2x2::a, &float2::x>, alex::Member<"a.y", &mat2x2::a, &float2::y>.
        alex::NestedMember<"b", Float2MemberList, &mat2x2::b>  // Expands to alex::Member<"b.x", &mat2x2::b, &float2::x>, alex::Member<"b.y", &mat2x2::b, &float2::y>.
    >;

To the :code:`alex::MemberList` you can also pass a :code:`alex::NestedMember`, allowing recursion of arbitrary depth.
Also note that, just as with the ordering of member variables, the class hierarchy can differ from the property
hierarchy. The above type, for example, could also have been defined as a completely flat class. Just because a type
has a nested property does not mean the class needs a nested member type and vice versa.

.. code-block:: cpp

    struct mat2x2
    {
        alex::InstanceId id;
        float            ax;
        float            ay;
        float            bx;
        float            by;
    };

    using MatrixDescriptor = alex::GenerateTypeDescriptor<
        alex::Member<"id", &mat2x2::id>,
        alex::Member<"a.x", &mat2x2::ax>,
        alex::Member<"a.y", &mat2x2::ay>,
        alex::Member<"b.x", &mat2x2::bx>,
        alex::Member<"b.y", &mat2x2::by>
    >;
