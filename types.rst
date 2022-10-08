Defining Types
==============

.. toctree::
    :maxdepth: 3
    :titlesonly:
    :hidden:

    types/properties

A new type can be created with the library's :code:`createType` method, which returns a reference to the new
:code:`alex::Type` object. The reference is valid as long as the library has not been deallocated. You can also retrieve
it by name with the :code:`getType` method.

.. code-block:: cpp

    // Create 2 types.
    auto& type0 = library->createType("type0");
    library->createType("type1");
    // Retrieve type by name.
    auto& type1 = library->getType("type1");

There are some restrictions on type names. Obviously, you cannot create two types with the same name. Additionally,
there are some forbidden prefixes to prevent collisions with the database's internal and generated tables. These
prefixes are: %TODO: List forbidden prefixes.

To specify the data the type will hold, you can add properties to it using the :code:`create*Property` methods. For a
description of all property types, see :doc:`types/properties`.

.. code-block:: cpp

    // Create some properties for each type.
    type0.createStringProperty("name");
    type0.createPrimitiveProperty("foo", alex::DataType::Float);
    type1.createBlobProperty("foo");
    type1.createPrimitiveArrayProperty("bar", alex::DataType::Int32);

Now, some details on what happens internally in terms of what kind of tables are created. For each type that you create,
one or more tables are generated. At the very least, the main :code:`instance table` is created. This table will contain
a column for each property that can be stored as a single value. When creating a new instance of this type, a new row is
added with all the values. Additional tables are generated for e.g. arrays of values or references to other objects.

To insert a type in the database and generate all tables, you can either call the :code:`commitType` method to add a
specific type or the :code:`commitTypes` to add all not yet committed types. After committing a type, it cannot be
modified. Note that if the library goes out of scope before a type is committed, it is lost. Also, when committing a
single type other types on which it depends will be committed as well.

.. code-block:: cpp

    // Commit just type0.
    library->commitType(type0);
    // Commit uncommitted types (in this case, just type1).
    library->commitTypes();
