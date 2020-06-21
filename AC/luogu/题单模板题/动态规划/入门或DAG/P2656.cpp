#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 80005,maxm = 200005;
vector<int> v[maxn];
struct Edge{
    int x,y,w;
    double re;
}edges[maxm];
int st,nst;
int scc[maxn],num_scc[maxn];
int top,ind,sccnum;
int low[maxn],dfn[maxn],stk[maxn];
void tarjan(int root){
    if(dfn[root]) return;
    dfn[root] = low[root] =++ind;
    stk[++top]=root;
    for(int i=0;i<v[root].size();i++){
        Edge& e = edges[v[root][i]];
        int to =e.y;
        if(!dfn[to]){
            tarjan(to);
            low[root]=min(low[root],low[to]);
        }
        else if(!scc[to]){
            low[root] = min(low[root],dfn[to]);
        }
    }
    if(dfn[root]==low[root]){
        sccnum++;
        while(1){
            int x= stk[top--];
            scc[x]= sccnum;
            if(x==st) nst = sccnum;
            if(x== root) break;
        }
    }
}
int in[maxn];
vector<int> nv[maxn];
vector<int> nw[maxn];
int f[maxn];
int main(){
    freopen("data.in","r",stdin);
    
    int n,m;
    cin >> n >> m;
    int x,y;int w;
    double z;
    
    for(int i=1;i<=m;i++){
        cin >> x >> y >> w >> z;
    
        edges[i].x=x;
        edges[i].y=y;
        edges[i].w=w;
        edges[i].re=z;
        v[x].push_back(i);
    }
    
    cin >> st;
    for(int i=1;i<=n;i++){
        tarjan(i);
    }
    
    for(int i=1;i<=m;i++){
        x = edges[i].x;
        y = edges[i].y;
        w = edges[i].w;
        z = edges[i].re;
        if(scc[x]==scc[y]){
            while(w){
                num_scc[scc[x]]+=w;
                
                w =(int)(w*z);
                
            }
        }
        else{
            in[scc[x]]++;
            nv[scc[y]].push_back(scc[x]);
            nw[scc[y]].push_back(w);
        }
    }
    queue<int> q;
    for(int i=1;i<=sccnum;i++){
        if(in[i]==0){
            q.push(i);
        }
        f[i]=num_scc[i];
       
    }
    
    //for(int i=1;i<=sccnum;i++) cout<<f[i]<<endl;
    //cout<< q.front()<<endl;
    while(!q.empty()){
        int i = q.front(); q.pop();
        
        for(int j=0;j<nv[i].size();j++){
            int ne = nv[i][j];
            --in[ne];
            f[ne]=max(f[ne],f[i]+num_scc[ne]+nw[i][j]);
            if(!in[ne]){
                q.push(ne);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout << scc[i]<<endl;
    // }
    //cout << nst<<endl;
    
  //for(int i=1;i<=sccnum;i++) cout<<f[i]<<endl;
    
    cout << f[nst]<<endl;
    
    return 0;
}

//你永远不要相信float