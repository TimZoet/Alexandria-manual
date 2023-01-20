Primitive Array
===============

Primitive array properties can be used to store lists of integer and floating point values. They can be added to a type
using the :code:`createPrimitiveArrayProperty` method.

.. code-block:: cpp

    auto& type = nameSpace.createType("mytype");
    auto& ints = type.createPrimitiveArrayProperty("myprop", alex::DataType::Int32);

Primitive arrays should only be used when storing small amounts of data that must be searchable. In all other scenarios,
primitive blobs are the better alternative.

Table Generation
----------------

For each primitive array property, a separate table is generated. Each element in an instance's primitive arrays is
inserted as a separate row containing a reference to the instance table and a value.

.. figure:: /_static/images/tables/primitive_array.svg

    Instance and primitive array table.

Class Definition
----------------

To handle arrays of primitive values, there is the :code:`alex::PrimitiveArray` class. This object holds a
:code:`std::vector` of the specified primitive type.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId              id;
        alex::PrimitiveArray<int32_t> ints;
    };

.. note:: 

    TODO: Implementing a custom class.
