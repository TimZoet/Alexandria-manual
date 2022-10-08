InstanceId
==========

All types have an implicit 64-bit signed integer property that is used as an instance's identifier. In the class
definition, an explicit member variable must be added. This member variable must have the name :code:`id` and be of type
:code:`alex::InstanceId`.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId id;
        ...
    };

Note that you should never initialize or modify this value. Doing so will result in undefined behaviour.
