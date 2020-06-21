#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n,m;
const int maxn = 1e4+5, maxm =1e5+5;
struct Edge{
    int x,y;
}edges[maxm];
vector<int> v[maxn];
int a[maxn];
int sum_scc[maxn];
int stk[maxn],low[maxn],dfn[maxn],scc[maxn];
int sccnum,top,ind;
void tarjan(int root){
    if(dfn[root]) return;
    dfn[root]=low[root]=++ind;
    stk[++top]=root;
    for(int i=0;i<v[root].size();i++){
        int to = v[root][i];
        if(!dfn[to]){
            tarjan(to);
            low[root]=min(low[root],low[to]);
        }
        else if(!scc[to]){
            low[root]=min(low[root],dfn[to]);
        }
    }
    if(dfn[root]==low[root]){
        sccnum++;
        while(1){
            int x= stk[top--];
            scc[x]=sccnum;
            sum_scc[sccnum]+=a[x];
            if(x==root) break;
        }
    }
}
int in[maxn];
int dp[maxn];
vector<int> nv[maxn];
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int x,y;
    for(int i=1;i<=m;i++){
        cin >> x >> y;
        v[x].push_back(y);
        edges[i].x=x;
        edges[i].y=y;
    }
    for(int i=1;i<=n;i++){
        tarjan(i);
    }
    int from,to;
    for(int i=1;i<=m;i++){
        from = edges[i].x;
        to = edges[i].y;
        if(scc[from]!=scc[to]){
            in[scc[to]]++;
            
            nv[scc[from]].push_back(scc[to]);
        }
    }
    queue<int> q;
    for(int i=1;i<=sccnum;i++){
        if(in[i]==0){
            dp[i]=sum_scc[i];
            q.push(i);
        }
        
    }
    while(!q.empty()){
        int i= q.front();q.pop();
        for(int j=0;j<nv[i].size();j++){
            int ne=nv[i][j];
            dp[ne]=max(dp[ne],dp[i]+sum_scc[ne]);
            in[ne]--;
            if(!in[ne]){
                q.push(ne);
            }
        }
    }
    int ans =0;
    for(int i=1;i<=sccnum;i++){
        if(dp[i]>ans){
            ans=dp[i];
        }
    }
    cout << ans;
    return 0;
}