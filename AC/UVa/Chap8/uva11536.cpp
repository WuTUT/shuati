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
const int maxn=1000001 +5;
int n,m,k;
int a[maxn];
int c[maxn];
int main(){
    // freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int T;scanf("%d",&T);int kase=0;
    while(T--){
        
        scanf("%d%d%d",&n,&m,&k);
         a[1]=1;a[2]=2;a[3]=3;
        for(int i=4;i<=n;i++){
            a[i]=(a[i-1]+a[i-2]+a[i-3])%m+1;
        }
        // printf("Sequence is \n");
        // for(int i=1;i<=n;i++){
        //     printf("%d ",a[i]);
        // }
        // printf("\n");
        memset(c,0,sizeof(int)*(k+1) );
        int minlen=n+1;int l=1;int num=0;bool fi=false;
        for(int i=1;i<=n;i++){
            if(a[i]<=k){
                if(c[a[i]]){
                    bool f1=false;
                    int j=l;
                    while(j<i){
                        if(a[j]>k) {l++;j++;continue;}
                        if(c[a[j]]<=1 && ((a[j]!=a[i]))){
                            f1=true;
                            break;
                        }
                        else{
                            c[a[j]]--;
                            l++;
                        }
                        j++;
                    }
                    if(f1){
                        c[a[i]]++;
                        if(num==k){
                        fi=true;
                        minlen=min(minlen,i-l+1);
                        // for(int ai=l;ai<=i;ai++){
                        //     printf("%d ",a[ai]);
                        // }
                        // printf("\n");
                        } 
                    }
                    else{
                        l++;
                        if(num==k){
                        fi=true;
                        minlen=min(minlen,i-l+2);
                        // for(int ai=l;ai<=i;ai++){
                        //     printf("%d ",a[ai]);
                        // }
                        // printf("\n");
                        } 
                    }
                    
                }
                else{
                    c[a[i]]++;
                    num++;
                    if(num==k){
                        fi=true;
                        minlen=min(minlen,i-l+1);
                        // for(int ai=l;ai<=i;ai++){
                        //     printf("%d ",a[ai]);
                        // }
                        // printf("\n");
                    } 
                }
                
            }
            else{
                continue;
            }
        }
        if(fi){
            printf("Case %d: %d\n",++kase,minlen);    
        }   
        else{
            printf("Case %d: sequence nai\n",++kase);    
        }
    }
   


    return 0;
}
//滑动窗口题
//别人的思路很简练，双指针，先移动尾指针，
/*
    int cnt = 0;
        while(e < n){ 
            while(e < n && cnt < k){
                if(!vis[a[e]] && a[e] <= k)  ++cnt;
                ++vis[a[e]];
                ++e;
            }
            if(cnt == k)  ans = min(ans, e-s);
            --vis[a[s]];
            if(!vis[a[s]] && a[s] <= k)  --cnt;
            ++s;
        }
*/