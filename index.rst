Alexandria
==========

.. toctree::
    :maxdepth: 3
    :titlesonly:
    :hidden:

    library
    types
    queries

:code:`Alexandria` is a C++ library for data serialization built on top of `SQLite <https://www.sqlite.org>`_. As a
user, you can define types with properties. Type definitions are stored in a database and are used to generate tables.
These tables will hold instances the registered types. Because it is built on top of SQLite, Alexandria can efficiently
handle large amounts of data. In addition, it allows running queries on your data. The main advantages can be summarized
as follows:

* SQLite is a well-established database format that can be used from other programming languages and is understood by
  many existing applications. This eases integration with other code, and makes it possible to inspect your data without
  having to write custom debugging tools.
* Using a SQL database instantly creates opportunities for writing complex and efficient queries on your data. Other
  data formats (or even your own, custom developed format) may not offer this out of the box without a considerable
  amount of reinventing the wheel. Alexandria uses the `cppql <https://github.com/TimZoet/cppql>`_ library to interface
  with SQLite. This library offers type safe, pure C++ access to the underlying database.
* The data specification and data itself are stored in the same file. While a lone database will probably not tell the
  whole story and fully understanding the data requires the accompanying C++ code, there is a decent amount of
  decoupling between data and code.
* Not including the database file itself, there is no reliance on the filesystem, avoiding a common source of headaches.
  Instead, objects are identified with UUIDs.
* Different applications (or more generally, independent systems) can interact with the same database, registering their
  own types, without affecting one another. This is great for e.g. plugin systems.

Managing libraries (in Alexandria lingo a database is called a library) is covered in the :doc:`library` section. How to
define types and match them to C++ classes/structs is explained in the :doc:`types` section. How to handle the
insertion, editing and retrieval of instances of the types you defined can be found in the :doc:`queries` section.
