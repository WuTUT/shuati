#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=305; 
int a[2*maxn];
int l,r;int n;
inline bool isok(){
    
    for(int i=0;i<n-1;i++){
        if(a[(l+i)%n]>a[(l+i+1)%n]) return false;
    }
    return true;
}
int main(){
    
    freopen("data.in","rw",stdin);
    
    //freopen("data.out","w",stdout);
    
    scanf("%d",&n);
    while(n){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        l=0,r=n-1;
        vector<int> ops;
        while(!isok()){
            int next= (l+1)%n;
            if((a[l]==n &&a[next]==1) || a[l]<a[next]){
                ops.push_back(2);
                l=(l-1+n)%n;
            }
            else{
                int t=a[l];
                a[l]=a[next];
                a[next]=t;
                ops.push_back(1);
            }
        }    
        for(int i=ops.size()-1;i>=0;i--){
            printf("%d",ops[i]);
        }
        printf("\n");
        scanf("%d",&n);
    }
   
    return 0;
}

//抄袭之王
//消除逆序对
