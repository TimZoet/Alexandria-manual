Types and Layouts
=================

Defining types is very simple. Create an :code:`alex::TypeLayout` and add various properties to it. Commit it to a
namespace. Start using it in queries. And that's it.

Let us assume a newly created library in which we define two namespaces :code:`main` and :code:`utils`.

.. code-block:: cpp

    auto    lib = alex::Library::create("example.db");
    auto&  main = lib->createNamespace("main");
    auto& utils = lib->createNamespace("utils");

We can then specify a simple layout with just a single primitive property.

.. code-block:: cpp

    alex::TypeLayout layout;
    layout.createPrimitiveProperty("x", alex::DataType::Int32);

This layout can be committed to a namespace under a unique name. This will result in the creation of a new type.

.. code-block:: cpp

    auto [commit, foo] = layout.commit(main, "foo");
    // commit should be equal to alex::TypeLayout::Commit::Created
    // and foo a pointer to a newly created type in main.

If we commit the same layout again to the very same namespace and with an identical name, this will return the existing
type. This is very convenient if you do not know if the library was just created or already contains your types. These
two very different situations can be handled by the same code, requiring no special handling.

.. code-block:: cpp

    auto [commit2, samefoo] = layout.commit(main, "foo");
    // commit2 should be equal to alex::TypeLayout::Commit::Existing
    // and samefoo a pointer to the already existing foo type.

The layout can be committed again, either to a different namespace or to the same namespace under a different name.

.. code-block:: cpp

    auto [commit3, utilsfoo] = layout.commit(utils, "foo");
    // commit3 should be equal to alex::TypeLayout::Commit::Created
    // and utilsfoo a pointer to a newly created type in utils.

    auto [commit4, bar] = layout.commit(main, "bar");
    // commit3 should be equal to alex::TypeLayout::Commit::Created
    // and bar a pointer to a newly created type.

If the namespace to which the layout is being committed already contains a type with the same name but a different
layout an exception is thrown.

.. code-block:: cpp

    layout.createPrimitiveProperty("y", alex::DataType::Int32);
    auto [uh, oh] = layout.commit(main, "foo"); // Will throw.

Instantiability
---------------

You may have types that you never wish to create instances of. For example, a pair of floats. These floats are most
likely to be used as a :doc:`/types/properties/nested`, not as objects on their own. To that end you can provide an
additional parameter :code:`alex::TypeLayout::Instantiable` when committing a layout. If instancing is disabled,
no tables are generated for the type.

.. code-block:: cpp

    alex::TypeLayout layout;
    layout.createPrimitiveProperty("x", alex::DataType::Float);
    layout.createPrimitiveProperty("y", alex::DataType::Float);
    layout.commit(utils, "float2", alex::TypeLayout::Instantiable::False);
