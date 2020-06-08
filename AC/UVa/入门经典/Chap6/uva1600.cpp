#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;
const int maxn=21;
int g[maxn][maxn];
int isvis[maxn][maxn][maxn];
int d[maxn][maxn][maxn];
int m,n,k;
struct Node
{
    int x,y,k;
    Node(int x,int y,int k):x(x),y(y),k(k){}
};

typedef struct Node P;
void bfs(){
    queue<P> q;
    q.push(P(0,0,0));
    isvis[0][0][0]=1;
    d[m-1][n-1][0]=-1;
    while(!q.empty()){
        P tmp=q.front();
        q.pop();
        for(int i=-1;i<=1;i++){
           for(int j=-1;j<=1;j++){
               if(abs(i)+abs(j)==1){
                   int nextx=tmp.x+i;
                   int nexty=tmp.y+j;
                   if(!(nextx<0 || nextx>=m || nexty<0 || nexty>=n) ){
                            int nextk;
                            if(g[nextx][nexty]==1 && tmp.k+1<=k){
                                nextk=tmp.k+1;
                                if(!isvis[nextx][nexty][nextk]){
                                    isvis[nextx][nexty][nextk]=1;
                                    d[nextx][nexty][nextk]=d[tmp.x][tmp.y][tmp.k]+1;
                                    q.push(P(nextx,nexty,nextk));
                                }
                            }else if(g[nextx][nexty]==0)
                            {
                                nextk=0;
                                if(!isvis[nextx][nexty][nextk]){
                                    isvis[nextx][nexty][nextk]=1;
                                    d[nextx][nexty][nextk]=d[tmp.x][tmp.y][tmp.k]+1;
                                    q.push(P(nextx,nexty,nextk));   
                                }
                            }
                   }
               }
            } 
        }
    }
    return;
}
int main(){
   // freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
   int T;
   cin>>T;
   while(T>0){
       T--;
       cin>>m>>n;
       cin>>k; 
       memset(isvis,0,sizeof(isvis));
       memset(d,0,sizeof(d));
       for(int i=0;i<m;i++){
           for (int j = 0; j < n; j++)
           {
               cin>>g[i][j];
           }
       }
       bfs();
       if(m==1 && n==1){
           cout<<0<<endl;
       }else
           cout<<d[m-1][n-1][0]<<endl;     
   }
    return 0;
}