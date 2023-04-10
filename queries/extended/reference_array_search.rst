Reference Array Search
======================

To search for single :doc:`/types/properties/reference` properties, :doc:`/queries/extended/primitive_search` has got
you covered. Searching by :doc:`/types/properties/reference_array` properties is done through separate functions. The
:code:`alex::references` function is currently the only operator that is available. It searches for instances for which
the specified reference array property contains a reference to the specified object.

Single Operator
---------------

The :code:`alex::referenceSearch` takes a type descriptor plus a single operator and returns an
:code:`alex::SearchQuery`.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId id;
        float            a = 0.0f;
    };

    struct Bar
    {
        alex::InstanceId          id;
        alex::ReferenceArray<Foo> foos;
    };

    using FooDescriptor = alex::GenerateTypeDescriptor<alex::Member<"id", &Foo::id>,
                                                       alex::Member<"a", &Foo::a>>;
    
    using BarDescriptor = alex::GenerateTypeDescriptor<alex::Member<"id", &Bar::id>,
                                                       alex::Member<"foos", &Bar::foos>>;
    
    // Search all instances where Bar.foos[] contains a specific Foo.
    auto query = alex::referenceSearch(barDescriptor,
                                       alex::references<BarDescriptor, "foos">());
    
    // Assuming some valid Foo, search for all Bar that reference it.
    Foo foo{};
    for (alex::InstanceId id : query(foo.id))
    {
        Bar obj{.id = id};
        // Run an alex::GetQuery for Bar.
        ...
    }

Multiple Operators
------------------

There are also the :code:`alex::referenceSearchAnd` and :code:`alex::referenceSearchOr` functions, which combine
multiple operators to return the intersection and union of results, respectively. In simpler terms,
:code:`alex::referenceSearchAnd` returns all instances that reference each of the specified objects.
:code:`alex::referenceSearchOr` returns all instances that reference at least one of the specified objects.

.. code-block:: cpp

    struct Baz
    {
        alex::InstanceId id;
        alex::InstanceId          id;
        alex::ReferenceArray<Foo> foos;
        alex::ReferenceArray<Bar> bars;
    };

    using BazDescriptor = alex::GenerateTypeDescriptor<alex::Member<"id", &Baz::id>,
                                                       alex::Member<"foos", &Baz::foos>,
                                                       alex::Member<"bars", &Baz::bars>>;

    // Search all instances where Baz.foos[] and Baz.bars contain a specific Foo or Bar.
    auto query = alex::referenceSearchOr(bazDescriptor,
                                         alex::references<BazDescriptor, "foos">(),
                                         alex::references<BazDescriptor, "bars">());
    
    // Assuming some valid Foo and Bar, search for all Baz that reference either or both.
    Foo foo{};
    Bar bar{};
    for (alex::InstanceId id : query(foo.id, bar.id))
    {
        Baz obj{.id = id};
        // Run an alex::GetQuery for Baz.
        ...
    }
