#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 3e3+5;
int a[maxn];
int minf,sum ;
int n,m;
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        minf+=a[i];
    }
    sum=minf;
    for(int i=2;i<=n-m+1;i++){
        sum = sum -a[i-1]+a[i+m-1];
       minf = min(sum,minf);
    //   cout << minf <<endl;
    }
    cout << minf <<endl;
    return 0;
}