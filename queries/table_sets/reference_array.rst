Reference Array Tables
======================

The tables for reference array properties can be retrieved through the :code:`getReferenceArrayTable` method of the
:code:`alex::TableSets` class. It takes either an index or a name. For the specification of reference array tables,
see :doc:`/types/properties/reference_array`.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId id;
        float            a;
    };

    struct Bar
    {
        alex::InstanceId  id;
        int32_t           b;
    };

    struct Baz
    {
        alex::InstanceId          id;
        alex::ReferenceArray<Foo> foo;
        alex::ReferenceArray<Bar> bar;
    };

    using FooDescriptor = alex::GenerateTypeDescriptor<alex::Member<"id", &Foo::id>, 
                                                       alex::Member<"a", &Foo::a>>;
    using BarDescriptor = alex::GenerateTypeDescriptor<alex::Member<"id", &Bar::id>,
                                                       alex::Member<"b", &Bar::b>>;
    using BazDescriptor = alex::GenerateTypeDescriptor<alex::Member<"id", &Baz::id>,
                                                       alex::Member<"foo", &Baz::foo>,
                                                       alex::Member<"bar", &Baz::bar>>;
    
    auto  bazDescriptor = BazDescriptor(...);
    auto  bazTables     = alex::TableSets(bazDescriptor);
    auto& fooTable      = bazTables.getReferenceArrayTable<0>();
    auto& alsoFooTable  = bazTables.getReferenceArrayTable<"foo">();
    auto& barTable      = bazTables.getReferenceArrayTable<1>();
    auto& alsoBarTable  = bazTables.getReferenceArrayTable<"bar">();
