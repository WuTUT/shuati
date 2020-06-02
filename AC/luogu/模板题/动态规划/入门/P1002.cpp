#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn=22;
long long g[maxn][maxn];
int main(){
    freopen("data.in","r",stdin); 
    int m,n,bx,by;
    scanf("%d%d%d%d",&m,&n,&bx,&by);
    
   
    for(int i=-2;i<=2;i++){
        for(int j=-2;j<=2;j++){
            if(i!=0 && j!=0 && abs(i)+abs(j)==3 ){
                if(bx+i>=0 && bx+i<=m && by+j>=0 && by+j<=n){
                    g[bx+i][by+j]=-1;
                }
            }
        }
    }
    g[bx][by]=-1;
    if(g[m][n]==-1) 
        printf("0");
    else{
        
        g[m][n]=1;
        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(g[i][j]==-1){
                    g[i][j]=0;
                }    
                else{
                    if(i+1<=m && j+1<=n){
                        g[i][j]=g[i+1][j]+g[i][j+1];
                    }else{
                        if(i+1<=m){
                            g[i][j]=g[i+1][j];
                        }else if(j+1<=n){
                            g[i][j]=g[i][j+1];
                        }
                    }
                }    
                
            }
        }
        printf("%lld",g[0][0]);
    }
    
    return 0;
}
//改 ll 就对了，好吧,DAG图的dp模板题