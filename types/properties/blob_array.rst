Blob Array
==========

Blob array properties can be used to store lists of arbitrary binary data. No explicit type information is maintained.
This is entirely the responsibility of the user.

A blob array property can be added to a type using the :code:`createBlobArrayProperty` method.

.. code-block:: cpp

    auto& type = nameSpace.createType("mytype");
    auto& prop = type.createBlobArrayProperty("myprop");

Table Generation
----------------

For each blob array property, a separate table is generated. Each element in an instance's blob arrays is inserted as a
separate row containing a reference to the instance table and a value.

.. figure:: /_static/images/tables/blob_array.svg

    Instance and blob array table. Rows in the blob array table reference a row from the instance table.

Class Definition
----------------

To handle arrays of blobs, there is the :code:`alex::BlobArray` class. Currently, it has two specializations: one for
single objects and one for a :code:`std::vector` of objects. The former holds a :code:`std::vector` of the specified
type, while the latter keeps a :code:`std::vector<std::vector<T>>`.

.. code-block:: cpp

    struct Bar { int32_t x; };

    struct Foo
    {
        alex::InstanceId                  id;
        alex::BlobArray<Bar>              objectBlob;
        alex::BlobArray<std::vector<Bar>> vectorBlob;
    };

.. note:: 

    TODO: Specializing the :code:`alex::BlobArray` class or implementing a custom class.
