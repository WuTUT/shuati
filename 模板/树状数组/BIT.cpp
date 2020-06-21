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


int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    int a;
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        add(i,a);
    }
    int x,y,ks;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&ks,&x,&y);
        if(ks==1){
            add(x,y);
        }
        else{
            
           
            printf("%d\n", ask(y)-ask(x-1));
        }
    }
    return 0;
}
//单点add 区间ask
//树状数组 O(n) 空间
//单点 区间都是O(logn)