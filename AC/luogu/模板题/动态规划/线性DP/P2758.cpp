#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2005,INF =0x7f7f7f7f;
char a[maxn],b[maxn];
int dp[maxn][maxn];
int cnt1,cnt2;
int main(){
    freopen("data.in","r",stdin);
    char c;
   // while(c=getchar() && c!='\n' && c!=EOF){// wrong! mei kuo hao a ! ge !!!
    //while(scanf("%c",&c) && c!='\n' && c!=EOF){ wrong!
    while((c=getchar())!='\n' && c!=EOF){
       
        a[++cnt1]=c;
    }
    
    while((c=getchar())!='\n' && c!=EOF){
        
        b[++cnt2]=c;
    }
    for(int i=1;i<=cnt1;i++) dp[i][0]=i;
    for(int i=1;i<=cnt2;i++) dp[0][i]=i;
   // cout <<cnt1 <<" "<<cnt2 <<endl;
    for(int i=1;i<=cnt1;i++){
        for(int j=1;j<=cnt2;j++){
            
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=  min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1 ;
        }
    }
    
    cout << dp[cnt1][cnt2] <<endl; 
    return 0;
}

//加括号啊 赋值优先级那么低