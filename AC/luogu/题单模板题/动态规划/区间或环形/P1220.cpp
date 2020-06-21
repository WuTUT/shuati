#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=53,INF = 0x7f7f7f7f;
int sumP[maxn][maxn];
int f[maxn][maxn][2];
int n,c;
int d[maxn];
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> c;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&d[i],&sumP[i][i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            sumP[i][j]=sumP[i][j-1]+sumP[j][j];
            f[i][j][0]=f[i][j][1]=INF;
        }
        f[i][i][0]=f[i][i][1]=INF;
    }
    f[c][c][0]=f[c][c][1]=0;
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            f[i][j][0]=min( f[i+1][j][1]+(d[j]-d[i])*(sumP[1][i]+sumP[j+1][n]) , f[i+1][j][0]+(d[i+1]-d[i])*(sumP[1][i]+sumP[j+1][n]) );
            f[i][j][1]=min( f[i][j-1][1]+(d[j]-d[j-1])*(sumP[1][i-1]+sumP[j][n]) , f[i][j-1][0]+(d[j]-d[i])*(sumP[1][i-1]+sumP[j][n]) );
        }
    }
    int ans=min(f[1][n][0],f[1][n][1]);
    cout << ans <<endl;
    return 0;
}
//3205的min版本，其实是一类的，加一维0/1状态就可以方便的表示区间dp的左右入、出队状态