#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=105;
int a[maxn];
int f[maxn],g[maxn];

int main(){ 
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=1;
        for(int j=1;j<i;j++){
            if(a[i]>a[j]) f[i]=max(f[i],f[j]+1);        
        }
    }
    // for(int i=1;i<=n;i++) cout<<f[i]<<" ";
    // cout <<endl;
    g[n]=1;
    for(int i=n-1;i>=1;i--){
        g[i]=1;
        for(int j=n;j>i;j--){
            if(a[i]>a[j]) g[i]=max(g[i],g[j]+1);        
        }
    }
    // for(int i=1;i<=n;i++) cout<<g[i]<<" ";
    // cout <<endl;
    int maxlen=0;
    for(int i=1;i<=n;i++){
        maxlen=max(maxlen,g[i]+f[i]-1);
    }
    cout << n-maxlen<<endl;
    return 0;
}