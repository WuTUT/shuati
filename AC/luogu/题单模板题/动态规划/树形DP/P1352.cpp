#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 6005;
struct node{
    int w;
    vector<int> child;
}no[maxn];
int n;
int f[maxn][2];
bool isroot[maxn];
void dfs(int root){
    if(no[root].child.size()==0){
        f[root][1]=no[root].w;
        f[root][0]=0;
        return;
    }
    int vsize=no[root].child.size();
    int sum=0;int sum2=0;
    for(int i=0;i<vsize;i++){
        int x=no[root].child[i];
        dfs(x);
        
        sum+=f[x][1];
        sum2+=f[x][0];
    }
    f[root][1]=sum2+no[root].w;
    f[root][0]=max(sum,sum2);
    return ;
}
int main(){
    freopen("data.in","r",stdin);
    cin >> n;
    for(int i=1;i<=n;i++){
        scanf("%d",&(no[i].w));
    }
    int x,y;
    for(int i=1;i<=n;i++) isroot[i]=true;
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        no[y].child.push_back(x);
        isroot[x]=false;
    }
    int root;
    for(int i=1;i<=n;i++){
        if(isroot[i]){
            root = i;
            break;
        }
    }
    dfs(root);
    cout << max(f[root][0],f[root][1]) <<endl;
    return 0;
}