#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
const int maxn=30;
int s[maxn];
int sorts[maxn];
int n=0;
void solve(){
    for(int i=n-1;i>=0;i--){
        
        int pan_i=find(s,s+i+1,sorts[i])-s;
        if(pan_i== i) continue;
        if(pan_i!=0){
            printf("%d ",n-pan_i);
            reverse(s,s+pan_i+1);
        }
        printf("%d ",n-i);
        reverse(s,s+i+1);
        
    }
}
int main(){
   //  freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);  
   string line;
   
   while(getline(cin,line)){
       n=0;
       stringstream ss(line);
       while(ss>>s[n]){n++;}
       for(int i=0;i<n;i++){
           if(i!=n-1)
           printf("%d ",s[i]);
           else
           {
               printf("%d",s[i]);
           }
           
       }
       printf("\n");
       memcpy(sorts,s,sizeof(sorts));
       sort(sorts,sorts+n);
       solve();  
        printf("0\n");
   }
   return 0;

}
