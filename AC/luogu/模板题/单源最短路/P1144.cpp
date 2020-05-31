#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
const int maxn=1000005;
const int INF=0x7fffffff;
typedef long long ll;
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
    ll p[maxn];

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
        p[s]=1;
        pq.push((HeapNode){s,0});
        while(!pq.empty()){
            HeapNode x=pq.top(); pq.pop();
            int u=x.u;
            if(done[u]) continue;
            done[u]=true;
            for(int i=0;i<g[u].size();i++){
                Edge& e=edges[g[u][i]];
                if(e.d+d[u]<=d[e.v]){
                    if(e.d+d[u]==d[e.v]){
                       // if(p[e.v]==0) //永远不会出现
                      //      p[e.v]=p[u];
                       // else{
                            p[e.v]=(p[u]+p[e.v])%100003;
                       // }
                    }
                   // if(p[e.v]==0) //为0一定是在else条件下发生的
                    else   p[e.v]=p[u];
                        
                    d[e.v]=e.d+d[u];
                    
                    pq.push((HeapNode){e.v,d[e.v]});
                }
            }
        }
    }
}dij;


int main(){
    freopen("data.in","r",stdin);
    int n,m,s;scanf("%d%d",&n,&m);
    dij.init(n);
    int u,v,d;
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        dij.AddEdge(u,v,1);
        dij.AddEdge(v,u,1);
    }
    dij.dijkstra(1);
    bool first=true;
    for(int i=1;i<=n;i++){
        if(first){
            printf("%d",dij.p[i]%100003);
            first=false;
        }
        else{
            printf("\n%d",dij.p[i]%100003);
        }
    }
}

//最短路模板题：求单源最短路的条数，只需要修改模板的p[]并维护，起点定为1，大概想象为前缀和
//注意一边算一边取模防溢出，第一次见到
//单源到多终点叫单源最短路，有重边，有自边，有向无向，dij万能！