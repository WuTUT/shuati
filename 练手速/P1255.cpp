#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Num{
    static const int maxn = 5005; 
    static const int base = 10000;
    int p[maxn];
    int len;
    Num(){
        memset(p,0,sizeof p);
        len = 0;
    }
    void print(){
        printf("%d",p[len]);
        for(int i=len-1;i>0;i--){
            printf("%04d",p[i]);
        }
    }
};
Num operator+(Num &a,Num &b){
    Num c;c.len=max(a.len,b.len);int x=0;
    for(int i=1;i<=c.len;i++){
        c.p[i] = a.p[i]+b.p[i]+x;
        x = c.p[i]/c.base;
        c.p[i]%=c.base;
    }
    if(x){
        c.p[++c.len]=x;
    }
    return c;

} 
Num f[5005]; 
int main(){
    int n;

    cin >> n;
    f[1].p[1]=1;f[2].p[1]=2;
    f[1].len=1;f[2].len=1;
    //f[1].print();
    for(int i=3;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
        
    }
   // cout << f[3].len<<endl;
    f[n].print();
    return 0;
}