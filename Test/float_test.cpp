#include <iostream>
#include <cstdio>
using namespace std;
int main(){
   
    int x = 9000;
    const float y = (float)0.0069999999;
    
    x = int(x*y);
    cout << x<<endl;
    //printf("%d",x);
    return 0;
}