#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
struct Num{
    static const int base = (int) 1e4;
    static const int maxlen=21050;
    int p[maxlen];
    int len;
    Num(){
        memset(p,0,sizeof p);
        len=0;
    }
    void readstr(const string& s){
        int slen =s.length();int j=1;int i;
        for(i=0;i+3<slen;i+=4){
            p[j++]=(s[i]-'0')+(s[i+1]-'0')*10+(s[i+2]-'0')*100+(s[i+3]-'0')*1000;
        }
        if(i<slen) p[j]=s[i]-'0';
        if(i+1<slen) p[j]+=(s[i+1]-'0')*10;
        if(i+2<slen) p[j]+=(s[i+2]-'0')*100;  
        if(i==slen)
            len = j-1;
        else 
            len = j;
    }
    bool operator <(const struct Num& rhs) const {
        if(len < rhs.len) return true;
        if(len > rhs.len) return false;
        for(int i=len; i>0;i++){
            if(p[i]< rhs.p[i]) return true;
            if(p[i]> rhs.p[i]) return false;
        }
        return 0;
    }
    void print(){
        printf("%d",p[len]);
        for(int i=len-1;i>0;i--){
            printf("%04d",p[i]);
        }
        
    }
}a,b;
Num operator+(const Num& a,const Num& b){
    Num c;c.len=max(a.len,b.len); int x=0;
    for(int i=1;i<=c.len;i++){
        c.p[i]=x+a.p[i]+b.p[i];
        x=c.p[i]/c.base;
        c.p[i]%=c.base;
    }
    if(x>0){
        c.p[++c.len]=x;
    }
    return c;
}
Num operator*(const Num& a,const int& b){
    Num c;c.len =a.len;int x=0;
    for(int i=1;i<=c.len;i++){
        c.p[i]=x+a.p[i]*b;
        x=c.p[i]/c.base;
        c.p[i]%=c.base;
    }
    while(x>0){
       c.p[++c.len]=x%c.base;
       x/=c.base;
    }
    return c;
}
Num operator*(const Num& a,const Num& b){
    Num c;int base=c.base;
    if(a.len == 0 || b.len == 0 )
        return c;
    
    for(int j=b.len;j>0;j--){
        c = c*base;
        c = c + a*b.p[j];
    }
    
    return c;
}
Num max(const Num& a,const Num& b){
    if(a<b) return b;
    return a;
}


int main(){
    freopen("data.in","r",stdin);
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    a.readstr(s);
    cin>>s;
    reverse(s.begin(),s.end());
    b.readstr(s);
   // b.print();
    Num c=a*b;
    
    
    c.print();
    return 0; 
}