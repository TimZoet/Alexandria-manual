Blob Array
==========

To handle arrays of blobs, there is the :code:`alex::BlobArray` class. Currently, it has two specializations: one for
single objects and one for :code:`std::vector` s of objects.

.. code-block:: cpp

    struct Bar { int32_t x; };

    struct Foo
    {
        alex::InstanceId                  id;
        alex::BlobArray<Bar>              objectBlob;
        alex::BlobArray<std::vector<Bar>> vectorBlob;
    };

Both specializations have a :code:`get` method to retrieve the vector or vector of vectors.

.. code-block:: cpp

    Foo obj;

    obj.objectBlob.get().push_back(Bar(1));
    obj.objectBlob.get().push_back(Bar(2));

    std::vector<Bar> vec0 = { Bar(3), Bar(4), Bar(5) };
    std::vector<Bar> vec1 = { Bar(6), Bar(7), Bar(8) };
    obj.vectorBlob.get().emplace_back(std::move(vec0));
    obj.vectorBlob.get().emplace_back(std::move(vec1));
