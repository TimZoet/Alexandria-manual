Object Handler
==============

.. toctree::
    :maxdepth: 3
    :titlesonly:
    :hidden:

    object_handler/construction
    object_handler/direct_access
    object_handler/managed_access

The :code:`alex::ObjectHandler` class is the interface to instances of a specific type. This class handles everything
related to creating, retrieving, updating and deleting objects. It can be constructed through a method of the
:code:`alex::Library` class.

The :code:`alex::ObjectHandler` provides two forms of access to the underlying database: direct and managed. When using
direct access, you are responsible for allocating objects. Whether you do that on the stack or the heap is up to you.
When using managed access, objects are allocated on the heap by the :code:`alex::ObjectHandler`. Additionally, they can
be cached in memory (automatically or manually) to reduce disk access.
