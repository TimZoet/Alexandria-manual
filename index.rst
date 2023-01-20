Alexandria
==========

.. toctree::
    :maxdepth: 3
    :titlesonly:
    :hidden:

    library
    types
    queries

%TODO Type definitions and data stored in same database file.

The :code:`alex::Library` class is the interface to a :doc:`library` file. It has methods for :doc:`types` and their
:doc:`types/properties`.

For each type definition you can create a matching C++ class. The member variables of this class correspond to the
properties of the type. With the exception of some primitive types, special wrapper classes are needed to correctly read
and write them.

The :doc:`/object_handler` class is the interface to instances of a specific type.  This class handles everything
related to creating, retrieving, updating and deleting objects.

When exactly you define types and create instances of these types will of course depend on your use case. You could
distribute an application with a complete library containing both types and data and never have the application modify
it. Alternatively, you might have a library file with just types because your application generates data at runtime. Or
perhaps the application creates wholly new library files and generates both the types and data at runtime.
