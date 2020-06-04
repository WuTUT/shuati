#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
const int maxn=5005;
const int mod=80112002; 
struct Edge{
    int a,b;
    Edge(int a,int b):a(a),b(b){}
};
vector<Edge> edges;
vector<int> g[maxn];
long long dp[maxn];
long long indegree[maxn];
long long outdegree[maxn];
int main(){
    freopen("data.in","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        edges.push_back(Edge(a,b));
        g[a].push_back(edges.size()-1);
        indegree[b]++;
        outdegree[a]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indegree[i]){
            q.push(i);
            if(outdegree[i]!=0){
                dp[i]=1;
            }
        }
    }
    long long maxnum=0;
    while(!q.empty()){
        int i=q.front();q.pop();
        for(int j=0;j<outdegree[i];j++){
            Edge& e=edges[g[i][j]];
            dp[e.b]= (dp[i]+dp[e.b])%mod;
            
            indegree[e.b]--;
            if(!indegree[e.b])//!!!!
                q.push(e.b);
        }
    }

    for(int i=1;i<=n;i++){
        if(outdegree[i]==0){
            maxnum=(maxnum+dp[i])%mod;
        }
    }
    
    printf("%lld",maxnum);
}


//DAG的最多路径，利用拓扑排序的办法遍历来保证