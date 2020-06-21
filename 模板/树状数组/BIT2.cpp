#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 5e5+5;
int n,m;
int tr[maxn];
void add(int x,int k){
    for(;x<=n;x+=x&-x){
        tr[x]+=k;
    }
}

int ask(int x){
    int ans = 0;
    for(;x;x-=x&-x){
        ans += tr[x];
    }
    return ans;
}

int a[maxn];
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        
    }
    int x,y,ks,k;
    for(int i=1;i<=m;i++){
        scanf("%d",&ks);
        if(ks==1){
            scanf("%d%d%d",&x,&y,&k);
            add(x,k);
            add(y+1,-k);
        }
        else{
            scanf("%d",&x);
           
            printf("%d\n", a[x]+ask(x));
        }
    }
    return 0;
}
//区间add 单点ask