#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 5e4+5;
vector<int> v[maxn];
int n;
int f[maxn];
int sz[maxn];
int dfs(int root,int fa){
    sz[root]=1;
    int dis=0;
    for(int i=0;i<v[root].size();i++){
        
        int to = v[root][i];
        if(fa==to) continue;
        dis+=dfs(to,root);
        sz[root]+=sz[to];
    }
    return dis+sz[root]-1;
}
void dp(int root,int fa){
    for(int i=0;i<v[root].size();i++){
        int to = v[root][i];
        if(fa==to) continue;
        f[to]=f[root]+n-sz[to]*2;
        dp(to,root);
    }
}
int main(){
    freopen("data.in","r",stdin);
    cin >> n;
    int fr,to;
    
    for(int i=1;i<n;i++){
        cin >> fr >> to;
        v[fr].push_back(to);
        v[to].push_back(fr);
    }
    f[1] = dfs(1,0);
    dp(1,0);
    int ans=0x7f7f7f7f;int ind=5e5+10;
    for(int i=1;i<=n;i++){
        if(ans>f[i]){
            ans = f[i];
            ind = i;
        }
        else if(ans == f[i]){
            ans = f[i];
            ind=min(ind,i);
        }
    }
    cout << ind <<" " <<ans<<endl;
    return 0;
}