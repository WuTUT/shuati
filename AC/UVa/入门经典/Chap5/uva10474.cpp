#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=10000;
int main(){
   // freopen("data.in","r",stdin);
    int n,q;
    int a[10000];
    int kase=0;
    while(scanf("%d%d",&n,&q)==2 && n){
        cout<<"CASE# "<<++kase<<":"<<endl;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        int m;int num;
        for(int i=0;i<q;i++){
            scanf("%d",&m);
            num=lower_bound(a+1,a+n+1,m)-a-1;
            if(a[num+1]==m){
                cout<<m<<" found at "<<num+1<<endl;
            }
            else{
                cout<<m<<" not found"<<endl;
            }
            
        }
    }
    
    return 0;
}