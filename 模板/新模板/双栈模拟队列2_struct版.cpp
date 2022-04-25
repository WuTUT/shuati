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

template<typename T,typename U, typename F=std::function<T(T,U)>>
struct Minstk{
    stack<U> sk;
    stack<T> ms;
    F fn;
    Minstk(F _fn, T _Identity){
        ms.push(_Identity);
        fn = _fn;
    }

    void push(U val){
        sk.push(val);
        ms.push(fn(ms.top(),val));
    }

    void pop(){
        ms.pop(),sk.pop();
    }

    U top(){
        return sk.top();
    }

    T getMin(){
        return ms.top();
    }

    bool empty() const {
        return sk.empty();
    }
};

template<typename T,typename U, typename F>
void removeSk(Minstk<T,U,F>& s1,Minstk<T,U,F>& s2){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.top()),s2.pop();
        }
    }
    s1.pop();
}

int n,s;

template<typename T,typename U, typename F>
bool good(Minstk<T,U,F>& s1,Minstk<T,U,F>& s2){
    auto al = s1.getMin(), a2 = s2.getMin();
    for(int i = 0; i<= s;i++){
        if(al[i] && a2[s - i]){
            return true;
        }
    }
    return false;
}
using bs_t = bitset<1005>;
bs_t fn(bs_t b1,int v){
    return b1 | (b1 << v);
}

int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> n >> s;
    
    vector<int>a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    int ans = 1e7;
    
    int l = 0;
    

    
    auto gn = std::function(fn);
    Minstk<bs_t,int, decltype(gn)> s1(gn, bs_t{1});
    Minstk<bs_t,int, decltype(gn)> s2(gn, bs_t{1});

   

    for(int r = 0;r < n;r++){
        s2.push(a[r]);
        while(good(s1,s2)){
            ans = min(ans, r - l + 1);    
            removeSk(s1,s2);
            l++;
        }
    }
   
    
  
    if(ans == 1e7) ans = -1;
   
    cout << ans << endl;
    return 0;
}