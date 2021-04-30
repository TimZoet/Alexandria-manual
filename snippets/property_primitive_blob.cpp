auto& type   = library->createType("myType");
auto& ints   = type.createPrimitiveBlobProperty(
                   "prop", alex::DataType::Int32);