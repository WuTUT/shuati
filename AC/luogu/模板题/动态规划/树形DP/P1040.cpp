#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn= 32;
typedef long long ll;
int a[maxn];
ll f[maxn][maxn];
bool isvis[maxn][maxn];
int ro[maxn][maxn];
int lt[maxn];
int rt[maxn];
int n;
void dfs(int l,int r){
    
    if(isvis[l][r]) return;
    isvis[l][r]=true;
    int len=r-l+1;
    if(l>r){
        f[l][r]=1;
        return ;
    }
    if(len==1){
        f[r][r]=a[r];
        ro[r][r]=r;
        return;
    }
    if(len==2){
        rt[l]=r;
        f[l][r]=a[l]+a[r];
        f[r][r]=a[r];
        ro[l][r]=l;
        return ;
    }
    ll ans=0;int root=0;
    for(int i=l;i<=r;i++){
        dfs(l,i);dfs(i+1,r);
        ll tmp=f[l][i-1]*f[i+1][r]+a[i];
        if(tmp>=ans){
            root = i;
            ans=tmp;
        } 
    }
    ro[l][r]=root;
    lt[root]=ro[l][root-1];
    rt[root]=ro[root+1][r];
    f[l][r]=ans;
    return ;
}
void print(int l,int r){
    if(ro[l][r])// 为什么要加这一句呢，似乎没有root=0的情况？
        cout<<ro[l][r]<<" ";
    if(l==r) return;
    if(lt[ro[l][r]]) print(l,ro[l][r]-1); 
    if(rt[ro[l][r]]) print(ro[l][r]+1,r);
}
int main(){
    freopen("data.in","r",stdin);
    
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    dfs(1,n);
    cout << f[1][n]<<endl;
    print(1,n);
}