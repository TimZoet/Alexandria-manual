auto& float3  = library->createType("float3");
float3.createPrimitiveProperty("x", alex::DataType::Float);
float3.createPrimitiveProperty("y", alex::DataType::Float);
float3.createPrimitiveProperty("z", alex::DataType::Float);

auto& type = library->createType("transform");
type.createTypeProperty("translation", float3);
type.createTypeProperty("rotation", float3);
type.createTypeProperty("scale", float3);