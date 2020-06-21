#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1005,d=20002,p=20000,mod=998244353;
int a[maxn];
int f[maxn][2*d];
int main(){
    freopen("data.in","r",stdin);
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            f[i][p+a[i]-a[j]]=(f[i][p+a[i]-a[j]]+f[j][p+a[i]-a[j]]+1)%mod;
            ans=(ans+f[j][p+a[i]-a[j]]+1)%mod;
        }
        
    }
    cout <<ans+n<<endl;
}

//等差子序列  emmm