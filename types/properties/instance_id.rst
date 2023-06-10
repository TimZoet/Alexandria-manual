Instance Identifier
===================

All types have an implicit identifier property. This property is added automatically.

.. code-block:: cpp

    alex::TypeLayout layout;
    // Identifier is added implicitly.

When defining a class, you must always add an :code:`InstanceId` member.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId id;
        ...
    };

The identifier is not initialized until you have inserted an object (see :doc:`/queries/basic/insert_query`).
