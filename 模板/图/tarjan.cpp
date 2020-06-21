#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1e4+5;
struct Tarjan{
    int dfn[maxn];
    int low[maxn];
    int scc[maxn];
    int sccnum;
    int stack[maxn];
    int top;
    int index;

    int num_of_scc[maxn];
    vector<int> v[maxn];


    void init(int n){
        memset(dfn,0,sizeof(int) * (n+1));
        memset(low,0,sizeof(int) * (n+1));
        sccnum = 0;
        top = 0;
        index = 0;
    }
    void tarjan(int root){
        if(dfn[root]){
            return;
        }
        dfn[root]=low[root]=++index;
        stack[++top]=root;
        for(int i=0;i<v[root].size();i++){
            int to=v[root][i];
            if(!dfn[to]){
                tarjan(to);
                low[root]=min(low[root],low[to]);
            }
            else if(!scc[to]){//IMPORTANT!!!!!!!!!!!!!!!!!!1
                low[root]=min(low[root],dfn[to]);
            }
        }
        if(dfn[root]==low[root]){
            sccnum++;
            while(1){
                int x=stack[top--];
                scc[x]=sccnum;
                num_of_scc[sccnum]++;
                if(x==root) break;
            }
        }
    }
}tar;


int main(){
    freopen("data.in","r",stdin);
    int n,m;
    cin >> n >> m;
    int a,b;
    tar.init(n);
    for(int i=1;i<=m;i++){
        cin >> a >> b;
        tar.v[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
        tar.tarjan(i);
    
    int tmp=0;
    for(int i=1;i<=tar.sccnum;i++){
        if(tar.num_of_scc[i]>1) 
            ++tmp;
    }
    cout << tmp <<endl;
    return 0;
}

//https://www.luogu.com.cn/problem/P2863 tarjan 模板，强连通分量大于1的个数
//强联通分量模板
//原题数据水 上面注释的那一句容易忘