#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
const int maxn = 10005;
int t[maxn],v[maxn];
typedef long long ll;
const int maxf=1e7+5;
ll f[maxf];
using namespace std;
int main(){
    freopen("data.in","r",stdin);
    int T,m;
    scanf("%d%d",&T,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d",&t[i]);
        scanf("%d",&v[i]);
    }
    
    for(int i=1;i<=m;i++){
        for(int j=t[i];j<=T;j++){
            f[j]=max(f[j],f[j-t[i]]+v[i]);
           
        }
         
    }
    printf("%lld",f[T]);
    return 0;
}

//完全背包 修改的只有j的遍历顺序 https://www.luogu.com.cn/problem/P1616
//这样刷新f确实没有问题