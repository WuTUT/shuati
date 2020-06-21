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
    int u,v,w;
    Edge(int u,int v,int w):u(u),v(v),w(w){}
};
struct SPFA{
    int n,m;
    bool inq[maxn];
    int cnt[maxn];
    int d[maxn];
    int p[maxn];
    vector<Edge> edges;
    vector<int> g[maxn];

    queue<int> q;
    void init(int n){
        this->n=n;
        
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        edges.clear();
        while(!q.empty()) q.pop();
    }
    void AddEdge(int u,int v,int w){
        edges.push_back(Edge(u,v,w));
        m=edges.size();
        g[u].push_back(m-1);
    }
    bool spfa(int s){
        memset(inq,0,sizeof(inq));    
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            d[i]=INF;
        }
        d[s]=0;
        q.push(s);
        inq[s]=true;

        while(!q.empty()){
            int u=q.front();q.pop();
            
            inq[u]=false;//important

            for(int i=0;i<g[u].size();i++){
                Edge& e=edges[g[u][i]];
                if(d[u]<INF && d[e.v]>d[u]+e.w){
                    d[e.v]=d[u]+e.w;
                    p[e.v]=g[u][i];
                    if(!inq[e.v]){
                        q.push(e.v);
                        inq[e.v]=true;
                        if(++cnt[e.v]>n) return false;
                    }
                }
            }
        }
        return true;
    }
}spfa;
int main(){
    freopen("data.in","r",stdin);
    int T;scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        spfa.init(n);
        int u,v,w;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            if(w>=0){
                spfa.AddEdge(u,v,w);
                spfa.AddEdge(v,u,w);
            }
            else{
                spfa.AddEdge(u,v,w);
            }
        }
        if(spfa.spfa(1)){
            printf("NO\n");
        }else
        {
            printf("YES\n");
        }
        
        
    }
    
    return 0;
}

//判断负环的模板题，必须要用SPFA做