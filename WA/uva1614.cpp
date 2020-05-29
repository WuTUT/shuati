#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include <cstring>
using namespace std;
const int maxn=100000 +5;

struct Node{
    int x;
    int id;
};
typedef struct Node Num;
bool cmp(Node x,Node y){
    return x.x>y.x;
}

int isvis[maxn];
Num a[maxn];
int main(){
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int n;
    while(cin>>n){
        long long sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].x);
            a[i].id=i;
            sum+=a[i].x;
        }
        memset(isvis,0,sizeof(int)*(n+1));
        bool ok=false;
        if(sum%2==0) ok=true;
        if(ok){
            ok=false;
            sort(a+1,a+n+1,cmp);
            long long cur=0;
            for(int i=1;i<=n;i++){
                if(cur+a[i].x < sum/2){
                    cur+=a[i].x;
                    isvis[a[i].id]=1;
                }else if(cur+a[i].x == sum/2){
                    cur+=a[i].x;
                    isvis[a[i].id]=1;
                    ok=true;
                    break;
                }
            }
        }
        if(ok){
            printf("Yes\n");
            bool first=true;
            for(int i=1;i<=n;i++){
                if(first){
                    if(isvis[i]) printf("1");
                    else printf("-1");
                    first=false;
                }
                else{
                    if(isvis[i]) printf(" 1");
                    else printf(" -1");
                } 
                
            }
            printf("\n");
        }
        else{
            printf("No\n");
        }
    }

    return 0;
}