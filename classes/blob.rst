Blob
====

To handle blobs, there is the :code:`alex::Blob` class. Currently, it has two specializations: one for single objects
and one for :code:`std::vector` s of objects.

.. code-block:: cpp

    struct Bar { int32_t x; };

    struct Foo
    {
        alex::InstanceId             id;
        alex::Blob<Bar>              objectBlob;
        alex::Blob<std::vector<Bar>> vectorBlob;
    };

Both specializations have a :code:`get` method to retrieve the object or vector.

.. code-block:: cpp

    Foo obj;

    obj.objectBlob.get().x = 10;

    obj.vectorBlob.get().push_back(Bar(20));
    obj.vectorBlob.get().push_back(Bar(30));
