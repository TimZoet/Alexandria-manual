Reference Array
===============

Reference array properties can be used to store lists of references to instances of some other type. They can be added
to a type using the :code:`createReferenceArrayProperty`.

.. code-block:: cpp

    auto& foo = nameSpace.createType("foo");
    auto& bar = nameSpace.createType("bar");
    auto& ref = bar.createReferenceArrayProperty("foo", foo);

Table Generation
----------------

For each reference array property, a separate table is generated. Each element in an instance's reference arrays is
inserted as a separate row containing a reference to the instance table and a value (which itself is a reference to the
instance table of the referenced type).

.. figure:: /_static/images/tables/reference_array.svg

    Instance tables and reference array table.

Class Definition
----------------

To handle reference arrays, there is the :code:`alex::ReferenceArray` class. This objects holds a
:code:`std::vector<alex::InstanceId>` to which identifiers of the specified type can be added.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId id;
    };

    struct Bar
    {
        alex::InstanceId          id;
        alex::ReferenceArray<Foo> foo;
    };

.. note:: 

    TODO: Implementing a custom class.
