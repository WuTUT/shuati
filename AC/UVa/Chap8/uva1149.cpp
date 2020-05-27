#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;
const int maxn=100000 +5;
int a[maxn];
int n;int len;
int main(){
    
    //freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T){
        T--;  
        scanf("%d%d",&n,&len);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int l=0,r=n-1;
        int bags=0;
        while(l<r){
            int sum=a[l]+a[r];
            if(sum>len){
                bags++;
                r--;
            }
            else{
                l++;r--;
                bags++;
            }
        }
        if(l==r) bags++;
        printf("%d\n",bags);
        if(T) printf("\n");
    }
    

    return 0;    
}