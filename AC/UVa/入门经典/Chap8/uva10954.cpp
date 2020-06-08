#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int n;
       
    scanf("%d",&n);
    while(n){ 
        int a;
         priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            pq.push(a);
        }
        long long ans=0;
        for(int i=0;i<n-1;i++){
           int x1= pq.top();
           pq.pop();
           int x2=pq.top();
           pq.pop();
           ans+=x1+x2;
           pq.push(x1+x2);
        }
        printf("%lld\n",ans);
        scanf("%d",&n);
    }  
    
   
   
    return 0;
}

