Primitive
=========

As stated, primitive types do not require any extra care. All floating point and integral values can be used directly.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId id;
        int32_t          x;
        float            y;
    };

.. code-block:: cpp

    Foo obj;
    obj.x = 32;
    obj.y = 4.5f;
