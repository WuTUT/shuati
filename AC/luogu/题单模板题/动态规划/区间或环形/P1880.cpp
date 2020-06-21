#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=102,INF=0x7f7f7f7f;

int f[2*maxn][2*maxn];
int a[2*maxn];int sum[2*maxn];
int main(){
    freopen("data.in","r",stdin);
    int n;cin>> n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i+n]=a[i];
        
    }
    for(int i=1;i<=2*n;i++){
        sum[i]=sum[i-1]+a[i];
    }
   
    for(int len=2;len<=n;len++){
        
        for(int i=1;i+len-1<2*n;i++){
            
            int j=i+len-1;
            f[i][j]=INF;
            for(int k=i;k<j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    
    int ans=INF;
    for(int i=1;i<=n;i++){
        ans=min(ans,f[i][i+n-1]);
    }
    cout << ans<<endl;
   
    
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<2*n;i++){
            int j=i+len-1;
            f[i][j]=0;
            for(int k=i;k<j;k++){
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,f[i][i+n-1]);
    }
    cout << ans<<endl;
}
//区间+环形DP
//区间dp枚举len，枚举left 枚举 中间 //注意要加上前缀和，前缀和不要写错！！！
//环形DP拆环方法: n -> 2*n 然后