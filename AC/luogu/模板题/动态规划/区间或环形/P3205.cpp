#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1002, mod=19650827;
int a[maxn];
int f[maxn][maxn][2];
int main(){
    freopen("data.in","r",stdin);
    int n;cin>> n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        f[i][i][0]=1;
      //  f[i][i][1]=1;
    }
    for(int len=1;len<n;len++){
        for(int i=1;i+len<=n;i++){
            int j=i+len;
            if(a[j]>a[i]) f[i][j][1]=f[i][j-1][0];
            if(a[j]>a[j-1]) f[i][j][1]=(f[i][j][1]+f[i][j-1][1])%mod;
            if(a[i]<a[i+1]) f[i][j][0]=f[i+1][j][0];
            if(a[i]<a[j]) f[i][j][0]=(f[i][j][0]+f[i+1][j][1])%mod;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<i;j++)
    //         cout<<"  ";
    //     for(int j=i;j<=n;j++){
    //         cout <<f[i][j] <<" ";
    //     }
    //     cout <<endl;
    // }
    cout << (f[1][n][0]+f[1][n][1])%mod<<endl;
    return 0;
}