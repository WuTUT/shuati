#include <iostream>
#include <cstdio>
#include <bitset>
#include <cassert>
using namespace std;
const int maxn = 100005,maxk = 16;
typedef long long ll;

int dp[1<<maxk];
int k,n;
int a[maxn];
int w[maxk];
ll su[maxn];

ll cnt;
    

int main(){
    freopen("data.in","r",stdin);
    cin >> k >>n;
    for(int i=1;i<=k;i++){
        scanf("%d",&w[i]);
        cnt+=w[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        su[i]=su[i-1]+a[i];
    }
    int sj = 1<<k;
    int lj;
    ll ans =-1;    
    
    for(int i=1;i<sj;i++){//枚举000 001 010 100 011 101 110 111 可以这样
        for(int j=0;j<k;j++){
            if(i&(1<<j)){
                lj= i^(1<<j);
                int le=dp[lj],ri=n;
                while(le<ri){
                    int mid = (le+ri)/2;
                    if(w[j+1]<su[mid]-su[dp[lj]]){
                        ri=mid;
                    }
                    else{
                        le = mid+1;
                        //tt= mid;
                    }

                }
                if(w[j+1]<su[le]-su[dp[lj]]) le--;//我的二分是有问题的，这种情况可能会偏靠r l+1 == r退出。但此时未必l+1就能满足条件
                
                if(le>dp[i]){
                   
                    dp[i]=le;
                    
                }
                if(dp[i]== n){
                    int tmp = 0;
                    for(int q=0;q<k;q++){
                        if(i&(1<<q)) tmp+=w[q+1];
                    }
                    ans = max(ans,cnt-tmp);
                }
            }
        }

    }
    
    
    
    
    cout << ans<<endl;
    return 0;
}