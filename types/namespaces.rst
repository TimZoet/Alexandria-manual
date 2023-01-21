Namespaces
==========

All types must be explicitly created inside of an :code:`alex::Namespace`. There is no such thing as an implicit global
namespace. Namespaces are created through a library by calling the :code:`createNamespace` method.

.. code-block:: cpp

    auto lib    = alex::Library::create("example.db");
    auto& main  = library->createNamespace("main");
    auto& utils = library->createNamespace("utils");

Namespaces have many benefits:

* Better organization of types and data, perhaps to mimick the structure of your C++ namespaces and types.
* 'Hiding' e.g. utility types from higher level users. (Nothing is ever truly hidden, but you get the idea.)
* Allowing different applications to coexist by having them use their own namespace, preventing name clashes.
