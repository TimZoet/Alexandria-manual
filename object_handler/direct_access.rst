Direct Access
=============

There are two ways in which you can create new instances. The first is by using the :code:`create` method. This method
will add a new row to the instance table with all default values. It also takes a pointer parameter. If not null, the
instance is immediately retrieved.

.. code-block:: cpp

    // Create a new instance.
    H->create(nullptr);

    // Create a new instance and immediately retrieve it.
    Foo inst;
    H->create(&inst);

    // Identifier should not be set, otherwise create will throw.
    Foo inst;
    inst.id = 1;
    H->create(&inst); // Will throw.

The second way is with the :code:`insert` method. This method takes a reference to an object that will be added to the
database with all its values. Just as with the :code:`create` method, the object that you pass should not have a valid
identifier yet. After insertion, the identifier will be set.

.. code-block:: cpp

    // Insert a new instance.
    Foo inst;
    inst.prop = ...;
    H->insert(inst);
    // Identifier is now valid.

After modifying an object, you can update the database by passing the object to the :code:`update` method.

.. code-block:: cpp

    // Create instance.
    Foo inst;
    H->create(&inst);

    // Modify.
    inst.prop = ...;

    // Update database.
    H->update(inst);

Instances can be retrieved by their identifier. The :code:`get` method takes an identifier parameter and a reference to
the object to which all values are written. Just as with the :code:`create` method, the identifier should not have been
set yet and is initialized after retrieval.

.. code-block:: cpp

    // Create instance without immediately retrieving it.
    auto id = H->create(nullptr);

    // Retrieve instance.
    Foo inst;
    H->get(id, inst);

Deleting an instance from the database is simple. Just call the :code:`del` method with the instance identifier.

.. code-block:: cpp

    // Delete instance from database.
    H->del(inst.id);
