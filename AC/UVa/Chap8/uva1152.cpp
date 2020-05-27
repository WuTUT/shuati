#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int,int> m1;
const int maxn=4005;
int a[maxn],b[maxn],c[maxn],d[maxn];
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);  
   int T;
   scanf("%d",&T);
   while(T){
       T--;
       
       int n;scanf("%d",&n);
       for(int i=0;i<n;i++){
           scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
       }
       
       m1.clear();
      
       for(int i=0;i<n;i++){
           for (int j = 0; j < n; j++)
           {
               m1[a[i]+b[j]]++;
           }
           
       }
       int ans=0;
       for(int i=0;i<n;i++){
           for (int j = 0; j < n; j++)
           {
               ans+=m1[-(c[i]+d[j])];
           }
           
       }  
       //cout<<ans<<endl;
       printf("%d\n",ans);
       if(T) printf("\n");
   }
    return 0;
}