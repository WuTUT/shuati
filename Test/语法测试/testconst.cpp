#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

//const 修饰的是this指针,只能修饰成员函数
class A
{
    int a, b;
    int *p;
    string s;
    mutable int x;
    void f1(int a, int b)
    {
        this->a = a, this->b = b;
        return;
    }
    void f1(int a, int b) const //重载
    {
        //this->a = a, this->b = b;//error , this指针是const
        *p = a; //ok , this->p不能修改，但指针指向的内容可以修改，这种写法是语法正确但不恰当的
        //为什么用 const修饰：一个const class A对象必须调用 f1

        return;
    }
    bool operator<(const A &rhs) //const
    {
        return a < rhs.a;
    }
    char &operator[](std::size_t i)
    {
        return s[i];
    }
    void errorcheck()
    {
        //do some check for A
    }
    const char &operator[](int i) const //必须返回引用才能实现s[i]='t',但又要实现能调用const 对象
    //返回的不是const时报错drop qualifiers
    {
        x++; //mutable 永远可以被修改
        // errorcheck();//error const成员函数不能调用非const成员函数
        return s[i]; //error 返回的应该为const类型
    }
    char &operator[](int i)
    {
        return const_cast<char &>(
            static_cast<const A &>(*this)[i]);
    }
};

int main()
{
    vector<int> a{1, 2, 3, 4, 5};
    cout << *(a.begin()) << endl;
    *(a.begin()) = *(a.begin()) + 1;
    //迭代器const 与 迭代器指向对象是const
    // auto it = s.begin();
    // auto b = ++a.cbegin(); //ok cbegin() is not a const "pointer"
    //*(a.cbegin()) = 1; // wrong , a.cbegin() point to a const value
    // cout << *(b) << endl;
}