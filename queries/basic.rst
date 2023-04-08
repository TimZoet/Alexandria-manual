Basic Queries
=============

.. toctree::
    :maxdepth: 1
    :titlesonly:
    :hidden:

    basic/delete_query
    basic/get_query
    basic/insert_query
    basic/update_query

To insert, get, update and delete objects there are various query classes. For each type and operation, you must
construct a separate query object from an :code:`alex::TypeDescriptor`. Internally, a query object manages one or more
SQLite statements that operate on the type's underlying tables. Because constructing a query is expensive, you should
cache them if they are going to be used more often. Each of these four query types is described on its own page. For
simplicity's sake, they will all assume a simple type :code:`Foo`, defined below.

.. code-block:: cpp

    // A simple type holding just some primitives.
    struct Foo
    {
        alex::InstanceId id;
        int32_t          a = 0;
        float            b = 0;
    };

    // Matching TypeDescriptor.
    using FooDescriptor = alex::GenerateTypeDescriptor<alex::Member<"id", &Foo::id>,
                                                       alex::Member<"a", &Foo::a>,
                                                       alex::Member<"b", &Foo::b>>;

    // Create library and main namespace.
    auto lib = alex::Library::create("example.db");
    auto& nameSpace = lib->createNamespace("main");

    // Define Foo type.
    auto& fooType = nameSpace.createType("foo");
    fooType.createPrimitiveProperty("a", alex::DataType::Int32);
    fooType.createPrimitiveProperty("b", alex::DataType::Float);
    fooType.commit();

    // Setup TypeDescriptor.
    auto fooDescriptor = FooDescriptor(fooType);
