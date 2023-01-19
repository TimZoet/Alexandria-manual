Delete Query
============

The :code:`alex::DeleteQuery` class can be used to delete existing instances of a specific type. It is constructed using
an :code:`alex::TypeDescriptor`.

.. code-block:: cpp

    auto deleter = alex::DeleteQuery(fooDescriptor);

To delete an instance of, in this case, :code:`Foo`, just call the query with a :code:`Foo` object that has a valid id.
After deleting, the instance will no longer be in the database.

.. code-block:: cpp

    // Variable to cache id for later retrieval.
    alex::InstanceId id;

    // Assuming we previously inserted an instance and stored the id...
    {
        Foo obj{.a = 10, .b = 20.0f};
        inserter(obj);
        id = obj.id;
    }

    // ...we can delete the object again.
    {
        deleter(id);
    }

    // You can also directly pass an object instead of just the id.
    {
        Foo obj{.a = 10, .b = 20.0f};
        inserter(obj);
        deleter(obj);
    }

.. note::

    Deleting a non-existent object does not (yet) throw or return an error code.
