// Create instance without immediately retrieving it.
auto id = H->create(nullptr);

// Retrieve instance.
Foo inst;
H->get(id, inst);