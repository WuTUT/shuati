#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=16390; 
int a[maxn][3];int n;
int cal(int order,int ach,bool less){
    
    int ans=-1;
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            for(int k=0;k<=1;k++){
                int tmp=i*a[order][0]+j*a[order][1]+k*a[order][2];
                if(less){
                    if(tmp<=ach){
                        ans=max(ans,tmp);
                    }
                }else{
                    if(tmp<ach){
                        ans=max(ans,tmp);
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    
 //   freopen("data.in","rw",stdin);
    
 //   freopen("data.out","w",stdout);
    int kase=0;
    scanf("%d",&n);
    while(n){
        double readn;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                scanf("%lf",&readn);
                a[i][j]=round(readn * 100.0);
            }
        }
        int order;int last=-1;int lorder=0;bool sol=true;
        for(int i=1;i<=n;i++){
            scanf("%d",&order);
            if(sol){
                if(last==-1){
                    last=0;
                for(int j=0;j<3;j++){
                    last+=a[order][j];
                }
                lorder=order;
                }else{
                    int next=0;
                    if(lorder<order){
                        next= cal(order,last,true);
                    }else{
                        next= cal(order,last,false);
                    }
                    if(next==-1){ 
                        // cout<<"Last "<<last<<" Next "<<next<<endl;cout<<"I: "<<i<<endl;  
                        // cout<<"Lorder "<<lorder<<" order"<<order<<endl;
                        sol=false;
                    }
                    //cout<<"Last "<<last<<" Next "<<next<<endl;
                    last=next;lorder=order;
                }
            }
            
        }
        if(sol)
        printf("Case %d: %.2f\n",++kase,(double)last/100.0);
        else{
        printf("Case %d: No solution\n",++kase);    
        }
        scanf("%d",&n);
    }
   
    return 0;
}

//浮点精度问题