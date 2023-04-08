Instance Table
==============

The instance table can be retrieved through the :code:`getInstanceTable` method of the :code:`alex::TableSets` class.
From the table, you can then directly retrieve columns by index. Another, probably better, way of doing things is by
using the :code:`getInstanceColumn` method. This takes a property name which is automatically resolved to the right
column index.

.. code-block:: cpp

    struct Foo
    {
        int32_t a = 0;
        int32_t b = 0;
    };

    struct Bar
    {
        alex::InstanceId id;
        float            x = 0;
        Foo              foo;
    };

    using FooMemberList = alex::MemberList<alex::Member<"a", &Foo::a>,
                                           alex::Member<"b", &Foo::b>>;
    using BarDescriptor = alex::GenerateTypeDescriptor<alex::Member<"id", &Bar::id>,
                                                       alex::Member<"x", &Bar::x>,
                                                       alex::NestedMember<"foo", FooMemberList, &Bar::foo>>;
    
    auto  barDescriptor    = BarDescriptor(...);
    auto  barTables        = alex::TableSets(barDescriptor);
    auto& instanceTable    = barTables.getInstanceTable();
    auto  idColumn         = instanceTable.col<1>();
    auto  alsoIdColumn     = barTables.getInstanceColumn<"id">();
    auto  xColumn          = instanceTable.col<2>();
    auto  alsoXColumn      = barTables.getInstanceColumn<"x">();
    auto  fooAColumn       = instanceTable.col<3>();
    auto  alsoFooAColumn   = barTables.getInstanceColumn<"foo.a">();
    auto  fooBColumn       = instanceTable.col<4>();
    auto  alsoFooBColumn   = barTables.getInstanceColumn<"foo.b">();
