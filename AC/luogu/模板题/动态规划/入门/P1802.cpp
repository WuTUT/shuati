#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn=1005;
int l[maxn],w[maxn],u[maxn];
typedef long long ll;
ll f[maxn];
int main(){
    freopen("data.in","r",stdin);
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&l[i],&w[i],&u[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=x;j>=u[i];j--){
           f[j]=max(f[j-u[i]]+w[i],f[j]+l[i]);
        }
        for(int j=u[i]-1;j>=0;j--){
           f[j]=f[j]+l[i];
        }
        
    }
    printf("%lld",f[x]*5);
    return 0;