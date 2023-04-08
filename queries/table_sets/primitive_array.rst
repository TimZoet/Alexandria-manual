Primitive Array Tables
======================

The tables for primitive array properties can be retrieved through the :code:`getPrimitiveArrayTable` method of the
:code:`alex::TableSets` class. It takes either an index or a name. For the specification of primitive array tables, see
:doc:`/types/properties/primitive_array`.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId               id;
        alex::PrimitiveArray<uint64_t> uints;
        alex::StringArray              strings;
    };

    using FooDescriptor = alex::GenerateTypeDescriptor<alex::Member<"id", &Foo::id>,
                                                       alex::Member<"uints", &Foo::uints>,
                                                       alex::Member<"strings", &Foo::strings>>;

    auto  fooDescriptor    = FooDescriptor(...);
    auto  fooTables        = alex::TableSets(fooDescriptor);
    auto& uintsTable       = fooTables.getPrimitiveArrayTable<0>();
    auto& alsoUintsTable   = fooTables.getPrimitiveArrayTable<"uints">();
    auto& stringsTable     = fooTables.getPrimitiveArrayTable<1>();
    auto& alsoStringsTable = fooTables.getPrimitiveArrayTable<"strings">();
