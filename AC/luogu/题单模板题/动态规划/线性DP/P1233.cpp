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
    f[1]=r[a[1]];int len=1;
    
    for(int i=2;i<=n;i++){
        if(r[a[i]]>f[len]) f[++len]=r[a[i]];
        else f[lower_bound(f+1,f+len+1,r[a[i]])-f]=r[a[i]];//第一次写错了是f+len+1不是f+i+1
    }
    cout <<len<<endl;
    return 0;
}
//Diworth定理+O(nlogn) 的LIS +排序 ：为什么要排序 ，这样可以使得下降的序列最少  （2）一定要从大到小排序