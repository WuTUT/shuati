#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 305*2;
vector<int> v[maxn],w[maxn];
int m;
int e[maxn],np[maxn];
int f[maxn][maxn];
void dfs(int root){
    cin >> e[root]>>np[root];
    e[root]*=2;
    if(np[root]==0){
        dfs(root*2);
        dfs(root*2+1);
    }else{
        int vi,wi;
        for(int i=1;i<=np[root];i++){
            cin >> vi >>wi;
            v[root].push_back(vi);
            w[root].push_back(wi);
        }
    }
}
int g[maxn];
void dp(int root){
    if(np[root]){
        //cout << np[root]<<" root "<<root<<endl;
        memset(g,0,sizeof g);
        for(int i=0;i<np[root];i++){
            for(int j=m;j>=w[root][i];j--){
                g[j]=max(g[j],g[j-w[root][i]]+v[root][i]);
            }
        }
        //cout << "root " <<root<<" "<<g[2]<<endl;
        for(int i=0;i+e[root]<=m;i++){
            f[root][i+e[root]]=g[i];
        }
        //cout << "root " <<root<<" "<<f[root][22]<<endl;
    }
    else{
        dp(root*2);
        dp(root*2+1);
        for(int i=m;i>=e[root];i--){
            int tt=i-e[root];
            for(int j=0;j<=tt;j++){
                f[root][i]=max(f[root][i],f[root*2+1][i-j-e[root]]+f[root*2][j]);
            }
        }
    }
}
int main(){
    freopen("data.in","r",stdin);
    cin >> m;

    m-=1;
    dfs(1);
    dp(1);
    cout << f[1][m]<<endl;
    return 0;
}