// Create some properties for each type.
type0.createStringProperty("name");
type0.createPrimitiveProperty("foo", alex::DataType::Float);
type1.createBlobProperty("foo");
type1.createPrimitiveArrayProperty("bar", alex::DataType::Int32);