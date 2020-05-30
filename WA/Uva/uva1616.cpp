#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=100000 +5;
struct Node{
    int x;int y;
    Node():x(0),y(0){}
    Node(int x,int y):x(x),y(y){}
    bool operator <(const struct Node& r) const {
        return x<r.x || (x==r.x && y<r.y);
    }
};
int n;
struct Node a[maxn];
long double eps=1e-11;
bool judge(long double mid){
    long double cur=0.0;
    for(int i=0;i<n;i++){
        cur = max(cur,(long double)a[i].x);
        if( cur+mid - a[i].y >eps) return false;
        cur+=mid;
    }
    return true;
}
int main(){
    
    freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
        while(scanf("%d",&n)==1&&n){
            long double l,r;
            for(int i=0;i<n;i++){
                scanf("%d%d",&a[i].x,&a[i].y);
                
            }
            sort(a,a+n);
            r=a[n-1].y;
            l=0.0;
            while((r-l)>eps){
                long double mid=l+(r-l)/2;
                if(judge(mid)) {
                    l=mid;
                }else{
                    r=mid;
                }
            }
            int p,q;
            for(int i=1;i<=n+1;i++){//  1~n+1
                int tmp=round(i*l);
                if(fabs((long double)tmp/(long double)i-l)<eps){
                    p=tmp;
                    q=i;
                    break;
                }
            }
            printf("%d/%d\n",p,q);
        }
        
      return 0;    
}