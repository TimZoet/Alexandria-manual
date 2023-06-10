A Practical Example
===================

Let us pretend we are developing an appplication that keeps track of bicycles and the people that own them. The below
diagram shows the specification of our data types that we came up with. It's fairly straightforward. A person has a name
and owns zero or more bicycles. (We use an array for the owned bicycles so that our application can also be sold in the
Netherlands, where people often own more than one biycle.) A bicycle has two wheels, each of which has a radius and
width.

.. figure:: /_static/images/types.svg

    A language agnostic specification of our data types.

In order to translate this specification to C++ code, we need to go through several steps. First, we have to define a
namespace. All types need to be stored in one. More details can be found on the :doc:`/types/namespaces` page.

.. code-block:: cpp

    auto lib    = alex::Library::create("example.db");
    auto& main  = library->createNamespace("main");

With a namespace, we can start defining type layouts and adding named properties to them. We can add primitive
properties (integers, floats) and string properties, as well as e.g. arrays of references. Full details on properties
can be found on the :doc:`/types/properties` pages. When done, we commit the layouts to register them in the database
as a finalized type. At that point, tables are generated that will hold instances of these types.

Important to note here is that if a layout was already registered under the same name in the same namespace, one of two
things will happen. If the existing type has an identical layout, it is simply returned. No new type is registered. If
the layout is different, an exception is thrown. What's nice about this is that the code for actually creating new
types when a library is accessed for the first time can be the same as that for reopening it when you want to verify
all your types are there. See also :doc:`/types/types`.

.. code-block:: cpp

    alex::TypeLayout wheelLayout;
    wheelLayout.createPrimitiveProperty("radius", alex::DataType::Float);
    wheelLayout.createPrimitiveProperty("width", alex::DataType::Float);
    // If main already contains a type wheel with a different layout, commit will throw.
    auto [commit, wheel] = wheelLayout.commit(main, "wheel", alex::TypeLayout::Instantiable::False);
    if (commit == alex::TypeLayout::Commit::Created)
        std::cout << "wheel did not exist yet" << std::endl;
    else
        std::cout << "wheel already existed" << std::endl;

    alex::TypeLayout bicycleLayout;
    bicycleLayout.createNestedTypeProperty("front_wheel", *wheel);
    bicycleLayout.createNestedTypeProperty("back_wheel", *wheel);
    auto& bicycle = *bicycleLayout.commit(main, "bicycle").second;

    alex::TypeLayout personLayout;
    personLayout.createStringProperty("name");
    personLayout.createReferenceArrayProperty("owned_bicycles", *bicycle);
    auto& person = *personLayout.commit(main, "person").second;

We also need to define some C++ classes that will correspond to our previously registered types. As you can see,
primitive properties are just primitive member variables in a class. Meanwhile, an array of references requires a
specific wrapper type. All these wrapper types are described on the same pages as their matching property.

.. code-block:: cpp

    struct Wheel
    {
        float radius = 0;
        float width  = 0;
    };

    struct Bicycle
    {
        alex::InstanceId id;
        Wheel            front;
        Wheel            back;
    };

    struct Person
    {
        alex::InstanceId              id;
        std::string                   name;
        alex::ReferenceArray<Bicycle> bicycles;
    };

Finally, we need to match the members of the classes with the types and their properties as we defined them previously.
This is done by defining :doc:`/types/type_descriptors`.

.. code-block:: cpp

    using WheelMemberList = alex::MemberList<alex::Member<"radius", &Wheel::radius>,
                                             alex::Member<"width", &Wheel::width>>;

    using BicycleDescriptor = alex::GenerateTypeDescriptor<
        alex::Member<"id", &BicycleDescriptor::id>,
        alex::NestedMember<"front", WheelMemberList, &BicycleDescriptor::front>,
        alex::NestedMember<"back", WheelMemberList, &BicycleDescriptor::back>
    >;
    
    using PersonDescriptor = alex::GenerateTypeDescriptor<
        alex::Member<"id", &Person::id>,
        alex::Member<"bycicles", &Person::bicycles>
    >;
    
    auto bicycleDesc = BicycleDescriptor(bicycle);
    auto personDesc = PersonDescriptor(person);

Once we have specified all these things, we can start running :doc:`/queries`.
