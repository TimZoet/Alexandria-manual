Primitive Blob
==============

To handle blob arrays of primitive values, there is the :code:`alex::PrimitiveBlob` class. Its functionality is
identical to the :code:`alex::PrimitiveArray` class.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId           id;
        alex::PrimitiveBlob<float> x;
    };

.. code-block:: cpp

    Foo obj;
    obj.x.get().push_back(3.0f);
    obj.x.get().push_back(6.0f);
