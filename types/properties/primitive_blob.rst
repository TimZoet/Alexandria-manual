Primitive Blob
==============

Primitive blob properties can be used to efficiently store lists of integer and floating point values as raw binary
data. They can be added to a type using the :code:`createPrimitiveBlobProperty` method.

.. code-block:: cpp

    auto& type   = nameSpace.createType("myType");
    auto& floats = type.createPrimitiveBlobProperty("myprop", alex::DataType::Float);

Primitive blobs are almost always a better alternative to primitive arrays when handling large amounts of data. They are
stored as a single, contiguous blob column as opposed to having a whole row per element in a separate table. The only
downside is that you lose the capability to perform more advanced search queries.

Note that you can achieve the same with a blob property. However, primitive blob properties explicitly record the type
of primitive they hold, whereas that information is not kept for generic blobs.

Table Generation
----------------

Primitive blob values are stored in the instance table as a single column value.

.. figure:: /_static/images/tables/primitive_blob.svg

    Instance table. A single column is added per primitive blob property.

Class Definition
----------------

To handle blobs of primitive values, there is the :code:`alex::PrimitiveBlob` class. This object holds a
:code:`std::vector` of the specified primitive type.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId           id;
        alex::PrimitiveBlob<float> floats;
    };

.. note:: 

    TODO: Implementing a custom class.
