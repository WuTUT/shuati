#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 10,maxk = 85;
const int maxst= 92;
//long long f[maxn][maxst][maxk];
long long f[2][maxst][maxk];
int KK,n;

int cnt[maxst];
int state[maxst];
int top;
inline int cnt2(int j){
    int sum=0;
    while(j){
        if(j&1) sum++;
        j>>=1;
    }
    return sum;
}
int main(){
    freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
    cin >> n>>KK;
    int si = 1<<n;
    for(int j=0;j<si;j++){
        if( (j&(j<<1))==0 && (j&(j>>1))==0 ){
            state[++top]=j;
            cnt[top]=cnt2(j);
        }
    }
    //cout << top;
    int sj,sk;
    for(int j=1;j<=top;j++){
        sj = state[j];
        f[1][j][cnt[j]]=1;
    }
    int i1,i2;
    for(int i=2;i<=n;i++){
        i1 = i%2;
        i2 = i1^1;
        //cout << i1 <<" "<<i2<<endl; 
        for(int j=1;j<=top;j++)
            for(int l=KK;l>=0;l--)
                f[i1][j][l]=0;
        for(int j=1;j<=top;j++){
                sj = state[j];
            for(int k=1;k<=top;k++){
                sk = state[k];
                if( (sj&sk)==0 && ((sj<<1)&sk)==0 && ((sj>>1)&sk)==0  ){
                    for(int l=KK;l>=0;l--){
                        f[i1][j][l]+=f[i2][k][l-cnt[j]];
                        //f[i][j][l]+=f[i-1][k][l-cnt[j]];
                        //cout << f[i1][j][l]<<endl;
                    }
                }
            }
        }
    }
    long long ans=0;
    i1=n%2;
    for(int j=1;j<=top;j++){
        ans+=f[i1][j][KK];
        //ans+=f[n][j][KK];
    }
    cout << ans;
}
//用2个代替N个时候0/1，优化空间的时候要初始化呀！！！！！！