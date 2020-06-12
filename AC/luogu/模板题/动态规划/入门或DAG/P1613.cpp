#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 53;
const int INF=0x7f7f7f7f;
int a[maxn][maxn];
int g[maxn][maxn][65];
int main(){
    freopen("data.in","r",stdin);
    int n,m;
    cin >> n>> m;
    int u,v;
    memset(a,0x7f,sizeof a);
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        a[u][v]=1;
        g[u][v][0]=1;
    }
    for(int k=1;k<=64;k++){
        for(int l=1;l<=n;l++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(g[i][l][k-1] && g[l][j][k-1]){
                        a[i][j]=1;
                        g[i][j][k]=1;
                    } 
                }
            }
        }
    }
    
    for(int l=1;l<=n;l++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][l]<INF && a[l][j]<INF)
                    a[i][j]=min(a[i][j],a[i][l]+a[l][j]);
            }
        }
    }
    cout << a[1][n]<<endl;
    return 0;
}
//图上DP基本就是改造floyd
