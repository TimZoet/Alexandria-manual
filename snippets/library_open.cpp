std::filesystem::path file = ...;

// Create a new library.
auto lib = alex::Library::create(file);

// Open an existing library.
auto lib = alex::Library::open(file);

// Open or create a library.
auto [lib, created] = alex::Library::openOrCreate(file);