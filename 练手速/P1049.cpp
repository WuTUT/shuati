#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 20005;
int n,m;
int f[maxn];
int a;
int main(){
    freopen("data.in","r",stdin);
    cin >> m;
    cin >> n;
    for(int i=1;i<=n;++i){
        scanf("%d",&a);
        for(int j=m;j>=a;j--){
            f[j]=max(f[j],f[j-a]+a);
        }
    }
    cout << m- f[m]<<endl;
    
}