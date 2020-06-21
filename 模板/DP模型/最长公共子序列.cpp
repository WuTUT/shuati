#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
const int maxn=1e3+5;
int a[maxn],b[maxn];
int dp[maxn][maxn];
int main(){
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j])
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    printf("%d",dp[n][n]);
    return 0;
}