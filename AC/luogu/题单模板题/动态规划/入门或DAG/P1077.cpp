#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn=105,mod=1000007;
int n,m;
int a[maxn];
int f[maxn];
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    } 
    for(int j=0;j<=a[1];j++){
        f[j]=1;
    }
    for(int i=2;i<=n;i++){
      //  for(int j=0;j<=m;j++){
        for(int j=m;j>=0;j--){
            int sum=0;
            for(int k=0;k<=a[i] && k<=j;k++){
                
                    //f[i][j]=f[i][j]+f[i-1][j-k];
                    sum+=f[j-k];
                
            }
            f[j]=sum%mod;
        }
        // for(int j=0;j<=m;j++)
        //     cout << f[j] <<" ";
        // cout <<endl;
    }
    cout << f[m] << endl;
    return 0;
}
//背包题  优化是按照0-1背包优化的，而完全背包是推导出来的，不要套用