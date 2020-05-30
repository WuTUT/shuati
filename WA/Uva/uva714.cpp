#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int maxn=505;
int a[maxn];
int id[maxn];
int m,k;
bool solve(ll mid){
    //cout<<"mid  "<<mid<<endl;
    
    int kmid=1;
    ll sum=0;
    for(int i=m-1;i>=0;i--){
        if(sum+a[i]>mid){
            sum=a[i];
            kmid++;
        }else{
            sum+=a[i];
        }
        if(kmid>k) return false;
    }
  //  if(sum>mid) return false;
     
    //cout<<"kmid  "<<kmid<<endl;
    if(kmid<=k) return true;
    else return false;
}
void print(ll mid){
    //printf("%lld\n",mid);
    ll sum=0;
    memset(id,0,sizeof(id));
    int k_id=1;
    bool f1=false;
    for(int i=m-1;i>=0;i--){
        if((k-k_id)>i) {f1=true;break;}
        if(sum+a[i]>mid){
            id[i]=1;
            k_id++;
            sum=a[i];
        }else{
            sum+=a[i];
        }
    }
    if(f1){
        memset(id,1,sizeof(int)*(k-k_id));
    }
    bool first=true;
    for(int i=0;i<m;i++){
        if(first){
            printf("%d",a[i]);
            first=false;
        }
        else{
            printf(" %d",a[i]);
        }
        if(id[i]){
            printf(" /");
        }
    }
    printf("\n");
}
int main(){
    
   // freopen("data.in","r",stdin); 
   // freopen("data.out","w",stdout);
    int T;
    scanf("%d",&T);
    
    while(T){
        T--;
        
        ll sum=0;
        ll l=-1,r=0;
        scanf("%d%d",&m,&k);
        for(int i=0;i<m;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
            if(l < a[i]) l = a[i];
        }
        r=sum;
       
        while(l<r){
            ll mid=l+(r-l)/2;
            if(solve(mid)){
                r=mid;
            }
            else{
                l=mid+1;
            }
           // cout<<"l "<<l<<" r "<<r<<endl;
        }
        // printf("l=%d\n",l);
       
       print(l);
        
    }   
    return 0;
}