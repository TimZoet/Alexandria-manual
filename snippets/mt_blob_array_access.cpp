Foo obj;

obj.objectBlob.get().push_back(Bar(1));
obj.objectBlob.get().push_back(Bar(2));

std::vector<Bar> vec0 = { Bar(3), Bar(4), Bar(5) };
std::vector<Bar> vec1 = { Bar(6), Bar(7), Bar(8) };
obj.vectorBlob.get().emplace_back(std::move(vec0));
obj.vectorBlob.get().emplace_back(std::move(vec1));