#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 2e4+5 , maxm = 2e5+5;
struct Edge{
    int x,y;
}edges[maxm];
vector<int> v[maxn];
int ef[maxm];
int cut[maxn];
int stk[maxn],low[maxn],dfn[maxn];
int top,ind;
void tarjan(int root,int fa){
    if(dfn[root]) return;
    dfn[root]=low[root]=++ind;
  //  stk[++top]=root;
    int child =0;
    for(int i=0;i<v[root].size();i++){
        int ei=v[root][i];
        if(ef[ei]) continue;
        ef[ei]=ef[ei^1]=1;
        int to = edges[ei].y;
        if(!dfn[to]){
            tarjan(to,root);
            low[root]=min(low[root],low[to]);
            if(dfn[root]<=low[to] && root!=fa){
                cut[root]=1;
            }
            if(root == fa){
                child++;
            }
        }
        else low[root] = min(low[root],dfn[to]);
    }
    if(child >=2 && root == fa){
        cut[root]=1;
    }
}
int main(){
    freopen("data.in","r",stdin);
    int n,m;
    cin >> n >> m;
    int x,y;
    for(int i=0;i<m;i++){
       cin >> x >> y;
        edges[i*2].x=x;
        edges[i*2].y=y;
        edges[i*2+1].y=x;
        edges[i*2+1].x=y;
        v[x].push_back(i*2);
        v[y].push_back(i*2+1);
    }
    for(int i=1;i<=n;i++){
        tarjan(i,i);
    }
    
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(cut[i]){
            ans.push_back(i);
        }
    }
    cout << ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i]<<" ";
    }
    return 0;
}


//求割点  点双联通模板

//不建图
//P3388