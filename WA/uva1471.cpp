#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;
struct Candidate{
    int a,g;
    Candidate(int a,int g):a(a),g(g){}
    bool operator < (const Candidate& rhs){
        return a<rhs.a;
    }
};
set<Candidate> s;
const int maxn=200000 +5;
int f[maxn],g[maxn];
int a[maxn];
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);  
   int T;
   scanf("%d",&T);
   while(T){
       T--;
       int n;scanf("%d",&n);
       for(int i=0;i<n;i++){
           scanf("%d",&a[i]);
       }
       if(n==1) {printf("1\n");continue;}
       g[0]=1;
       for(int i=1;i<n;i++){
           if(a[i]>a[i-1]) g[i]=g[i-1]+1;
           else g[i]=1;
       }
       f[n-1]=1;
       for(int i=n-2;i>=0;i--){
           if(a[i]<a[i]+1) f[i]=f[i+1]+1;
           else f[i]=1;
       }
       s.clear();
       s.insert(Candidate(a[0],g[0])); 
       int ans=1;
       for(int i=1;i<n;i++){
           Candidate c(a[i],g[i]);
           set<Candidate>::iterator it= s.lower_bound(c);
            bool keep = true;
           if(it!=s.begin()){
               it--;
               Candidate last=*it;
               int len=f[i]+last.g;
               ans=max(ans,len);
               if(c.g<=last.g){
                   keep=false;
               }
           }
           if(keep){
               s.erase(c);
               s.insert(c);
               it=s.find(c);
               it++;
               while(it!=s.end()){
                   if(it->a > c.a && it->g<=c.g){
                       s.erase(it);
                       it++;
                   }
               }
           }
       } 
   }
    return 0;
}