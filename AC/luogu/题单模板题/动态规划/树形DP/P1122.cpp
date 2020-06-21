#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int maxn=16005;

vector<int> child[maxn];
    
bool isvis[maxn];
int w[maxn];
int f[maxn];
void dfs(int root){
    if(isvis[root]) return;
    isvis[root]=true;
    vector<int>& v=child[root];
    if(v.size()==0){
        f[root]=max(0,w[root]);
        return;
    }
    int sum=0;
    for(int i=0;i<v.size();i++){
        if(!isvis[v[i]]){
            dfs(v[i]);
            if(f[v[i]]>0) sum+=f[v[i]];
        }
    }
    f[root]=sum+w[root];
    return ;
}
int main(){
    freopen("data.in","r",stdin);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    int x,y;
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        child[x].push_back(y);
        child[y].push_back(x);
    }
    dfs(1);
    int maxf=0;
    for(int i=1;i<=n;i++){
        maxf=max(maxf,f[i]);

    }
    cout << maxf <<endl;
    return 0;
}

//丑陋的vis 无向最小生成树型图转成树，存双向边，从单个点遍历
//dfs真的不会爆栈???