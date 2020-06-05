#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e4+5,INF=0x7f7f7f7f;
struct duty{
    int p;int t;
    duty(){}
    duty(int p,int t):p(p),t(t){}
    bool operator <(const struct duty& rhs)const {
        if(p<rhs.p || (p==rhs.p && t<rhs.t)) return false;
        return true;
    }
}d[maxn];
int f[maxn],isdu[maxn];
int main(){
    freopen("data.in","r",stdin);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=k;i++){
        scanf("%d",&(d[i].p));
        scanf("%d",&(d[i].t));
        isdu[d[i].p]=1;
    }
    sort(d+1,d+1+k);int cur=1;
    
    for(int i=n;i>=1;i--){
        if(isdu[i]==0) f[i]=f[i+1]+1;
        else{
            for(int j=cur;j<=k;j++)
                if(d[j].p==i){
                    f[i]=max(f[i],f[i+d[j].t]);
                    cur=j;
                }
                else if(d[j].p<i){
                    break;
                } 
            
        }
    }
    cout << f[1]<<endl;

    //cout << n-f[k] <<endl;
}

//没做对