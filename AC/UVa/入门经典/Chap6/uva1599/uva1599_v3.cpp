#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;
const int maxn=100010;

struct Edge{
    int v1,v2,c;
    Edge(int v1,int v2, int c):v1(v1),v2(v2),c(c){}
};
vector<int> g[maxn];
vector<Edge> edges;
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
            struct Edge* nexti=&(edges[g[tmp][i]]);
            int adj;
            if(tmp==nexti->v1) adj=nexti->v2;
            else adj=nexti->v1;
            if(!isvisit[adj]){
                q.push(adj);
                d[adj]=d[tmp]+1;
                isvisit[adj]=1;
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
    
    vector<int> q;
    
    memset(isvisit,0,sizeof(isvisit));
    q.push_back(1);
    isvisit[1]=1;
    
    // while(!q.empty()){
    //     int qsize=q.size();
    //     int mincolor=(1e+11)+1;
    //     mincol_count=0;
    //     for(int qi=0;qi<qsize;qi++){
    //         int tmp=q.front();
    //         q.pop();
            
    //         int size=g[tmp].size();
            
    //         for(int i=0;i<size;i++){
    //             struct Edge* nexti=&(edges[g[tmp][i]]);
    //             int dist=nexti->c;
    //             int adj;
    //             if(tmp==nexti->v1) adj=nexti->v2;
    //             else adj=nexti->v1;
    //             if(!isvisit[adj] && ( (d[adj]+1)==d[tmp] )){
                    
    //                 if(mincolor>dist){
    //                     mincolor=dist;
    //                     mincol_count=0;
    //                     mincol_id[mincol_count]=adj;
    //                     mincol_count++;
    //                 }
    //                 else if(mincolor==dist){
    //                     mincol_id[mincol_count]=adj;
    //                     mincol_count++;
    //                 }
    //             }
    //         }
        
    //     }
    //     ans.push_back(mincolor);
    //     int idsize=mincol_count;
    //     for(int i=0;i<idsize;i++){
    //         q.push(mincol_id[i]);
    //         isvisit[mincol_id[i]]=1;
    //     }
    // }
    for(int i=0;i<=d[1];i++){
        int qsize=q.size();
        //int mincolor=(1e+9)+10;
        int mincolor=0x3fffffff;
        for(int j=0;j<qsize;j++){
            int size=g[q[j]].size();
            for(int k=0;k<size;k++){
                struct Edge* nexti=&(edges[g[q[j]][k]]);
                int dist=nexti->c;
                int adj;
                if(q[j]==nexti->v1) adj=nexti->v2;
                else adj=nexti->v1;
                if(!isvisit[adj] && ( (d[adj]+1)==d[q[j]] )){
                    if(mincolor>dist){
                        mincolor=dist;
                    }
                }
            }
        }
        ans.push_back(mincolor);
        vector<int> tnext; 
        for(int j=0;j<qsize;j++){
            int size=g[q[j]].size();
            for(int k=0;k<size;k++){
                struct Edge* nexti=&(edges[g[q[j]][k]]);
                int dist=nexti->c;
                int adj;
                if(q[j]==nexti->v1) adj=nexti->v2;
                else adj=nexti->v1;
                if(!isvisit[adj] && ( (d[adj]+1)==d[q[j]] )){
                    if(mincolor==dist){
                       tnext.push_back(adj);
                       isvisit[adj]=1;
                    }
                }
            }
        }
        
        q=tnext;
    }
    return;
}

int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
  
   while(scanf("%d%d", &n, &m) == 2){
       
       int v1,v2;
       int color;
        
        memset(d,0,sizeof(d));
        memset(isvisit,0,sizeof(isvisit));
        edges.clear();
        fill(g, g+maxn, vector<int>{});
        
        
        ans.clear();

       for(int i=0;i<m;i++){
           scanf("%d%d%d",&v1,&v2,&color);
           if(v1 == v2 ) continue;
           struct Edge e(v1,v2,color);
           edges.push_back(e);
           g[v1].push_back(edges.size()-1);
           g[v2].push_back(edges.size()-1); 
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