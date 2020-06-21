#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n,m;
const int maxn= 21;
int a[maxn];
int has[maxn];
int f[2002];
bool ok;
int cnt;
int sum ;
int maxcnt;
void dfs(int id,int sle){
    
    if(sle == m && id == n+1){
       // cout << id <<" "<<sle << " ziji L: ";
       //for(int i=1;i<=n;i++){
       //    cout << has[i] <<" ";
       //}
       //cout <<endl;
        memset(f,0,sizeof f);

        f[0]=1;
        for(int i=1;i<=n;i++){
            if(has[i]){
                for(int j=sum;j>=a[i];j--){
                    f[j]=max(f[j],f[j-a[i]]);
                }
            }
        }
        cnt = 0;
        for(int i=1;i<=sum;i++) {
            
       //     cout << f[i]<<" ";
            if(f[i])
                cnt++;    
        }
       // cout << cnt <<endl;
        maxcnt = max(cnt, maxcnt);
    }
    if( (sle > m) || (id>n) ) return;
    dfs(id+1,sle);
    has[id]=1;
    dfs(id+1,sle+1);
    has[id]=0;
    return ;
}
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    m=n-m;
    dfs(1,0);
    cout << maxcnt;
    return 0;
}