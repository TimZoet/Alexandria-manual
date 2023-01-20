Reference
=========

Reference properties can be used to store references to instances of some other type. They can be added to a type using
the :code:`createReferenceProperty`.

.. code-block:: cpp

    auto& foo = nameSpace.createType("foo");
    auto& bar = nameSpace.createType("bar");
    auto& ref = bar.createReferenceProperty("foo", foo);

Table Generation
----------------

Reference values are stored in the instance table as a single column value. This value is a reference to the instance
table of the referenced type.

.. figure:: /_static/images/tables/reference.svg

    Instance tables. A single column is added per reference property.

Class Definition
----------------

To handle references, there is the :code:`alex::Reference` class. This objects holds an :code:`alex::InstanceId` to
which the identifier of the specified type can be assigned.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId id;
    };

    struct Bar
    {
        alex::InstanceId     id;
        alex::Reference<Foo> foo;
    };

.. note:: 

    TODO: Implementing a custom class.
