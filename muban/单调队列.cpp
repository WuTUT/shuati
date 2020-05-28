#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=1000000 +5; 
int q[maxn];
int a[maxn];
int main(){
    
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int l=0,r=0;
    for(int i=0;i<n;i++){
        while(r-l>0 && a[q[r-1]]>a[i]){
            r--;
        }
        q[r++]=i;
        if(i>=k-1){
            if(i<n-1)
            printf("%d ",a[q[l]]);
            else
            printf("%d",a[q[l]]);
        }
        if(i-k+1>=q[l]) l++;
    }
    printf("\n");
    l=0,r=0;
    for(int i=0;i<n;i++){
        while(r-l>0 && a[q[r-1]]<a[i]){
            r--;
        }
        q[r++]=i;
        if(i>=k-1){
            if(i<n-1)
            printf("%d ",a[q[l]]);
            else
            printf("%d",a[q[l]]);
        }
        if(i-k+1>=q[l]) l++;
    }
    return 0;
}

//为什么要设置q存着的为a的下标？因为不然不知道什么时候该从头部出队