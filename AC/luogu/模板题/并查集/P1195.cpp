#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
const int maxn=10005;
struct Edge{
    int u,v,w;
    bool operator <(const struct Edge& re) const{
        return w<re.w;
    }
}edges[10005];
int fa[maxn];
int find(int x){
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
int main(){
    //freopen("data.in","r",stdin);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    int v,u,l;int cnt=0;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
    
    }
    sort(edges,edges+m);int ans=0;
    while(1){
        if( n-cnt == k) break;
        for(int i=0;i<m;i++){
            u=edges[i].u;
            v=edges[i].v;
            int rootu=find(u);
            int rootv=find(v);
            if(rootu==rootv) continue;
            else{
                fa[rootu]=rootv;
                ans+=edges[i].w;
                cnt++;
                if(n-cnt == k) break;
            }
        }
    }
    if(n-cnt == k) {
        printf("%d",ans);
    }
    else
    {
        printf("No Answer");
    }
     
    

}
//输出"No Answer"的只有需要生成的棉花糖数大于云彩原料总数的情况
//所以大概没有判断，还好没有tle