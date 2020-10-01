#include <iostream>
using namespace std;
class movedemo {
public:
    movedemo() :num(new int(0)) {
        cout << "construct!" << endl;
    }
    //拷贝构造函数
    movedemo(const movedemo& d) :num(new int(*d.num)) {
        cout << "copy construct!" << endl;
    }
    //移动构造函数
    movedemo(movedemo&& d) :num(d.num) {
        d.num = NULL;
        cout << "move construct!" << endl;
    }
public:
    int* num;
};
int main() {
    movedemo demo;
    cout << "demo2:\n";
    movedemo demo2 = demo;
    //cout << *demo2.num << endl;   //可以执行
    cout << *demo.num << endl;
    cout << "demo3:\n";
    movedemo demo3 = std::move(demo);
    //此时 demo.num = NULL，因此下面代码会报运行时错误
    //cout << *demo.num << endl;

    return 0;
}