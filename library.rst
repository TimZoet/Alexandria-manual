Library
=======

.. toctree::
    :maxdepth: 1
    :titlesonly:
    :hidden:

    library/multithreading
    library/versioning

The :code:`alex::Library` class is the interface to an on-disk library file. The code snippet below shows various ways
in which a library file can be created and/or opened. There are several static methods that only require a path to a
file and will return an opened (and possible newly created) library.

.. code-block:: cpp

    std::filesystem::path file = ...;

    // Create a new library.
    auto lib = alex::Library::create(file);

    // Open an existing library.
    auto lib = alex::Library::open(file);

    // Open or create a library.
    auto [lib, created] = alex::Library::openOrCreate(file);
