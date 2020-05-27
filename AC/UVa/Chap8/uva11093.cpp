#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
using namespace std;
const int maxn=100004;
int a[maxn];
int main(){
    
     freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int kase=0;int T;
    scanf("%d",&T);
    while(T){
        T--; 
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int b;
        for(int i=0;i<n;i++){
            scanf("%d",&b);
            a[i]-=b;
        }
        long long sum=0;
        int ans=0;
        int i=0;
        int count=0;
        bool cir=false;
        
        for(int i=0;i<n;i++){
           // printf("%d  ",i);
            sum=0;
            for(count=0;count<n;count++){
                if(sum+a[(i+count)%n]>=0){
                    sum+=a[(i+count)%n];
                }else{
                    i=i+count;
                    break;
                }
            }
            if(count==n){
                cir=true;
                ans=i;
                break;
            }
        }
        //printf("\n");
        if(cir){
            printf("Case %d: Possible from station %d\n",++kase,(ans+1));
        }    
        else{
            printf("Case %d: Not possible\n",++kase);
        }
    }
    

    return 0;    
}