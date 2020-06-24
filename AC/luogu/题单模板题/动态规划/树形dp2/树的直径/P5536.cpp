#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1e5+5;
int n,k;
vector<int> v[maxn];
int dep[maxn],f[maxn],mdep[maxn],ans[maxn];
int maxdep,maxx;
void dfs(int root,int fa){
    if(dep[root]>maxdep){
        maxdep=dep[root];
        maxx=root;    
    }
    for(int i=0;i<v[root].size();i++){
        int to =v[root][i];
        if(to==fa) continue;
        dep[to]=dep[root]+1;
        dfs(to,root);
        
    }
}

void dfs2(int root ,int fa){
    if(dep[root]>maxdep){
        maxdep=dep[root];
        maxx=root;    
    }
    for(int i=0;i<v[root].size();i++){
        int to =v[root][i];
        if(to==fa) continue;
        dep[to]=dep[root]+1;
        f[to]=root;
        dfs2(to,root);
        
    }
}
void dfs3(int root ,int fa){
    mdep[root]=dep[root];
    for(int i=0;i<v[root].size();i++){
        int to =v[root][i];
        if(to==fa) continue;
        dep[to]=dep[root]+1;
        dfs3(to,root);
        mdep[root] = max(mdep[root], mdep[to]);
    }
}
int main(){ 
    freopen("data.in","r",stdin);
    cin >> n >> k;
    int x,y;
    for(int i=1;i<n;i++){
       cin >> x >> y; 
       v[x].push_back(y);
       v[y].push_back(x);
    }
    dfs(1,0);
    memset(dep,0,sizeof dep);
    maxdep=0;
    dfs2(maxx,0);
    int midx = maxx;
    for(int i=1;i<=(dep[maxx]+1)/2;i++){
        midx = f[midx];
    }
    dfs3(midx,0);
    for(int i=1;i<=n;i++){
        ans[i]=mdep[i]-dep[i];
    }
    sort(ans+1,ans+n+1,greater<int>());
    cout << ans[k+1]+1 <<endl;
    return 0;
}
//第一个点一定要包含在直径中，再考虑最小化，则一定是直径链的中点
//接下来以这个点扩展，必须和它相连，故贪心选择

//有点难想的，很经典好吧