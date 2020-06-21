#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int a[maxn],b[maxn];
int ha[maxn],dp[maxn];
int main(){
    freopen("data.in","r",stdin);
    int n;cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt++;
        ha[a[i]]=cnt;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        b[i]=ha[b[i]];
    }
    int len=1; dp[1]=b[1];
    for(int i=2;i<=n;i++){
        if(dp[len]<b[i]){
            dp[++len]=b[i];
        }
        else{
            dp[upper_bound(dp,dp+len,b[i])-dp]=b[i];
        }
    }
    cout<<len<<endl;
    return 0;
}

//秒啊
/*
关于为什么可以转化成LCS问题，这里提供一个解释。

A:3 2 1 4 5

B:1 2 3 4 5

我们不妨给它们重新标个号：把3标成a,把2标成b，把1标成c……于是变成：

A: a b c d e
B: c b a d e

这样标号之后，LCS长度显然不会改变。但是出现了一个性质：

两个序列的子序列，一定是A的子序列。而A本身就是单调递增的。
因此这个子序列是单调递增的。

换句话说，只要这个子序列在B中单调递增，它就是A的子序列。

哪个最长呢？当然是B的LIS最长。

自此完成转化。

https://www.luogu.com.cn/problem/solution/P1439

*/