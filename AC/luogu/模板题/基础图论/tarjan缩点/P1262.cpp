#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 3005,maxm=8005,INF=0x7f7f7f7f;
int a[maxn];
vector<int> v[maxn];
struct Edge{
    int x,y;
}edges[maxm];
int dfn[maxn];
int low[maxn];
int stack[maxn];
int top;
int ind;
int scc[maxn];
int sccnum;
int lescc[maxn];
int minscc[maxn];
void tarjan(int root){
    if(dfn[root]) return;
    dfn[root]=low[root]=++ind;
    stack[++top]=root;
    for(int i=0;i<v[root].size();i++ ){
        int to=v[root][i];
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
        int minw=INF;
        while(1){
            int x= stack[top--];
            if(minw>a[x]){
                minw=a[x];
            }
            lescc[sccnum]=min(lescc[sccnum],x);
            scc[x]=sccnum;
            if(x==root) break;
        }
        minscc[sccnum]=minw;
    }
}
int indegree[maxn];
int main(){

    freopen("data.in","r",stdin);
    int n;
    cin >> n;
    int p;
    cin >> p;
    int p_num;int px;
    memset(a,0x7f,sizeof a);
    memset(lescc,0x7f,sizeof lescc);
    
    for(int i=1;i<=p;i++){
        cin >>p_num >> px;
        a[p_num]=px;
    }
    int r;
    int ax,bx;
    cin >> r;
    
    for(int i=1;i<=r;i++){
        cin >> ax >> bx;
        v[ax].push_back(bx);
        edges[i].x=ax;
        edges[i].y=bx;
    }
    for(int i=1;i<=n;i++){
        tarjan(i);
    }
    
    for(int i=1;i<=r;i++){
        int from = edges[i].x;
        int to = edges[i].y;
        if(scc[from]!=scc[to]){
            indegree[scc[to]]++;
        }
    }
    
    int ans=9000;int cost=0;
    bool fi=true;
    for(int i=1;i<=sccnum;i++){
        if(indegree[i]==0){
            if(minscc[i]==INF){
                fi=false;
                ans=min(ans,lescc[i]);
               
            }else{
                cost+=minscc[i];
            }
        }
    }
    if(fi){
        cout <<"YES"<<endl;cout<<cost<<endl;
    }
    else{
        cout << "NO"<<endl;cout <<ans<<endl;
    }
    return 0;
}
//既然是有向图，先考虑有无环肯定是显然的，其次是否有重边，是否联通，是否有最短路的特征，有无负边权