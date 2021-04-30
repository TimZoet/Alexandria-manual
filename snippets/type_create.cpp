// Create 2 types.
auto& type0 = library->createType("type0");
library->createType("type1");
// Retrieve type by name.
auto& type1 = library->getType("type1");