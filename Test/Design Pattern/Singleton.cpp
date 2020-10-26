#include <iostream>
#include <cstdio>
#include <mutex>
using namespace std;
class Singleton {
private:
    Singleton() {};
    ~Singleton() {};
    Singleton(const Singleton&) {};
    Singleton& operator= (const Singleton&) = delete;
    static Singleton* m_instance;
    static std::mutex mtx;
    int value;

public:
    static Singleton* getInstance();
    int getvalue() {
        return value;
    }
};
Singleton* Singleton::m_instance = nullptr;
mutex Singleton::mtx;
//single thread version
// Singleton* Singleton::getInstance() {
//     if (m_instance == nullptr) {
//         m_instance = new Singleton();
//     }
//     return m_instance;
// }

//multi-thread safe but inefficiency version
// Singleton* Singleton::getInstance() {
//     //LOCK
//     mtx.lock();
//     if (Singleton::m_instance == nullptr) {
//         Singleton::m_instance = new Singleton();
//         m_instance->value = 5;
//     }
//     mtx.unlock();
//     return Singleton::m_instance;
// }

//DCL(Double Check Lock) Memory Reorder Bug 
Singleton* Singleton::getInstance() {
    if (Singleton::m_instance == nullptr) {
        //LOCK
        mtx.lock();
        if (Singleton::m_instance == nullptr) {
            Singleton::m_instance = new Singleton();
            m_instance->value = 5;
        }
        mtx.unlock();
    }
    return Singleton::m_instance;
}
int main() {
    int a = 1, b = 2, c = 3;
    (a = b) = c;//that's ok ,so assignment type return  
    //again it is not right in c ,c return a lvalue;
    cout << a << b << c << endl;

    cout << Singleton::getInstance()->getvalue() << endl;
    return 0;
}
//http://www.yolinux.com/TUTORIALS/C++Singleton.html