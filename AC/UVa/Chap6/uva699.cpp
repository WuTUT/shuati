#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN= 25000;
int be,en;
int ans[MAXN];
void build(int x,int pos){
    if(x==-1) return;
    int l,r;
    ans[pos]+=x;
    be=be>pos?pos:be;
    en=en<pos?pos:en;
    scanf("%d",&l);  
    build(l,pos-1);
    scanf("%d",&r);
    build(r,pos+1);
    return;
}
int main(){
   // freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
    int x;
    int kase=0;
    while(1){
        if(scanf("%d",&x)!=1)
        {
            cout<<endl;
            return 0;
        }
        memset(ans,0,sizeof(ans));
        int pos=MAXN/2;
        be=en=pos;
        build(x,pos);
        if(x!=-1){
            if(kase==0){
                printf("Case %d:\n",++kase);
            }
            else{
                printf("\nCase %d:\n",++kase);
            }
            for(int i=be;i<=en;i++){
                if(i==be){
                    cout<<ans[i];
                }
                else{
                    cout<<" "<<ans[i];
                }
            }
            cout<<endl;
        }
        
    }
    return 0;
}
