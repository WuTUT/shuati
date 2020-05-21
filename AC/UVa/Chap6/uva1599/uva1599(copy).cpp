#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;
const int maxn=100010;

struct Edge{
    int v,c;
    Edge(int v, int c):v(v),c(c){}
};
vector<Edge> g[maxn];

int d[maxn];
int n,m;
int isvisit[maxn];

vector<int> ans;
int mincol_id[maxn];
int mincol_count;
void rbfs(){
    queue<int> q;
    q.push(n);
    isvisit[n]=1;
    
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        
        int size=g[tmp].size();
        for(int i=0;i<size;i++){
            struct Edge nexti=g[tmp][i];
            if(!isvisit[nexti.v]){
                q.push(nexti.v);
                d[nexti.v]=d[tmp]+1;
                isvisit[nexti.v]=1;
            }
        }
    }
    // cout<<"D is"<<endl;
    // for(int i=1;i<n;i++){
    //     cout<<d[i]<<" ";
    // }
    // cout<<endl;
    return;
}
void bfs(){
    
    queue<int> q;
    
    memset(isvisit,0,sizeof(isvisit));
    q.push(1);
    isvisit[1]=1;
    while(!q.empty()){
        int qsize=q.size();
        int mincolor=(1e+9)+1;
        mincol_count=0;
        for(int qi=0;qi<qsize;qi++){
            int tmp=q.front();
            q.pop();
            
            int size=g[tmp].size();
            
            for(int i=0;i<size;i++){
                struct Edge nexti=g[tmp][i];
                int dist=nexti.c;
                
                if(!isvisit[nexti.v] && ( (d[nexti.v]+1)==d[tmp] )){
                    
                    if(mincolor>dist){
                        mincolor=dist;
                        mincol_count=0;
                        mincol_id[mincol_count]=(nexti.v);
                        mincol_count++;
                    }
                    else if(mincolor==dist){
                        mincol_id[mincol_count]=(nexti.v);
                        mincol_count++;
                    }
                }
            }
        
        }
        ans.push_back(mincolor);
        int idsize=mincol_count;
        for(int i=0;i<idsize;i++){
            q.push(mincol_id[i]);
            isvisit[mincol_id[i]]=1;
        }
    }
    return;
}
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
  
   while(scanf("%d %d", &n, &m) == 2){
       
       int v1,v2;
       int color;
        
        memset(d,0,sizeof(d));
        memset(isvisit,0,sizeof(isvisit));
        
        fill(g, g+maxn, vector<struct Edge>{});
        
        
        ans.clear();

       for(int i=0;i<m;i++){
           scanf("%d%d%d",&v1,&v2,&color);
           if(v1 == v2 ) continue;
           struct Edge edge1(v2,color);
           struct Edge edge2(v1,color);
           g[v1].push_back(edge1);
           g[v2].push_back(edge2); 
       }
       rbfs();
       
       bfs();
       int anssize=ans.size();
       printf("%d\n",d[1]);
       for(int i=0;i<anssize-2;i++){
           printf("%d ",ans[i]);
       }
        printf("%d\n",ans[anssize-2]);
   }
    return 0;
}