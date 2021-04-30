auto& type = library->createType("myType");
auto& flt  = type.createPrimitiveProperty(
                 "prop0", alex::DataType::Float);
auto& i32  = type.createPrimitiveProperty(
                 "prop1", alex::DataType::Int32);
auto& i64  = type.createPrimitiveProperty(
                 "prop2", alex::DataType::Int64);