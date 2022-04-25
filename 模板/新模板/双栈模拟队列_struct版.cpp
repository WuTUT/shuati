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
template<typename T>
T mgcd(T x,T y){
    if(y == 0) return x;
    return gcd(y, x % y);
}



template<typename T, typename F = std::function<T(T,T)>>
struct MinStk{
    stack<T> sk;
    stack<T> ms;
    //T minV = std::numeric_limits<T>::min();
    //T maxV = std::numeric_limits<T>::max();
    
    F fn;
    MinStk(F _fn, T _Identity){
        fn = _fn;
        ms.push(_Identity);
    } 

    void push(T val){
        
        ms.push(fn(ms.top(),val));
        
        sk.push(val);
        
    }

    T top(){
        return sk.top();
    }

    T getMin(){
        return ms.top();
    }

    void pop(){
        ms.pop();
        sk.pop();
    }
    
    bool empty()const{
        return sk.empty();
    }
};

template<typename T, typename F> 
void removeSK(MinStk<T,F>& s1,MinStk<T,F>& s2){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    s1.pop();
}

int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; 
    
    cin >> n; 
    vector<ll> a(n);
    int ans = 1e8;
    for(int i = 0;i < n;i++) cin >> a[i];
    int l = 0;
    auto f = std::gcd<ll,ll>;
    
    MinStk<ll,decltype(f)> s1(f, 0ll);
    MinStk<ll,decltype(f)> s2(f, 0ll);
    //s1 queue front , s2 queue end
    
    for(int r = 0;r < n;r++){
        s2.push(a[r]);
        
        while(std::gcd(s1.getMin(), s2.getMin()) == 1){
            ans = min(ans, r - l + 1);
            removeSK(s1,s2);
            l++;
        }
        
    }
    if(ans == 1e8) ans = -1;
    cout << ans << endl;
    
    
    
    return 0;
}