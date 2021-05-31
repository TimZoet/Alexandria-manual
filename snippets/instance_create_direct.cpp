// Create a new instance.
H->create(nullptr);

// Create a new instance and immediately retrieve it.
Foo inst;
H->create(&inst);

// Identifier should not be set, otherwise create will throw.
Foo inst;
inst.id = 1;
H->create(&inst); // Will throw.