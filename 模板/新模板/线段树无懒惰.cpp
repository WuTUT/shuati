#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <numeric>
#include <iterator>
#include <random>
#include <cassert>
#include <array>
#include <functional>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 3e5 + 10;
const int M = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;


template<typename T>
struct segtree{
    int size;
    vector<T> values;
    T NEUTRAL_ELEMENT;

    

    void init(int n){
        size = 1;
        while(size <= n) size = size * 2;
        values.resize(size * 2,{0});
        NEUTRAL_ELEMENT = T{nullptr};
    }

    void build(vector<int>& a, int x, int lx, int rx){
        //cout << x <<" " << lx << " " << rx << endl;
        if(lx == rx){ 
            if(lx < (int)a.size())
            values[x] = T{a[lx]};
        }
        else{ 
            int m = (lx + rx) / 2;
            build(a, x * 2, lx, m);
            build(a, x * 2 + 1, m + 1, rx);
            values[x] = values[x * 2] + values[x * 2 + 1];
        }
    }

    void build(vector<int>& a){
        build(a,1,1,size);
    }

    void set(int i,int v,int x,int lx,int rx){
        if(lx == rx) {
            values[x] = T{v}; 
        }
        else{
            int m = (lx + rx) / 2;
            if(i <= m){
                set(i,v,x*2,lx,m);
            }
            else{
                set(i,v,x*2+1,m+1,rx);
            }
            values[x] = values[x * 2] + values[x * 2 + 1];
        }
    }

    void set(int i,int v){
        return set(i, v, 1, 1, size);
    }

    T query(int l,int r,int x,int lx,int rx){
        //cout << lx << " >> " << rx << endl;
        if(l > rx || r < lx) return NEUTRAL_ELEMENT;
        if(l <= lx && rx <= r) return values[x];
        int m = (lx + rx) / 2;
        T t1 = query(l, r, x * 2, lx, m); 
        T t2 = query(l, r, x * 2 + 1, m + 1, rx);
        return t1 + t2;
    }

    T query(int l,int r){
        return query(l, r, 1, 1, size);
    }  
}; 

struct item{
    ll preSum;
    ll sufSum;
    ll sum;
    ll res;

    item(void* ){
        res = sum = preSum = sufSum = 0;
    }

    item(int val = 0){
        preSum = sufSum = sum = val;
        res = max(val, 0);
    }

    friend ostream &operator<<(ostream& os, const item &it){
       return cout << it.res;
    }

    item operator+(const item& b){
        item ret;
        ret.res = max({res, b.res, sufSum + b.preSum});
        ret.preSum = max(preSum, sum + b.preSum);
        ret.sufSum = max(b.sufSum, b.sum + sufSum);
        ret.sum = sum + b.sum;
        return ret;
    }
};



int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    segtree<item> st;
    
    st.init(n);
    
    vector<int> a(n + 1);
    //for(auto& x : a) cin >> x;
    for(int i = 1;i <= n;i++) cin >> a[i]; 
    //for(auto& x : a) cout << x << endl;
    // cout << st.size << endl;
    st.build(a);
    
    /*
    for(int i = 1;i <= n;i++)
      cout << st.query(i,i,1,1,st.size) << " w" << endl;
    */
   cout << st.query(1,n) << endl;
    while(m--){
        int l, r;
        cin >> l >> r;
        st.set(l + 1, r);
        cout << st.query(1,n) << endl;
        
    }
    
   
    return 0;
}