#include <iostream>
#include <cstdio>
using namespace std;
double a,b;
int n;
int main(){
    freopen("data.in","r",stdin);
    cin >> n;
    int ai,bi;
    for(int i=1;i<=n;i++){
        scanf("%d",&ai);
        a+=ai;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&bi);
        b+=bi;
    }
    double ans = (3.0*a-2.0*b)/(a-b);
    printf("%.6lf\n",ans);
    return 0;
}
