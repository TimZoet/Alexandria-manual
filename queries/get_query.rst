Get Query
============

The :code:`alex::GetQuery` class can be used to retrieve instances of a specific type. It is constructed using an
:code:`alex::TypeDescriptor`.

.. code-block:: cpp

    auto getter = alex::GetQuery(fooDescriptor);

To retrieve an instance of, in this case, :code:`Foo`, just call the query with a :code:`Foo` object that has a valid
id. After retrieval, all members will be assigned the values as they were previously stored.

.. code-block:: cpp

    // Variable to cache id for later retrieval.
    alex::InstanceId id;

    // Assuming we previously inserted an instance and stored the id...
    {
        Foo obj{.a = 10, .b = 20.0f};
        inserter(obj);
        id = obj.id;
    }

    // ...we can retrieve the object again.
    {
        Foo obj{.id = id};
        getter(obj);
    }

Trying to retrieve an object that does not exist will throw an exception.

.. code-block:: cpp

    // Non-existent id, will throw.
    Foo obj;
    obj.id.regenerate();
    getter(obj);
