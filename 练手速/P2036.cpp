#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n;
const int maxn = 13;
int a[maxn],b[maxn];
int ans=0x7fffffff;

void dfs(int ind,int sum1,int sum2,bool no){
    if(ind == n+1){
        if(no)
        {
            int tmp =abs(sum1-sum2);
            if(tmp<ans) ans = tmp; 
            
        }
        else if(ind == 2){
            ans = abs(a[1]-b[1]);
        }
        return;
    }
    
    
    
    dfs(ind+1,sum1*a[ind],sum2+b[ind],true);
    
    dfs(ind+1,sum1,sum2,no);
    return;
}
int main(){
    freopen("data.in","r",stdin);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }
    
    dfs(1,1,0,false);
    cout << ans<<endl;
}