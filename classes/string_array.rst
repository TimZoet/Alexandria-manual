String Array
============

To handle arrays of strings, there is the :code:`alex::StringArray` class. Its functionality is identical to the
:code:`alex::PrimitiveArray` class.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId  id;
        alex::StringArray s;
    };

.. code-block:: cpp

    Foo obj;
    obj.s.get().push_back("abc");
    obj.s.get().push_back("def");
