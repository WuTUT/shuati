#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1005;
int n,m;
struct point{
    int x,y;
}po[maxn];
double g[maxn][maxn];
struct Edge{
    int u,v;
    double dis;
    Edge(int u,int v,double dis):u(u),v(v),dis(dis){

    }
    bool operator<(const Edge& rhs) const {
        return dis < rhs.dis;
    }
};
vector<Edge> edges;
int fa[maxn];
int findfa(int x){
    while(fa[x]!=x) x=fa[x]=fa[fa[x]];//并查集没写对啊
    return x;
}
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        cin >> po[i].x >> po[i].y;    
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
           g[i][j]=sqrt( (double)(po[i].x-po[j].x)*(po[i].x-po[j].x) + (double)(po[i].y-po[j].y)*(po[i].y-po[j].y) );
           
        }
    }
    int x,y;
    for(int i=1;i<=m;i++){
        cin >> x >> y;
        if(x>y) std::swap(x,y);
        g[x][y]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            edges.push_back(Edge(i,j,g[i][j]));
        }
    } 
    int esize = edges.size();
    sort(edges.begin(),edges.end());
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    double ans;
    int cnt=0;
    for(int i=0;i<esize;i++){
       int u = edges[i].u;
       int v = edges[i].v;
       if(findfa(u)==findfa(v)) continue;
       fa[findfa(u)]=findfa(v);//Kruskal第二个错点！！！要把爸爸链上去！！！！！！！而不是把u和v链上去
       ans+=edges[i].dis;
       cnt++;
       if(cnt == n-1) break;
    }
    printf("%.2lf\n",ans);
    return 0;
}

//double强转！！！sqrt一个数时也要先把他转double在调用