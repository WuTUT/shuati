#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int INF=0x7fffffff;
const int maxn=205;
int t[maxn];
int d[maxn][maxn];
int main(){
    freopen("data.in","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    int u,v,w;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j]=INF;
        }
    }
    for(int i=0;i<n;i++){
        d[i][i]=0;
    }
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        d[u][v]=w;
        d[v][u]=w;
    }
    
    int q;scanf("%d",&q);
    int x,y,ti;int lastti=-1;
    for(int i=0;i<q;i++){
        scanf("%d%d%d",&x,&y,&ti);
       // printf("%d %d ti= %d,lastti=%d\n",x,y,ti,lastti);
        
        for(int k=0;k<n;k++){
            if(t[k]<=ti&&t[k]>lastti){
              //  printf("k= %d, t[k]=%d,  \n",k,t[k]);
                for(int j=0;j<n;j++){  //不去判断t[j]<=ti
                    for(int l=0;l<n;l++){//不去判断t[l]<=ti
                        if( d[j][k]<INF && d[k][l]<INF){
                           // printf("d[%d, %d] = %d\n",j,k,d[j][k]);
                           // printf("d[%d, %d] = %d\n",k,l,d[k][l]);
                            d[j][l]=min(d[j][l],d[j][k]+d[k][l]);
                           // printf("d[%d, %d] = %d\n",j,l,d[j][l]);
                        }
                    }
                }
            }
            
        }

        if(t[x]>ti || t[y]>ti || d[x][y]>=INF){
            printf("-1\n");
        }else{
            printf("%d\n",d[x][y]);
        }
        lastti=ti;
    }
    return 0;
}

//Floyd 每次激活t[k]在(lastti,ti]的k，因为新的最短路径更新必然在这些点产生。充分长时间最后复杂度只是O(n^3)不会再增长。