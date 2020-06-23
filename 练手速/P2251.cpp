#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 1000000+5;
int st[maxn][21];
int n,m;
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        scanf("%d",&st[i][0]);
    }
    for(int j=1;j<21;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
    int len = int(log(m)/log(2)); int binlen = 1<<len;
    for(int i=1;i<=n-m+1;i++){
        printf("%d\n",min(st[i][len],st[i+m-binlen][len]));
    }
    return 0;
}