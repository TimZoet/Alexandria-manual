Update Query
============

The :code:`alex::UpdateQuery` class can be used to modify existing instances of a specific type. It is constructed using
an :code:`alex::TypeDescriptor`.

.. code-block:: cpp

    auto updater = alex::UpdateQuery(fooDescriptor);

To update an instance of, in this case, :code:`Foo`, just call the query with a :code:`Foo` object that has a valid id.
After updating, the new values will be stored in the database.

.. code-block:: cpp

    // Assuming a previously inserted object...
    Foo obj{.a = 10, .b = 20.0f};
    inserter(obj);

    // ...updating is fairly straightforward.
    obj.a = 300;
    obj.b = -10.0f;
    updater(obj);

.. note::

    Updating a non-existent object does not (yet) throw or return an error code. It will fail silently.
