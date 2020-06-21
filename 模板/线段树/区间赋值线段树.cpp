#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 21,maxc = 1e5+5,INF = 0x7fffffff;
int qr1,qr2,ql1,ql2;int q_add,q_set;
int q_sum,q_max,q_min;
int r,c,m;
struct Tree{
    int l,r;
    int addv,setv;
    int sumv,minv,maxv;
    void update(int val){
        addv += val;
        minv += val;
        maxv += val;
        sumv += val*(r-l+1);
    }
    void update_set(int val){
        setv = val;
        addv = 0;
        minv = val;
        maxv = val;
        sumv = val*(r-l+1);
    }
}tr[maxn][maxc*4];
inline void push_up(int x,int row){

    tr[row][x].sumv = tr[row][x<<1].sumv + tr[row][x<<1|1].sumv;
    tr[row][x].minv = min(tr[row][x<<1].minv,tr[row][x<<1|1].minv);
    tr[row][x].maxv = max(tr[row][x<<1].maxv,tr[row][x<<1|1].maxv);

}
inline void push_down(int x,int row){
    int lc = x<<1;int rc = x<<1|1;
    if(tr[row][x].setv>=0){
        tr[row][lc].update_set(tr[row][x].setv);
        tr[row][rc].update_set(tr[row][x].setv);
        tr[row][x].setv=-1;
    }
    if(tr[row][x].addv){
        tr[row][lc].update(tr[row][x].addv);
        tr[row][rc].update(tr[row][x].addv);
        tr[row][x].addv=0;
    }
}
void build(int x,int l,int r,int row){
    tr[row][x].l = l,tr[row][x].r =r;
    tr[row][x].addv=0;tr[row][x].setv=-1;
    tr[row][x].sumv=0;
    if(l==r){
        tr[row][x].sumv=0;
        tr[row][x].maxv=tr[row][x].minv=0;
    }
    else{
        int mid= (l+r)/2;
        build(x<<1,l,mid,row);
        build(x<<1|1,mid+1,r,row);
        push_up(x,row);
    }
}
void query_i(int x,int row){
    int l = tr[row][x].l;int r = tr[row][x].r;
    if(qr1<=l&&qr2>=r){
        q_sum+=tr[row][x].sumv;
        q_min=min(q_min,tr[row][x].minv);
        q_max=max(q_max,tr[row][x].maxv);
    }
    else{
        push_down(x,row);
        int mid = (l+r)/2;
        if(qr1<=mid) query_i(x<<1,row);
        if(qr2>mid) query_i(x<<1|1,row);
        push_up(x,row);
    }
}
void add_i(int x,int row){
    int l = tr[row][x].l;int r = tr[row][x].r;
    if(qr1<=l&&qr2>=r){
        tr[row][x].update(q_add);
    }
    else{
        push_down(x,row);
        int mid = (l+r)/2;
        if(qr1<=mid) add_i(x<<1,row);
        if(qr2>mid) add_i(x<<1|1,row);
        push_up(x,row);
    }
}
void set_i(int x,int row){
    int l = tr[row][x].l;int r= tr[row][x].r;
    if(qr1<=l&&qr2>=r){
        tr[row][x].update_set(q_set);
    }
    else{
        push_down(x,row);
        int mid = (l+r)/2;
        if(qr1<=mid) set_i(x<<1,row);
        if(qr2>mid) set_i(x<<1|1,row);
        push_up(x,row);
    }
}
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int ks;
    while(cin >> r >> c>> m){
        for(int i=1;i<=r;i++){
            build(1,1,c,i);
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d%d%d%d",&ks,&ql1,&qr1,&ql2,&qr2);
            if(ks==1){
                scanf("%d",&q_add);
                for(int j=ql1;j<=ql2;j++){
                    add_i(1,j);
                }
            }
            else if(ks == 2){
                scanf("%d",&q_set);
                for(int j=ql1;j<=ql2;j++){
                    set_i(1,j);
                }
            }
            else 
            {
                q_sum=0;q_max=-INF;q_min=INF;
                for(int j=ql1;j<=ql2;j++){
                    query_i(1,j);
                }
                printf("%d %d %d\n",q_sum,q_min,q_max);
            }
            
        }
        
    }
    
    return 0;
}
// //还是有点问题的，CE可能是MLE了 2e8的字节200M超限制了 偷了ac
// //push_down时候先检查有没有set标记
// //set一个node后要把add标记清0
// //set初始化-1
// //uva11992 区间直接赋值线段树



//模板

// #include <iostream>
// #include <cstdio>
// using namespace std;
// const int maxn  = 1e6+5,INF=0x7fffffff;
// struct Tree{
//     int l,r;
//     int setv,addv;
//     int sumv,maxv,minv;
//     void update(int val){
//         addv+=val;
//         minv+=val;
//         maxv+=val;
//         sumv+=val*(r-l+1);
//     }
//     void update_set(int val){
//         setv =val;
//         minv =val;
//         maxv =val;
//         sumv =val*(r-l+1);
//         addv =0;
//     }
// };