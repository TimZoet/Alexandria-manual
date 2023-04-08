Blob Array Tables
=================

The tables for blob array properties can be retrieved through the :code:`getBlobArrayTable` method of the
:code:`alex::TableSets` class. It takes either an index or a name. For the specification of blob array tables, see
:doc:`/types/properties/blob_array`.

.. code-block:: cpp

    struct Baz
    {
        float   x;
        int32_t y;
    };

    struct Foo
    {
        alex::InstanceId                    id;
        alex::BlobArray<Baz>                a;
        alex::BlobArray<std::vector<float>> b;
    };

    using FooDescriptor = alex::GenerateTypeDescriptor<alex::Member<"id", &Foo::id>,
                                                       alex::Member<"a", &Foo::a>,
                                                       alex::Member<"b", &Foo::b>>;

    auto  fooDescriptor    = FooDescriptor(...);
    auto  fooTables        = alex::TableSets(fooDescriptor);
    auto& bazTable         = fooTables.getBlobArrayTable<0>();
    auto& alsoBazTable     = fooTables.getBlobArrayTable<"a">();
    auto& floatsTable      = fooTables.getBlobArrayTable<1>();
    auto& alsofloatsTable  = fooTables.getBlobArrayTable<"b">();
