struct Bar { int32_t x; };

struct Foo
{
    alex::InstanceId                  id;
    alex::BlobArray<Bar>              objectBlob;
    alex::BlobArray<std::vector<Bar>> vectorBlob;
};