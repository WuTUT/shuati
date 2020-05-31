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
    while(scanf("%d%d",&n,&m)==2 && n){
        for(int i = 0; i <= n; i++) fa[i]=i;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&edges[i].x,&edges[i].y,&edges[i].w);
        }
        sort(edges,edges+m,cmp);
        int l=edges[0].w;int r=l;int i=0;
        while(1){
            int count=0;
            int ans=0;
            l=edges[i].w;
            for(;i<m && edges[i].w<=r;i++){
                int rootx=find(edges[i].x);
                int rooty=find(edges[i].y);
                if(rootx==rooty) continue;
                
                fa[rooty]=rootx;
                count++;
                if(count==n-1){
                    break;
                }
            }
            if(count==n-1)
                printf("%d",r-l);    
            else 
                printf("-1\n");        
            
        }
        
    }   
    
    return 0;
}