#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 21,maxc = 1e6+5;
int qr1,qr2,ql1,ql2;
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
}tr[maxn][maxc<<2];
inline void push_up(int x,int row){

    tr[row][x].sumv = tr[row][x<<1].sumv + tr[row][x<<1|1].sumv;
    tr[row][x].minv = min(tr[row][x<<1].minv,tr[row][x<<1|1].minv);
    tr[row][x].maxv = max(tr[row][x].maxv,tr[row][x].maxv);

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
void query_i(int x,int row){
    
}