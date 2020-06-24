#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn  = 35;
typedef long long ll;
int n,m;
ll f[maxn][maxn];
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    
    memset(f,0,sizeof f);
    f[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
             
            
            f[i][j]=f[i-1][(j+1)%n]+f[i-1][(j-1+n)%n];
            
        }
    }
    
    cout << f[m][0]<<endl;
    return 0; 
}