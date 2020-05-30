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
struct Node{
    int r;int d;
    Node(){}
    Node(int r,int d):r(r),d(d){}
    bool operator <(const struct Node& rh)const {
        return d<rh.d ||(d==rh.d && r<rh.r);
    }
};
struct Node a[maxn];
int main(){
    
    freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i].r,&a[i].d);
        }
        sort(a+1,a+n+1);
        int ans=0;
        int cur= a[1].d;

        for(int i=2;i<=n;i++){
            if(a[i].d==cur){
                continue;
            }
            if(a[i].r>cur){
                ans++;
                cur=a[i].d;
            }
            else
                cur++;
        }
        printf("%d\n",ans);
    }
         return 0;    
}
