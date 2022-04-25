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
ll gcd(ll x,ll y){
    if(y == 0) return x;
    return gcd(y, x % y);
}

template<typename T, typename F = std::greater<T>>
struct Monoqueue{
    private:
        deque<pair<T,int>> q;
        int addn,decn;
        F Cmp = F();
    public:
        Monoqueue(){
            addn = decn = 0;
        }
        
        void push(T val){
            while(!q.empty() && Cmp(q.back().first,val) ){
                q.pop_back();
            }
            q.push_back({val,addn});               
            addn++;
        }

        void pop(){
            if(!q.empty() && q.front().second == decn){
                q.pop_front();
            }
            decn++;
        }

        T top(){
            return q.front().first;
        }

};

int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; 
    ll K;
    cin >> n >> K; 
    vector<ll> a(n);
    ll ans = 0;
    for(int i = 0;i < n;i++) cin >> a[i];
    int l = 0;
    
    Monoqueue<ll,std::greater<ll>> q1;
    Monoqueue<ll,std::less<ll>> q2;
    for(int r = 0;r < n;r++){
        
        q1.push(a[r]),q2.push(a[r]);
        while(q2.top() - q1.top() > K){
            q1.pop(),q2.pop();
            l++;
        }
        ans  = ans + r - l + 1;
    }
    cout << ans << endl;
    
    
    
    return 0;
}