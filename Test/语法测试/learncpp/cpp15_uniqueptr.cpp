#include <iostream>
#include <memory>
using namespace std;
class Resource {
public:
    int x;
    Resource() { cout << "accuired resource" << endl; x = 47; }
    ~Resource() { cout << "destroyed resource" << endl; }
};
int main() {
    unique_ptr<Resource> res1(new Resource{});
    unique_ptr<Resource> res2;
    //res2 = res1; compile error
    res2 = std::move(res1);
    cout << (*res2).x << endl;
    cout << (res1 == nullptr) << endl;

    cout << (static_cast<bool>(res1) ? "not null" : "null") << endl;
    return 0;
}


