Blob
====

Blob properties can be used to store arbitrary binary data. No explicit type information is maintained. This is entirely
the responsibility of the user.

A blob property can be added to a type using the :code:`createBlobProperty` method.

.. code-block:: cpp

    auto& type = nameSpace.createType("mytype");
    auto& prop = type.createBlobProperty("myprop");

Table Generation
----------------

Blob properties are stored in the instance table as a single column value.

.. figure:: /_static/images/tables/blob.svg

    Instance table. A single column is added per blob property.

Class Definition
----------------

To handle blobs, there is the :code:`alex::Blob` class. Currently, it has two specializations: one for single objects
and one for a :code:`std::vector` of objects. The former just holds the specified type, while the latter keeps a
:code:`std::vector`.

.. code-block:: cpp

    struct Bar { int32_t x; };

    struct Foo
    {
        alex::InstanceId             id;
        alex::Blob<Bar>              objectBlob;
        alex::Blob<std::vector<Bar>> vectorBlob;
    };

.. note:: 

    TODO: Specializing the :code:`alex::Blob` class or implementing a custom class.
