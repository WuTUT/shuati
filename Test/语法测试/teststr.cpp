#include <string.h>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    //返回值为size_t类型的和负数比较大小存在着隐患

    size_t a = strlen("hell");
    string s("hello");

    if (s.length() > -1) //当有符号整型和无符号整型进行运算时，有符号整型会先自动转化成无符号
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    return 0;
}