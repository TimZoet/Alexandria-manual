Primitive
=========

Primitive properties can be used to store integer and floating point values. They can be added to a type using the 
:code:`createPrimitiveProperty` method.

.. code-block:: cpp

    auto& type = nameSpace.createType("mytype");
    auto& flt  = type.createPrimitiveProperty("prop0", alex::DataType::Float);
    auto& i64  = type.createPrimitiveProperty("prop1", alex::DataType::Int64);

Table Generation
----------------

Primitive values are stored in the instance table as a single column value.

.. figure:: /_static/images/tables/primitive.svg

    Instance table. A single column is added per primitive property.

Class Definition
----------------

Primitive types do not require any extra care when defining classes. All floating point and integral values can be used
directly.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId id;
        float            x;
        int64_t          y;
    };
