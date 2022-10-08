Nested
======

To make defining complex types a bit easier, it is possible to create type properties. This is essentially the
equivalent of having one class as a member variable of another in C++. Types can be added to any number of other types.
Adding a type property that would result in a circular dependency is not allowed. You can repeatedly add the same type
(with a different name, of course).

.. code-block:: cpp

    auto& float3  = library->createType("float3");
    float3.createPrimitiveProperty("x", alex::DataType::Float);
    float3.createPrimitiveProperty("y", alex::DataType::Float);
    float3.createPrimitiveProperty("z", alex::DataType::Float);

    auto& type = library->createType("transform");
    type.createTypeProperty("translation", float3);
    type.createTypeProperty("rotation", float3);
    type.createTypeProperty("scale", float3);

Adding a type property effectively calls the property creation methods for the type that you're adding. In the above
example, the :code:`transform` type would end up with 9 float columns in the instance table.
