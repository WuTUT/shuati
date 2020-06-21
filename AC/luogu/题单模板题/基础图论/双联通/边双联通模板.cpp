#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
using namespace std;
const int maxn= 1e4+5;
struct Edge{
    int x,y;

}edges[maxn*2];
vector<int> v[maxn];
int n;
int mp[maxn][maxn];
int ef[maxn];
int dfn[maxn],low[maxn],bcc[maxn],stk[maxn];
int top,bccnum,ind;
void tarjan(int root){
    if(dfn[root]) return;
    dfn[root]=low[root]=++ind;
    stk[++top]=root;
    
    for(int i=0;i<v[root].size();i++){
        int ei=v[root][i];
        if(ef[ei]) continue;
        ef[ei]=ef[ei^1]=1;
        int to =edges[ei].y;
        if(!dfn[to]){
            tarjan(to);
            low[root]=min(low[root],low[to]);
        }
        else low[root]=min(low[root],dfn[to]); 
    }
    if(dfn[root]==low[root]){
        bccnum++;
        while(1){
            int x =stk[top--];
            bcc[x]=bccnum;
            if(x==root) break;
        }
    }
}
int in[maxn];
int main(){
    freopen("data.in","r",stdin);
    int f,r;
    cin >>f  >>r;
    int x,y;
    n=0;
    for(int i=0;i<r;i++){
        cin >> x >> y;
        if(mp[x][y]){
            continue;
        }
        else{
            mp[x][y]=mp[y][x]=1;
            edges[n].x=x;
            edges[n].y=y;
            v[x].push_back(n);
            n++;
            edges[n].y=x;
            edges[n].x=y;
            v[y].push_back(n);
            n++;
        }
    }
    for(int i=1;i<=f;i++){
        tarjan(i);
    }
    int from,to;
    for(int i=0;i<n;i+=2){
        from =edges[i].x;
        to = edges[i].y;
        if(bcc[from]!=bcc[to]){
            in[bcc[from]]++;
            in[bcc[to]]++;
        }
    }
   
    int leaf=0;
    for(int i=1;i<=bccnum;i++){
        if(in[i] == 1){ //写的居然是bccnum,居然还是第二次这么写了
            leaf++;   
        }
    }
    cout << (leaf+1)/2<<endl;
    return 0;
}
//POJ3177
//边联通分量的模板题
//求给出一个n个点,m条边的连通图，问至少加几条边使两两点可以至少两条路到达。
//去重边的一条办法，二维数组map 真O(1) n^2的邻接矩阵型复杂度
//缩点之后一定一条树
//叶子两两相连构成新双联通图