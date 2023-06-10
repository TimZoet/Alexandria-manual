Nested Type
===========

To allow reuse of existing types and ease the definition of more complex types, types themselves can be added as
properties. This can even be done recursively. Adding a nested type property is the equivalent of adding all its
properties. In terms of table generation or class definitions, there are no differences.

.. code-block:: cpp

    // Create non-instantiable type.
    alex::TypeLayout float3Layout;
    float3Layout.createPrimitiveProperty("x", alex::DataType::Float);
    float3Layout.createPrimitiveProperty("y", alex::DataType::Float);
    float3Layout.createPrimitiveProperty("z", alex::DataType::Float);
    auto& float3  = float3Layout.commit(nameSpace, "float3", alex::TypeLayout::Instantiable::False);

    // Create type with multiple float3.
    alex::TypeLayout transformLayout;
    transformLayout.createNestedTypeProperty("translation", float3);
    transformLayout.createNestedTypeProperty("rotation", float3);
    auto& transform = transformLayout.commit(nameSpace, "transform");

.. figure:: /_static/images/tables/nested_type.svg

    Instance table.
