Primitive Array
===============

To handle arrays of primitive values, there is the :code:`alex::PrimitiveArray` class.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId            id;
        alex::PrimitiveArray<float> x;
    };

Internally, it stores a :code:`std::vector` which can be retrieved using the :code:`get` method.

.. code-block:: cpp

    Foo obj;
    obj.x.get().push_back(3.0f);
    obj.x.get().push_back(6.0f);
