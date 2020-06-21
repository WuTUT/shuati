#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=1e5+5;
const int maxm=3e5+5,INF=0x7fffffff,mod =1e9+7;
int n,m;
int a[maxn];
vector<int> v[maxn];
struct Edge{
    int x,y;
}edges[maxm];
int w[maxn];
int dfn[maxn];
int low[maxn];
int stack[maxn];
int top;
int ind;
int sccnum;
int scc[maxn];
typedef long long ll;
ll ans;
ll ans2;
int sum_scc[maxn];
int minco_scc[maxn];
void tarjan(int root){
    if(dfn[root]) return;
    dfn[root]=low[root]=++ind;
    stack[++top]=root;
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
    if(dfn[root] == low[root]){
        sccnum++;
        int minw=INF;
        while(1){
            int x= stack[top--];
            scc[x]=sccnum;
            if(minw>w[x]){
                minw=w[x];
                sum_scc[sccnum]=1;
            }else if(minw == w[x]){
                sum_scc[sccnum]++;
            }
            if(x== root) break;
        }
        minco_scc[sccnum]=minw;
    }
}

int main(){
    freopen("data.in","r",stdin);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> w[i];
    }
    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> edges[i].x >> edges[i].y;
        v[edges[i].x].push_back(edges[i].y);
    }

    for(int i=1;i<=n;i++){
        tarjan(i);
    }
    ans2=1;
    for(int i=1;i<=sccnum;i++){
        
        ans+=minco_scc[i];
        ans2= (ans2*sum_scc[i])%mod;
    }
    cout << ans << " " << ans2;
    return 0;
}
