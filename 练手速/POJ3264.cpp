#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 5e4+5;
typedef long long ll;
const ll INF=1ll<<60;
ll q_max,q_min;
int ql,qr;
int a[maxn];
struct Tree{
    int l,r;
    ll maxv,minv;
    ll addv;
    void update(ll val){
        maxv+=val;
        minv+=val;
        addv+=val;
    }
}tr[maxn<<2];
inline void push_down(int x){
    if(tr[x].addv){
        tr[x<<1].update(tr[x].addv);
        tr[x<<1|1].update(tr[x].addv);
        tr[x].addv=0;
    }
}
inline void push_up(int x){
    tr[x].minv = min(tr[x<<1].minv,tr[x<<1|1].minv);
    tr[x].maxv = max(tr[x<<1].maxv,tr[x<<1|1].maxv);
}
void build(int x,int l,int r){
    tr[x].l=l,tr[x].r=r;
    tr[x].addv=0;
    if(l==r){
        tr[x].minv=tr[x].maxv=a[l];
        return;
    }
    int mid = (l+r)/2;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    push_up(x);
}
void query_i(int x){
    int l=tr[x].l;int r= tr[x].r;
    if(ql<=l&&qr>=r){
        q_max=max(q_max,tr[x].maxv);
        q_min=min(q_min,tr[x].minv);
    }
    else{
        push_down(x);
        int mid = (l+r)/2;
        if(ql<=mid) query_i(x<<1);
        if(qr>mid) query_i(x<<1|1);
        push_up(x);
    }
}
int n,m;
int main(){
    freopen("data.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&ql,&qr);
        q_min=INF,q_max=-INF;
        query_i(1);
        printf("%lld\n",q_max-q_min);
    }
    return 0;
}