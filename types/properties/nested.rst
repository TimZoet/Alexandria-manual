Nested Type
===========

To allow reuse of existing types and ease the definition of more complex types, types themselves can be added as
properties. This can even be done recursively. Adding a nested type property is the equivalent of adding all its
properties. In terms of table generation or class definitions, there are no differences.

.. code-block:: cpp

    // Create non-instantiable type.
    auto& float3  = nameSpace.createType("float3", false);
    float3.createPrimitiveProperty("x", alex::DataType::Float);
    float3.createPrimitiveProperty("y", alex::DataType::Float);
    float3.createPrimitiveProperty("z", alex::DataType::Float);

    // Create type with multiple float3.
    auto& transform = nameSpace.createType("transform");
    transform.createNestedTypeProperty("translation", float3);
    transform.createNestedTypeProperty("rotation", float3);

    // float3 must be committed before transform.
    float3.commit();
    transform.commit();

.. figure:: /_static/images/tables/nested_type.svg

    Instance table.
