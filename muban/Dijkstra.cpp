#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
const int maxn=200005;
const int INF=0x7fffffff;
struct Edge{
    int u,v,d;
    Edge(int u,int v,int d):u(u),v(v),d(d){}
};
struct HeapNode{
    int u,d;
    bool operator <(const struct HeapNode& rhs)const{
        return d>rhs.d;
    }
};
struct Dijkstra{
    int n,m;

    bool done[maxn];
    int d[maxn];
    int p[maxn];

    vector<Edge> edges;
    vector<int> g[maxn];

    priority_queue<HeapNode> pq;
    void init(int n){
        this->n=n;
        // for(int i=0;i<n;i++){//1~n or 0~n-1
        //     g[i].clear();
        // }
        for(int i=1;i<=n;i++){//1~n or 0~n-1
            g[i].clear();
        }
        edges.clear();
        // while(!pq.empty()) pq.pop(); //   pq should clear ?
       
    }

    void AddEdge(int u,int v,int d){
        edges.push_back(Edge(u,v,d));
        m=edges.size();
        g[u].push_back(m-1);
    }

    void dijkstra(int s){
        memset(done,0,sizeof(done));
       // for(int i=0;i<n;i++) d[i]=INF;//1~n or 0~n-1
        for(int i=1;i<=n;i++) d[i]=INF;//1~n or 0~n-1
        d[s]=0;
        
        pq.push((HeapNode){s,0});
        while(!pq.empty()){
            HeapNode x=pq.top(); pq.pop();
            int u=x.u;
            if(done[u]) continue;
            done[u]=true;
            for(int i=0;i<g[u].size();i++){
                Edge& e=edges[g[u][i]];
                if(e.d+d[u]<d[e.v]){
                    d[e.v]=e.d+d[u];
                    p[e.v]=g[u][i];
                    pq.push((HeapNode){e.v,d[e.v]});
                }
            }
        }
    }
}dij;


int main(){
    freopen("data.in","r",stdin);
    int n,m,s;scanf("%d%d%d",&n,&m,&s);
    dij.init(n);
    int u,v,d;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&d);
        dij.AddEdge(u,v,d);
    }
    dij.dijkstra(s);
    bool first=true;
    for(int i=1;i<=n;i++){
        if(first){
            printf("%d",dij.d[i]);
            first=false;
        }
        else{
            printf(" %d",dij.d[i]);
        }
    }
}