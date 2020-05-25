#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
int n;
int kase;
int ans[18];
int isvis[18];
int prime[34];
void setprime(){
    for(int i=2;i<33;i++){
        int tmp=floor(sqrt(i)+0.5);
        int flag=1;
        for(int j=2;j<=tmp;j++){
            if(i%j==0){
                flag=0;
                break;
            }
        }
        if(flag) prime[i]=1;
    }
    // for(int i=0;i<34;i++){
    //     if(prime[i]==1) printf("%d ",i);
    // }
}
void dfs(int ni){
    if(ni==n && prime[ans[ni-1]+ans[0]]){
        
        printf("1");
        for(int i=1;i<n;i++){
            printf(" %d",ans[i]);
        }
        printf("\n");
        
        
        return;
    }
    for(int i=2;i<=n;i++){
        if(!isvis[i]){
            if(prime[ans[ni-1]+i]){
                ans[ni]=i;
                isvis[i]=1;
                dfs(ni+1);
                isvis[i]=0;
            }
        }
    }
    
}
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout); 
   kase=0;  
   setprime();
   while(scanf("%d",&n)==1&& n){
       if(kase) printf("\n");
       memset(isvis,0,sizeof(isvis));
       isvis[1]=1;
       ans[0]=1;
       printf("Case %d:\n",++kase);
       dfs(1);
       
   }

   
   return 0;
}