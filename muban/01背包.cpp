#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int maxn=105;
int t[maxn],v[maxn];
int f[1005];
int main(){
    freopen("data.in","r",stdin);
    int T,m;
    scanf("%d%d",&T,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&t[i]);
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=m;i++){
        for(int j=T;j>=t[i];j--){
            f[j]=max(f[j],f[j-t[i]]+v[i]);
        }
    }
    printf("%d",f[T]);
    return 0;
}

//re 数组开小了
//0 1 背包 https://www.luogu.com.cn/problem/P1048