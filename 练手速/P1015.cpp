#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int n;
struct Num{
    int p[105];
    int len;
    Num(){
        len =0;
        memset(p,0,sizeof p);
    }
    Num(std::string& s){
        if(n==16){
            len = s.length();
            for(int i=len;i>=0;i--){
                if(s[i]<='F'&&s[i]>='A'){
                    p[i+1]=s[i]-'A'+10;
                }
                else 
                    p[i+1]=s[i]-'0';
            }
        }
        else {
            len = s.length();
            for(int i=len;i>=0;i--){
                p[i+1]=s[i]-'0';
            }
        }
        
    }
    void print(){
        
        for(int i=len;i>0;i--){
            printf("%d",p[i]);
        }
    }
};
Num operator+(const Num& a,const Num& b){
    Num c;c.len=max(a.len,b.len);int x=0;
    for(int i=1;i<=c.len;i++){
        c.p[i]=a.p[i]+b.p[i]+x;
        x=c.p[i]/n;
        c.p[i]%=n;
    }
    if(x){
        c.p[++c.len]=x;
    }
    return c;
}
void getReverse(const Num& a,Num& c){
    c.len=a.len;
    for(int i=1;i<=c.len;i++){
        c.p[i]=a.p[c.len-i+1];
    }
    int lenth = c.len/2 + 1;
    for(int i=1;i<=lenth;i++){
        if(c.p[i]!=a.p[i]){
            c.len=-1;
            break;
        }
    }
    return;
}
string s;
int main(){
    freopen("data.in","r",stdin);
    cin >> n;
    string s;
    cin >> s;
    Num a(s);
    int step = 0;
    Num b;
    while(1){
        getReverse(a,b);
        if(b.len != -1){
            break;
        }
        a= a+b;
        step++;
        if(step > 30){
            break;
        }
    }
    if(step > 30){
        cout << "Impossible!"<<endl;
    }
    else{
        cout << "STEP="<<step<<endl;
    }
    return 0;
}
//练习下高精度
//
//