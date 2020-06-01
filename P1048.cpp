#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int maxn=105;
int a[maxn];
int dp[maxn][maxn];
int main(){
    freopen("data.in","r",stdin);
    int r;scanf("%d",&r);
    int tmp;

    for(int i=1;i<=r;i++){
        v[i].resize(i);
        for(int j=0;j<i;j++){
            scanf("%d",&tmp);
            v[i][j]=(tmp);
        } 
    }
    for(int i=0;i<r;i++){
        dp[r][i]=v[r][i];
        //printf("dp[%d %d]= %d\n",r,i,dp[r][i]);
    }
    for(int i=r-1;i>=1;i--){
        for(int j=0;j<i;j++){
            dp[i][j]=v[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
         //   printf("dp[%d %d]= %d\n",i,j,dp[i][j]);
        }
    }

    printf("%d\n",dp[1][0]);
    return 0;
}