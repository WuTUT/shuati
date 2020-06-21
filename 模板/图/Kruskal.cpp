#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
const int maxn=200005;
struct Edge{
    int x;int y;int w;
    
}edges[maxn];
bool cmp(const struct Edge& e1,const struct Edge& e2){
    return e1.w<e2.w;
}
int fa[5005];
int find(int x){
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
int main(){
    freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i <= n; i++) //should be Nodes i<=n not m
    {
        fa[i]=i;
    }
    
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&edges[i].x,&edges[i].y,&edges[i].w);
    //NOOOOOOO!!!!    fa[i]=i;
    }
    sort(edges,edges+m,cmp);
    int ans=0;int count=0;
    for(int i=0;i<m;i++){
        int rootx=find(edges[i].x);
        int rooty=find(edges[i].y);
        if(rootx==rooty) continue;
        ans+=edges[i].w;
        //ADD IN
        fa[rooty]=rootx;//不要写反了
        count++;
        if(count==n-1){
            break;
        }
    }
    if(count==n-1)
        printf("%d",ans);    
    else 
        printf("orz");        
          
    return 0;
}