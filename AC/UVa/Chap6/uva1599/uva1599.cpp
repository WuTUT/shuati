#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;
const int maxn=100010;
vector<int> g[maxn];
map<pair<int,int> ,int> cg;

int d[maxn];
int n,m;
int isvisit[maxn];

vector<int> ans;
vector<int> mincol_id;
void rbfs(){
    queue<int> q;
    q.push(n);
    isvisit[n]=1;
    
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        
        int size=g[tmp].size();
        for(int i=0;i<size;i++){
            int nexti=g[tmp][i];
            if(!isvisit[nexti]){
                q.push(nexti);
                d[nexti]=d[tmp]+1;
                isvisit[nexti]=1;
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
        int mincolor=(1e+11)+1;
        mincol_id.clear();
        for(int qi=0;qi<qsize;qi++){
            int tmp=q.front();
            q.pop();
            
            int size=g[tmp].size();
            
            for(int i=0;i<size;i++){
                int nexti=g[tmp][i];
                pair<int,int> p;
                if(nexti>tmp){
                    p=make_pair(tmp,nexti);
                }
                else{
                    p=make_pair(nexti,tmp);
                }
                int dist=cg[p];
                if(!isvisit[nexti] && ( (d[nexti]+1)==d[tmp] )){
                    
                    if(mincolor>dist){
                        mincolor=dist;
                        mincol_id.clear();
                        mincol_id.push_back(nexti);
                    }
                    else if(mincolor==dist){
                        mincol_id.push_back(nexti);
                    }
                }
            }
        
        }
        ans.push_back(mincolor);
        int idsize=mincol_id.size();
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
  
   while(cin>>n){
       cin>>m;
       int v1,v2;
       int color;
        
        memset(d,0,sizeof(d));
        memset(isvisit,0,sizeof(isvisit));
        
        fill(g, g+maxn, vector<int>{});
        cg.clear();
        
        ans.clear();

       for(int i=0;i<m;i++){
           cin>>v1>>v2>>color;
           if(v1 == v2 ) continue;
           g[v1].push_back(v2);
           g[v2].push_back(v1);
          
           if(v1<v2){
                pair<int,int> p(v1,v2);
               if(cg.count(p)){
                   cg[p]=min(color,cg[p]);
               }
               else  cg[p]=color;
           }
           else{
               pair<int,int> p(v2,v1);
               if(cg.count(p)){
                   cg[p]=min(color,cg[p]);
               }
               else  cg[p]=color;
           }
           
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