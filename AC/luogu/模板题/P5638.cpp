#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
const int maxn=1000005;
long long a[maxn];
long long S[maxn];
int main(){
   freopen("data.in","r",stdin);
    int n,k;scanf("%d%d",&n,&k);
    S[0]=0;
    for(int i=1;i<n;i++){
        scanf("%lld",&a[i]);
        S[i]=S[i-1]+a[i];
    }
    long long maxk=0;
    for(int i=0;i<n;i++){
        int j=i+k;j=min(j,n-1);
        maxk=max(maxk, S[j]-S[i]);
    }   
    long long ans=S[n-1]-maxk;
    printf("%lld",ans);
    

}

//居然是a数组没有long long 和题目不符合啊
//前缀和模板