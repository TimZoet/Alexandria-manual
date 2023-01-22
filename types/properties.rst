Properties
==========

.. toctree::
    :maxdepth: 3
    :titlesonly:
    :hidden:

    properties/instance_id
    properties/primitive
    properties/primitive_array
    properties/primitive_blob
    properties/string
    properties/string_array
    properties/blob
    properties/blob_array
    properties/reference
    properties/reference_array
    properties/nested

Types are made up of properties. There are a number of basic property types such as integers, floats and strings that
can be defined. Additonally, raw binary data can be stored in the form of blob properties to allow for compact storage
and fast retrieval. Also important are reference properties, allowing instances of one type to reference instances of
another. All properties can be defined as being an array.

When committing a type, at least one table is generated to hold the data that you'll be inserting. This is the instance
table. All instance tables have an integer column with the SQLite rowid, as well as a fixed length text column that will
store the UUID of each instance. All properties that specify a single value result in an additional column being added.
For array properties, separate array tables are generated that link to the instance table.

Each property needs to be represented in the C++ class definition. More complex properties require special wrapper
classes that take care of reading from and writing to the underlying SQLite database.
