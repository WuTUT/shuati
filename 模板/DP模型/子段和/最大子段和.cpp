#include <iostream>
#include <cstdio>
using namespace std;
const int maxn  =2e5+5; 
int a;
int f[maxn];
int n,ans;
int main(){
    freopen("data.in","r",stdin);
    cin >> n;
    
    cin >> ans;
    f[1]=ans;
    for(int i=2;i<=n;i++){
        cin >> a;
        f[i]=a;
        if(f[i-1]>0) f[i]+=f[i-1];
        ans = max(f[i],ans);
    }
    cout << ans<<endl;
    return 0;
}
//P1115 最大连续子段和
//既然是连续，那么我们不能定义前i个而是定义以i结尾
//而且无法用单调队列之类的优化
//f[i]=max(f[i-1],0)+a[i];