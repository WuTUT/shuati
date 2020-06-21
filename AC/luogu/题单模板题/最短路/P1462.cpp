#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;
const int maxn=10005;
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
int f[maxn];
int r=-1;int l=INF;
struct Dijkstra{
    int n,m;

    bool done[maxn];
    ll d[maxn];
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

    void dijkstra(int s,int mid){
        memset(done,0,sizeof(done));
        while(!pq.empty()) pq.pop();
       // for(int i=0;i<n;i++) d[i]=INF;//1~n or 0~n-1
        for(int i=1;i<=n;i++) d[i]=INF;//1~n or 0~n-1
        d[s]=0;
        if(f[s]>mid) return;
        pq.push((HeapNode){s,0});
        while(!pq.empty()){
            HeapNode x=pq.top(); pq.pop();
            int u=x.u;
            if(done[u]) continue;
            done[u]=true;
            for(int i=0;i<g[u].size();i++){
                
                    Edge& e=edges[g[u][i]];
                    if(f[e.v]<=mid){
                        if(e.d+d[u]<d[e.v]){
                            d[e.v]=e.d+d[u];
                            p[e.v]=g[u][i];
                            pq.push((HeapNode){e.v,d[e.v]});
                        }
                    }
                
            }
        }
    }
}dij;


int main(){
    freopen("data.in","r",stdin);
    int n,m; int b;scanf("%d%d%d",&n,&m,&b);
    dij.init(n);
    
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i]);
        l=min(l,f[i]);
        r=max(r,f[i]);
    }
    
    int u,v,d;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&d);
        dij.AddEdge(u,v,d);
        dij.AddEdge(v,u,d);
    }
    dij.dijkstra(1,r);
    if(dij.d[n]>b){
        printf("AFK\n");
        return 0;
    }
    while(l<r){
        int mid=l+(r-l)/2;
        dij.dijkstra(1,mid);
        if(dij.d[n]<=b){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    printf("%d\n",l);
    
    return 0;
}

//最短路+二分，一看min max就应该想到是二分的