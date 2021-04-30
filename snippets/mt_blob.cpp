struct Bar { int32_t x; };

struct Foo
{
    alex::InstanceId             id;
    alex::Blob<Bar>              objectBlob;
    alex::Blob<std::vector<Bar>> vectorBlob;
};