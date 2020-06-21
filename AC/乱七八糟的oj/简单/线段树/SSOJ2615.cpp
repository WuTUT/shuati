#include <iostream>
#include <cstdio>
using namespace std;
const int maxn= 200000+5,INF=0x7f7f7f7f;
int ql,qr,q_set;
int q_sum;
int a[maxn];
struct Tree{
    int l,r;
    int sumv;
    int setv;
    void update_set(int val){
        setv = val;
        sumv = val*(r-l+1);
    }
}tr[maxn<<2];
int n,m;
inline void push_up(int x){
    tr[x].sumv = tr[x<<1].sumv+tr[x<<1|1].sumv;

}
inline void push_down(int x){
    if(tr[x].setv>-INF){
        tr[x<<1].update_set(tr[x].setv);
        tr[x<<1|1].update_set(tr[x].setv);
        tr[x].setv=-INF;
    }
}
void set_i(int x){
    int l= tr[x].l,r=tr[x].r;
    if(ql<=l&&qr>=r){
        tr[x].update_set(q_set);
    }
    else{
        push_down(x);
        int mid= (l+r)>>1;
        if(ql<=mid) set_i(x<<1);
        if(qr>mid) set_i(x<<1|1);
        push_up(x);
    }

}
void query_i(int x){
    int l= tr[x].l,r=tr[x].r;
    if(ql<=l&&qr>=r){
        q_sum+=tr[x].sumv;
    }
    else{
        push_down(x);
        int mid= (l+r)>>1;
        if(ql<=mid) query_i(x<<1);
        if(qr>mid) query_i(x<<1|1);
        push_up(x);
    }
}
void build(int x,int l,int r){
    tr[x].l=l,tr[x].r=r;
    tr[x].sumv=0;tr[x].setv=-INF;
    if(l==r){
        tr[x].sumv=a[l];
        
    }
    else{
        int mid = (l+r)/2;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        push_up(x);
    }
}
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int ks;
    build(1,1,n);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&ks,&ql,&qr);
        if(ks==1){
            scanf("%d",&q_set);
            set_i(1);
        }
        else{
            q_sum=0;
            query_i(1);
            printf("%d\n",q_sum);
        }   
    }
    return 0;
}