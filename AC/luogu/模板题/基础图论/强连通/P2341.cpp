#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e4+5,maxm= 5e4+5;
int low[maxn];
int dfn[maxn];
int scc[maxn];
int num_scc[maxn];
int sccnum;
int top;
int stack[maxn];
int ind;
struct Edge{
    int x,y;
}edges[maxm];
vector<int> v[maxn];

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
        while(1){
            int x = stack[top--];
            scc[x] = sccnum; 
            num_scc[sccnum]++;
            if(x==root) break;
        }
    }
}
int outdegree[maxn];
int main(){
    freopen("data.in","r",stdin);
    int n,m;
    cin >> n >> m;
    int a,b;
    for(int i=1;i<=m;i++){
       cin >> edges[i].x >> edges[i].y;
       v[edges[i].x].push_back(edges[i].y);
    }
    for(int i=1;i<=n;i++){
        tarjan(i);
    }
    for(int i=1;i<=m;i++){
        int from = edges[i].x;
        int to = edges[i].y;
        if(scc[from] != scc[to]){
            outdegree[scc[from]]++;
        }
    }
    int ans=0;
    int cnt=0;
    for(int i=1;i<=sccnum;i++){
        if(outdegree[i] == 0){
            ans=num_scc[i];
            cnt++;
            if(cnt > 1) break;
        }
    }
    if(cnt > 1)
        cout << 0;
    else
        cout << ans;
    return 0;
}
//注意应该是出度为0而不是入度为sccnum-1。因为不需要直接喜欢，可以间接相连，同时缩点之后如果有多于两个的点出度为0说明此图没有这种牛，为什么？
//因为这两个点必有一个不被另一个喜欢