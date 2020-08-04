#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
//引用原则：
//内置类型都可以，但数组唯一方式就是传指针而非引用
//类应传引用
//void fff(int &a[]) //wrong!!!数组不可以传引用
//{
//    cout << a[0];
//}
// void f(int &a)
// {
//     cout << a[1] << endl; //这里就会报错
// }
void fff(vector<int> *v)
{
    //cout << v[0] << endl; //不可以

    cout << (*v)[0] << endl; //不方便
    cout << *(v->end() - 1) << endl;
}
int *a = new int[3];
int aaa[3];
int main()
{
    vector<int> v;
    v.push_back(1);
    // a[1] = 1;
    // int(&b)[3] = aaa; //Yes
    // //int(&b)[3] = a;//No a reference of type "int (&)[3]" (not const-qualified) cannot be initialized with a value of type "int *"
    // int *(&b) = a; //Yes
    fff(&v);
    return 0;
}