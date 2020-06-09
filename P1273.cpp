#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int maxn=3002;
int n,m;
vector<int> c[maxn];
vector<int> e[maxn];
int f[maxn][maxn];
void dfs(int root){
    int csize = c[root].size();
    
    for(int i=0;i<csize;i++){
        dfs(c[root][i]);
        for(int j=m;j>0;j--){
            for(int k=j-1;k>0;k--){
                f[root][j]=max(f[root][j],f[c[root][i]][k]-e[root][i]+f[root][j-k]);
            }
            f[root][j]=max(f[root][j],f[c[root][i]][0]+f[root][j]);
        }
    }
}
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    int k,x,y;
    for(int i=1;i<=n-m;i++){
        cin >> k;
        for(int j=1;j<=k;j++){
            cin >> x >> y; 
            c[i].push_back(x);
            e[i].push_back(y);
        }
    }
    for(int i=n-m+1;i<=n;i++){
        cin >> f[i][1];
    }
    dfs(1);
    for(int i=0;i<=m;i++){
        cout << f[1][i]<<endl;
    }
}