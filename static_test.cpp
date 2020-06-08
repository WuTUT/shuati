#include <iostream>
#include <cstdio>
using namespace std;
//class A; 前向声明，只能定义指针、引用、和函数形参的指针、引用 不可以定义静态成员变量

class A{
public:
    static int num;
    A(int& reference_num):reference_num(reference_num) //忘加这个&的后果，哪个0覆盖了这个栈的变量呢 
    {
       // num = 2 ; static num 
      //  pnum = 4; // private static data member initializes at here
    }
    int getpnum(){
       return pnum; 
    }
    int get_reference_num(){
        return reference_num;
    }
    int get_normal_num(){
        return normal_num;
    }
private:
    static int pnum;
    //static int static_not_const_num = 1;//error a member with an in-class initializer must be const
    const int const_num = 1; //(g++ warning) non-static data member initializers only available with -std=c++11 应该在参数初始化列表里初始化
    static const int static_const_num = 1; 
    //int & reference_num = 1; //error initial value of reference to non-const must be an lvalue
    int& reference_num;
    int normal_num = 1; //(g++ warning) non-static data member initializers only available with -std=c++11
};
int A::num = 77;
int A::pnum; // 初始化为0 ,private故不能赋值
//const int A::static_const_num = 50;//error: duplicate initialization of ‘A::static_const_num’
//const 的优先度比static高
int main(){
    //cout << A::num <<endl;
    //A a(1);
    //cout << a.num <<endl;
    //cout << a.get_normal_num() <<endl;
    //cout << a.getpnum() <<endl;
    
    int ref = 3;
    A b = A(ref);
    cout << b.get_reference_num() <<endl;
    cout << b.get_reference_num() <<endl;
    return 0;
}

//成员函数在代码段，与是否inline无关，与定义在类内部还是外部无关
const int r1 = 1;  //rodata段  和text段是在合一起的 叫 Text Segment 代码段
int r2 = 10 ;// data段
static int r3 = 10;//data 段  data段和bss段合起来在Data Segment 数据段
int r4;static int r5; //bss段 bss段填0


//C++类（不是对象）成员变量和成员函数的内存位置、静态变量和全局变量的内存位置以及初始化
//特殊类成员变量初始化位置