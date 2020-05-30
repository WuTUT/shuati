#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;

const int maxn=200000 +5;
int a[maxn];
int n;
map<int,int> lmap,nmap;
int Last[maxn],Next[maxn];
bool unique(int i, int l,int r){
    
    return (Last[i]<l && Next[i]>r);
            
    
}

bool check(int l,int r){
    //printf("%d %d\n",l,r);
    if(l>=r) return true;
    int d=0;
    while(l+d<=r-d){
        if(unique(l+d,l,r)){
            return check(l+d+1,r)&&check(l,l+d-1);
        }
        if(l+d==r-d) break;//Important
        if(unique(r-d,l,r)){
            return check(l,r-d-1)&&check(r-d+1,r);
        }
        d++;
    }
    return false;//Important
}
int main(){
    
    //freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T){
        T--;  
        scanf("%d",&n);
      
        lmap.clear();
        nmap.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(!lmap.count(a[i])){
                Last[i]=-1;
                
            }
            else{
                Last[i]=lmap[a[i]];
            }
            lmap[a[i]]=i;
        }
        for(int i=n-1;i>=0;i--){
            if(!nmap.count(a[i])){
                Next[i]=n+1;
            }
            else{
                Next[i]=nmap[a[i]];
            }
            nmap[a[i]]=i;
        }
        // for(int i=0;i<n;i++){
        //     printf("%d ",Last[i]);
        // }
        // printf("\n");
        // for(int i=0;i<n;i++){
        //     printf("%d ",Next[i]);
        // }
        // printf("\n");
        int l=0,r=n-1;
        bool boring = check(l,r);
        
        if(!boring){
            printf("boring\n");
        }
        else{
            printf("non-boring\n");
        }
    }
    

    return 0;    
}
