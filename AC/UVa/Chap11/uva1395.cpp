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
       
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&edges[i].x,&edges[i].y,&edges[i].w);
        }
        sort(edges,edges+m,cmp);
        int l=edges[0].w;int minslim=edges[m-1].w-l+1;
        int maxw=edges[m-1].w;bool over=false;int i=0;int tmpi=i;
        while(l<=maxw){
            int r=l;int count=0;
            for(int k = 0; k <= n; k++) fa[k]=k;
            while(r<=maxw){
                bool reach=false;
                for(i;i<m && edges[i].w<=r;i++){
                    int rootx=find(edges[i].x);
                    int rooty=find(edges[i].y);
                    if(rootx==rooty) continue;
                    
                    fa[rooty]=rootx;
                    count++;
                    if(count==n-1){
                        reach=true;
                        break;
                    }
                }
                if(reach){
                 //   printf("r-l %d %d\n",r,l);
                    minslim=min(minslim,r-l);
                    break;
                }else{
                    if(i<m)
                        r=edges[i].w;
                    else{
                        if(tmpi==0){
                            over=true;
                        }
                        break;
                    }
                }        
            }
            if(over){
                break;
            }
            else{
                
                int j;
                for(j=tmpi;j<m && edges[j].w<=l;j++){
                }
                tmpi=j;
                if(j>=m) break;
                l=edges[j].w;
                i=j;
            }
        }    
        
        if(!over && m!=0)
            printf("%d\n",minslim);    
        else 
            printf("-1\n");
    }   
    
    return 0;
}
//最瘦生成树
//l和r遍历m啊，遍历w干嘛，太复杂了
//枚举边的标号而不是权重！！！
