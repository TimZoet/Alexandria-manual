Primitive Search
================

There are a number of freestanding functions to create queries that search for instances with primitive values
satisfying a basic condition. The usual comparison operators are provided through matching functions which take a type
descriptor and property name.

+------+----------------------------+-----------------------------------------------------------------------------+
| op   | function                   | note                                                                        |
+======+============================+=============================================================================+
| ==   | :code:`alex::equal`        | Can be used with :code:`std::string` and :code:`alex::Reference` properties |
+------+----------------------------+-----------------------------------------------------------------------------+
| !=   | :code:`alex::notEqual`     |                                                                             |
+------+----------------------------+-----------------------------------------------------------------------------+
| <    | :code:`alex::less`         |                                                                             |
+------+----------------------------+-----------------------------------------------------------------------------+
| >    | :code:`alex::greater`      |                                                                             |
+------+----------------------------+-----------------------------------------------------------------------------+
| <=   | :code:`alex::lessEqual`    |                                                                             |
+------+----------------------------+-----------------------------------------------------------------------------+
| >=   | :code:`alex::greaterEqual` |                                                                             |
+------+----------------------------+-----------------------------------------------------------------------------+
| null | :code:`alex::none`         | Can only be used with :code:`alex::Reference` properties                    |
+------+----------------------------+-----------------------------------------------------------------------------+

Single Operator
---------------

The :code:`alex::primitiveSearch` function is the simplest primitive search function. It takes a type descriptor plus a
single operator and returns an :code:`alex::SearchQuery`.

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

Multiple Operators
------------------

There are also the :code:`alex::primitiveSearchAnd` and :code:`alex::primitiveSearchOr` functions, which chain together
multiple operators using the :code:`&&` and :code:`||` logical operators.

.. code-block:: cpp

    // Search all instances with Foo.b < x || Foo.c > y.
    auto query = alex::primitiveSearchOr(fooDescriptor,
                                         alex::less<FooDescriptor, "b">(),
                                         alex::greater<FooDescriptor, "c">());
    
    // Run for x = 100 and y = 200.
    for (auto id : query(100, 200)) {...}

None Operator
-------------

A note on the usage of the :code:`alex::none` operator. It still requires passing in an extra value to the
:code:`alex::SearchQuery` class, even though it technically isn't needed. The value must be :code:`nullptr`.

.. code-block:: cpp

    struct Bar
    {
        alex::InstanceId     id;
        alex::Reference<Foo> foo;
        std::string          name;
    };

    using BarDescriptor = alex::GenerateTypeDescriptor<alex::Member<"id", &Bar::id>,
                                                       alex::Member<"foo", &Bar::foo>,
                                                       alex::Member<"name", &Bar::name>>;
    
    auto query = alex::primitiveSearchAnd(barDescriptor,
                                          alex::none<BarDescriptor, "foo">(),
                                          alex::equal<BarDescriptor, "name">());

    // Note the first, somewhat redundant, parameter.
    for (auto id : query(nullptr, "someName"))
    {
        ...
    }
