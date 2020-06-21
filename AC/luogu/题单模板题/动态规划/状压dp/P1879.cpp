#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
const int maxn = 14,maxs =400;
int g[maxn];
int n,m;
int state[maxs];
int top;
typedef long long ll;
ll f[maxn][maxs];
int main(){
    freopen("data.in","r",stdin);
    cin >> m >> n;
    int ch;int si = 1<<n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&ch);
            g[i]<<=1;
            if(ch==0){
                g[i]+=1;
            }
        }
        
    }
    
    for(int j=0;j<si;j++){
        if( (j&(j<<1))==0 && (j&(j>>1))==0 ){
            state[++top]=j;
            
        }
    }
    //cout << top <<endl;
    int sj,sk;
    for(int j=1;j<=top;j++){

        sj = state[j];
        if( (sj&g[1])==0 )
            f[1][j]=1;
    }
    for(int i=2;i<=m;i++){
        for(int j=1;j<=top;j++){
            sj = state[j];
            for(int k=1;k<=top;k++){
                sk = state[k];
                
                if( (sj&sk)==0 && (sj&g[i])==0 && (sk&g[i-1])==0  ){
                    //cout << bitset<3>(sj) <<" "<<bitset<3>(sk)<<endl;
                    f[i][j]+=f[i-1][k];
                }
            }
        }
    }
    
    ll ans=0;
    for(int i=1;i<=top;i++){
        ans = (ans+f[m][i])%100000000;
    }
    cout  << ans <<endl;
    return 0;
}