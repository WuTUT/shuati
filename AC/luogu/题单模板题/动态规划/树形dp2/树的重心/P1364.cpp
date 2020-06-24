#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 105; 
int lc[maxn],rc[maxn];
int n;
int tr[maxn];
int sz[maxn],f[maxn];
int dfs(int root){
    int dis=0;
    sz[root]=tr[root];
    if(lc[root]){
        dis+=dfs(lc[root]);
        sz[root]+=sz[lc[root]];
    }
    if(rc[root]){
        dis+=dfs(rc[root]);
        sz[root]+=sz[rc[root]];
    }
    return dis+sz[root]-tr[root];
}
void dp(int root){
    if(lc[root]){
        f[lc[root]]=f[root]+sz[1]-2*sz[lc[root]];
        dp(lc[root]);
    }
    if(rc[root]){
        f[rc[root]]=f[root]+sz[1]-2*sz[rc[root]];
        dp(rc[root]);
    }
}
int main(){
    freopen("data.in","r",stdin);
    cin >> n;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&tr[i],&lc[i],&rc[i]);
    }
    memset(f,0x7f,sizeof f);
    f[1] = dfs(1);
    dp(1);
    //cout << f[1]<<endl;
    int ans = 0x7f7f7f7f; 
    for(int i=1;i<=n;i++){
        ans = min(ans,f[i]);
    }
    cout << ans <<endl;
    return 0;
}