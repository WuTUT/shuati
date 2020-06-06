#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 81;
struct Num{
    static const int base=(int) 1e4;
    int p[505];
    int len;
    Num(){
        len=0;
        memset(p,0,sizeof p);
    }
    void clear(){
        memset(p,0,sizeof p);
        len=0;
    }
    void print(){
        printf("%d",p[len]);
        for(int i=len-1;i>0;i--){
            printf("%04d",p[i]);
        }
    }
    bool operator<(const Num& b)const {
        if(len>b.len) return false;
        if(len<b.len) return true;
        for(int i=len;i>0;i--){
            if(p[i]<b.p[i]) return true;
            if(p[i]>b.p[i]) return false;
        }
        return 0;
    }
        
}f[maxn][maxn],base2[maxn],ans[maxn];
Num operator+(const Num& a,const Num& b){
    Num c;c.len=max(a.len,b.len);int x=0;
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
    Num c;c.len=a.len;int x=0;
    for(int i=1;i<=c.len;i++){
        c.p[i]=a.p[i]*b+x;
        x=c.p[i]/c.base;
        c.p[i]%=c.base;
    }
    while(x>0){
        c.p[++c.len]=x%c.base;
        x/=c.base;
    }
    return c;
}
Num max(const Num&a,const Num&b){
    if(a<b) return b;
    else return a;
}

int n,m;
void BaseTwoInit(){
    base2[0].p[1]=1;
    base2[0].len=1;
    for(int i=1;i<=m+2;i++){
        base2[i]=base2[i-1]*2;
    }
}
int x[maxn][maxn];
int main(){
    freopen("data.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&x[i][j]);
        }
    }
    BaseTwoInit();
    Num sumans;
    for(int row=1;row<=n;row++){
        for(int i=1;i<=m;i++){
            f[i][i]=base2[m]*x[row][i];
        }
        for(int len=2;len<=m;len++){
            for(int l=1;l+len-1<=m;l++){
                int r= l+len-1;
             //   cout << l <<" "<<r<<endl;
                f[l][r]=max(f[l+1][r]+base2[m-len+1]*x[row][l],f[l][r-1]+base2[m-len+1]*x[row][r]);
              //  f[l][r].print();
            }
        }
        sumans = sumans + f[1][m];
    }
    
    sumans.print();

   // cout <<sumans<<endl;
    return 0;
}

//最简单版本的左右出队型，区间DP
//高精度