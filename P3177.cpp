#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 2005;
int n,m;
vector<int> g[maxn];
vector<int> w[maxn];
int f[maxn][maxn];
int sz[maxn];
void dfs(int root,int fa){
    sz[root]=1;
    f[root][0]=f[root][1]=0;
    for(int i=0;i<g[root].size();i++){
        
        int to = g[root][i];
        if(to==fa) continue;
        dfs(to,root);
        sz[root]+=sz[to];
        
    }
    for(int i=0;i<g[root].size();i++){
        int to = g[root][i];
        if(to==fa) continue;
        for(int j=min(m,sz[root]);j>=0;j--){
                int tt=min(j,sz[to]);
                for(int k=0;k<=tt;k++){
                    if(f[root][j-k]==-1) continue ;
                    int val=k*(m-k)+ (sz[to]-k)*(n-m-sz[to]+k);
                    val*=w[root][i];
                    f[root][j]=max(f[root][j],f[root][j-k]+f[to][k]+val);
                }
            } 
    }
}
int main(){
    freopen("data.in","r",stdin);
    memset(f,-1,sizeof f);
    cin >> n >> m;
    int fr,to,dis;
    for(int i=0;i<n;i++){
        cin >> fr >> to >>dis;
        
        g[fr].push_back(to);
        w[fr].push_back(dis);
        g[to].push_back(fr);
        w[to].push_back(dis);
    }
    dfs(1,-1); 
    cout << f[1][m]<<endl;
    return 0;
}