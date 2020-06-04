#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn=5005;
int n;
int l[maxn];
int r[maxn];
bool cmp(int x,int y){
    //if(l[x]<l[y] && r[x]<r[y]) return false; //wrong
    if(l[x]<l[y] ) return false; //?>>>?
    else if(l[x]==l[y] && r[x]<r[y]) return false;
    else return true;
}
int a[maxn];
int f[maxn];
int main(){
    freopen("data.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&l[i]);
        scanf("%d",&r[i]);
        a[i]=i;
    }
    sort(a+1,a+1+n,cmp);
    int ans=0;
    for(int i=1;i<=n;i++){
        f[i]=1;
        for(int j=1;j<i;j++){
            if(r[a[i]] > r[a[j]])
              f[i]=max(f[i],f[j]+1);   
        }
        ans=max(ans,f[i]);
    }
    cout <<ans<<endl;
    return 0;
}
