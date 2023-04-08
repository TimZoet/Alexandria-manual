Insert Query
============

The :code:`alex::InsertQuery` class can be used to insert new instances of a specific type. It is constructed using an
:code:`alex::TypeDescriptor`.

.. code-block:: cpp

    auto inserter = alex::InsertQuery(fooDescriptor);

To insert an instance of, in this case, :code:`Foo`, just call the query with a :code:`Foo` object. After insertion the
object will have a valid id assigned by which the object could later be retrieved.

.. code-block:: cpp

    Foo obj0{.a = 10, .b = 20.0f};
    Foo obj1{.a = 33, .b = 66.6f};
    inserter(obj0);
    inserter(obj1);
    // obj0.id and obj1.id are now a valid id.

To prevent bugs, you must explicitly reset the id before calling the inserter with the same object.

.. code-block:: cpp

    // We want to insert another object with a slight modification,
    // and don't want to construct a whole new object.
    obj0.a += 22;

    // Inserting an object with a valid id is not allowed. The following will throw:
    inserter(obj0);

    // After resetting the id, it can be inserted again. Obviously, it will receive a new, valid id.
    obj0.id.reset();
    inserter(obj0);
