#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 105;
int indegree[maxn];
int outdegree[maxn];
int ind;
int stk[maxn];
int top;
int scc[maxn];
int sccnum;
int low[maxn];
int dfn[maxn];
vector <int> v[maxn];

void tarjan(int root){
    if(dfn[root]) return ;
    dfn[root]=low[root]=++ind;
    stk[++top]=root;
    for(int i=0;i<v[root].size();i++){
        int to = v[root][i];
        if(!dfn[to]){
            tarjan(to);
            low[root]=min(low[root],low[to]);
        }
        else if(!scc[to]){
            low[root]=min(low[root],dfn[to]);
        }
    }
    if(dfn[root] == low[root]){
        sccnum++;
        while(1){
            int x=stk[top--];
            scc[x]=sccnum;
            if(x==root) break;
        }
        

    }

}
int main(){
    freopen("data.in","r",stdin);
    int n;
    cin>>n;
    int cx;
    for(int i=1;i<=n;i++){
        cin >>cx;
        while(cx){
            v[i].push_back(cx);
            cin >> cx;
        }
    }
    for(int i=1;i<=n;i++){
        tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            int to =v[i][j];
            if(scc[i]!=scc[to]){
                indegree[scc[to]]++;
                outdegree[scc[i]]++;
            }
        }
    }
   
    int a=0,b=0;int ans=0;
    for(int i=1;i<=sccnum;i++){
        if(outdegree[i]==0){
            a++;
        }
        if(indegree[i]==0){
            b++;
            ans++;
        }
    }
    
    cout << (ans==0?1:ans) <<endl;
    if(a>=b){
        ans = b+(a-b);
    }else{
        ans = a+(b-a);
    }
    if(sccnum==1) cout<< 0<<endl;
    else
        cout << ans <<endl;
}
//special judge n== 1 NOOOOO!!!!!!!
//sccnum == 1 只有1个大强联通块而不是一个点是缩点之后了！！！！！
//经典模板题，缩点后求出度入度 应用： 怎么最小花费把缩点后的图连成一个最大强连通