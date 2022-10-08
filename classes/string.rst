String
======

Just like with primitive types, string values can be used directly.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId id;
        std::string      s;
    };

.. code-block:: cpp

    Foo obj;
    obj.s = "abc";
