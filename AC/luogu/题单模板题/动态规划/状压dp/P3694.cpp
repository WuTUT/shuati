#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
const int maxn = 1e5+5,maxm =21,INF=0x7f7f7f7f;
int a[maxn];
int s[maxn][maxm]; 
int num[maxm];
int f[1<<maxm];
int main(){
    freopen("data.in","r",stdin);
    cin >> n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        num[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            s[i][j]=s[i-1][j];
        }
        s[i][a[i]]++;
    }
    f[0]=0;
    for(int i=1;i<(1<<m);i++){
        f[i]=INF;
        int r=0;
        for(int j=1;j<=m;j++){
            if(i&(1<<(j-1))){
                r+=num[j];
            }
        }
        for(int j=1;j<=m;j++){
            if(i&(1<<(j-1)))
                f[i]=min(f[i],f[i^(1<<(j-1))]+num[j]+s[r-num[j]][j]-s[r][j]);
        }
    }
    cout << f[(1<<m)-1];
    return 0;
}

//位运算的优先级括号问题
//