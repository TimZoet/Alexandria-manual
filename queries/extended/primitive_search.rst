Primitive Search
================

There are a number of freestanding functions to create queries that search for instances with primitive values
satisfying a basic condition. The usual comparison operators are provided through matching functions which take a type
descriptor and property name.

+----+----------------------------+
| op | function                   |
+====+============================+
| == | :code:`alex::equal`        |
+----+----------------------------+
| != | :code:`alex::notEqual`     |
+----+----------------------------+
| <  | :code:`alex::less`         |
+----+----------------------------+
| >  | :code:`alex::greater`      |
+----+----------------------------+
| <= | :code:`alex::lessEqual`    |
+----+----------------------------+
| >= | :code:`alex::greaterEqual` |
+----+----------------------------+

Below follow some examples for the type :code:`Foo`.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId id;
        float            a = 0.0f;
        int32_t          b = 0;
        uint64_t         c = 0;
    };

    using FooDescriptor = alex::GenerateTypeDescriptor<alex::Member<"id", &Foo::id>,
                                                       alex::Member<"a", &Foo::a>,
                                                       alex::Member<"b", &Foo::b>,
                                                       alex::Member<"c", &Foo::c>>;

The :code:`alex::primitiveSearch` function is the simplest primitive search function. It takes a type descriptor plus a
single operator and returns an :code:`alex::SearchQuery`.

.. code-block:: cpp

    // Search all instances with Foo.a == x.
    auto query = alex::primitiveSearch(fooDescriptor,
                                        alex::equal<FooDescriptor, "a">());
    
    // Run for x = 10.
    for (alex::InstanceId id : query(10))
    {
        Foo obj{.id = id};
        // Run an alex::GetQuery for Foo.
        ...
    }

    // Now run for x = 33.
    for (auto id : query(33)) {...}

There are also the :code:`alex::primitiveSearchAnd` and :code:`alex::primitiveSearchOr` functions, which chain together
multiple operators using the :code:`&&` and :code:`||` logical operators.

.. code-block:: cpp

    // Search all instances with Foo.b < x || Foo.c > y.
    auto query = alex::primitiveSearchOr(fooDescriptor,
                                         alex::less<FooDescriptor, "b">(),
                                         alex::greater<FooDescriptor, "c">());
    
    // Run for x = 100 and y = 200.
    for (auto id : query(100, 200)) {...}
