auto& foo  = library->createType("foo");
auto& bar  = library->createType("bar");
auto& prop0 = bar.createReferenceProperty("foo", foo);
auto& prop1 = bar.createReferenceArrayProperty("foos", foo);