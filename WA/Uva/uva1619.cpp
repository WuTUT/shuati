#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
const int maxn=100000 +5;
int n;
int a[maxn];
long long S[maxn];
int L[maxn];int R[maxn];
stack<int> s;
int main(){
    
    freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int kase=0;
    while(scanf("%d",&n)==1&&n){
            while(s.size()) s.pop();
            S[0]=0;
            for(int i=1;i<=n;i++){
                scanf("%d",&a[i]);
                S[i]=S[i-1]+a[i];
            }
            memset(L,0,sizeof(L));
            memset(R,0,sizeof(R));
            for(int i=1;i<=n;i++){
                while(!s.empty() &&a[s.top()]>=a[i] ) s.pop();
                if(s.empty()) L[i]=0;
                else L[i]=s.top()+1;

                s.push(i); 
            }
            while(s.size()) s.pop();
            for(int i=n;i>0;i--){
                while(!s.empty()&&a[s.top()]>=a[i]) s.pop();
                if(s.empty()) R[i]=0;
                else R[i]=s.top()-1;
                s.push(i);
            }
        
           long long x=-1;int ansl=1,ansr=1;
            if(n!=1){
                for(int i=1;i<=n;i++){
                    int lid=L[i];int rid=R[i];
                    if(lid==0) lid=1;
                    if(rid==0) rid=n;
                    if( (S[rid]-S[lid-1])*a[i]>x ){
                        x=(S[rid]-S[lid-1])*a[i];
                        ansl=lid;
                        ansr=rid;
                    }else if( (S[rid]-S[lid-1])*a[i]==x ) {
                        if(ansr-ansl >rid-lid || ( (ansr-ansl ==rid-lid)&& ansl>lid) ){
                            ansl=lid;
                            ansr=rid;
                        }
                    }
                }
            }else{
                x=a[1];ansr=ansl=1;
            }
            
            if(kase==0){
                printf("%lld\n%d %d\n",x,ansl,ansr);
                kase++;
            }
            else{
                printf("\n%lld\n%d %d\n",x,ansl,ansr);
            }
        }
        
      return 0;    
}

//....各种强凑边界条件终于ac了