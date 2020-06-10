#include <iostream>
#include <cstdio>
using namespace std;
int n;
const int maxn =1e6+5;
int root;
int lt[maxn];
int rt[maxn];
int dfs(int root){
    if(!lt[root] && !rt[root]) return 1;
    
    int l=0,r=0;
    if(lt[root]) l=dfs(lt[root]);
    if(rt[root]) r=dfs(rt[root]); 
    
    return max(l,r)+1;
}
int main(){
    freopen("data.in","r",stdin);
    cin >> n;
    for(int i=1;i<=n;i++){
       cin >>  lt[i] >> rt[i];
    }
    
    cout << dfs(1) <<endl;
    return 0;
}