#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int s[20];
int main(){
   // freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
   int n;
  int kase=0;
   while(scanf("%d",&n)==1){
       
       for(int i=0;i<n;i++){
           scanf("%d",&s[i]);
        }
        long long maxres=0;
        for(int start=0;start<n;start++){
            long long res=s[start];
            maxres=max(maxres,res);
            for(int end=start+1;end<n;end++){
                    
                    res*=s[end];
                    maxres=max(maxres,res);
            }
            
        }
        
        printf("Case #%d: The maximum product is %lld.\n\n",++kase,maxres);
   }
   
    return 0;
}