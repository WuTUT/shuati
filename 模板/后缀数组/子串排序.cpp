#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 3e5 + 10;


const int MAXN = 21;
int lg[1<<21];
struct SparseTable{
    
    int n;
    vector<vector<int>> st;
    void init(int _n,vector<int>& a){
       
        n = _n;
        st.resize(n, vector<int>(MAXN));
        
        lg[1] = 0;
        for(int i = 2;i < (1 << MAXN);i++){
            lg[i] = lg[i / 2] + 1;
        }

        for(int i = 0;i < n;i++){
            st[i][0] = a[i];
        }
        for(int i = 1;i < 21;i++){
            int len = 1 << (i - 1);
            for(int j = 0;j + len < n;j++){
                st[j][i] = std::min(st[j][i - 1] , st[j + len][i - 1]);
            }
        }
    }

    int query(int l,int r){
        
        int len = (r - l + 1);
        return std::min(st[l][lg[len]] , st[r - (1 << lg[len]) + 1][lg[len]]); 
    }


};

inline int quick_read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}




void counting_sort(vector<int>& p,vector<int>& c){
    int n = p.size();
    {
        vector<int> cnt(n);
        for(auto x : c){
            cnt[x]++;
        }
        vector<int> p_new(n);
        vector<int> pos(n);
        for(int i = 1;i < n;i++){
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for(auto x : p){
            int id = c[x];
            p_new[pos[id]] = x;
            pos[id]++;
        }
        p = p_new;
    }
}

int main()
{
#ifdef FDEBUG
    freopen("data.in", "r", stdin);
#endif

    string s;

    
    

    cin >> s;
    s += char(32);
    int n = s.length();
    vector<int> p(n),c(n);
    {
        // k = 0;
        vector<pair<char,int>> a(n);
        for(int i = 0;i < n;i++) a[i] = {s[i], i};
        sort(begin(a),end(a));
        for(int i = 0;i < n;i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1;i < n;i++){
            if(a[i].first == a[i - 1].first)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }
    }
    int k = 0;
    while((1 << k) < n){
        int len = 1 << k;
        for(int i = 0;i < n;i++){
            p[i] = (p[i] - len + n) % n;
        }

        counting_sort(p,c);

        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for(int i = 1;i < n;i++){
            pair<int,int> prev = {c[p[i - 1]],c[(p[i - 1] + len) % n]};
            pair<int,int> now = {c[p[i]],c[(p[i] + len) % n]};
            if(now == prev)
                c_new[p[i]] = c_new[p[i-1]];
            else
                c_new[p[i]] = c_new[p[i-1]] + 1;
        }
        c = c_new;
        k++;
    }

    // for(int i = 0;i < n;i++){
    //      cout << " index " << i << " " << s.substr(p[i], n - p[i]) << endl;
    // }
    // cout << endl; 

    // c[i] is the pos of p[i] in suffix array
    // p[c[i]] = i for all i
    vector<int> lcp(n);

    for(int i = 0, k = 0;i < n - 1;i++){
        int x = c[i];
        int y = x - 1;
        while(s[p[x] + k] == s[p[y] + k]) k++;
        lcp[x] = k;
        k = max(k - 1, 0);
    }
   
    // for(int i = 0;i < n ;i++) cout << lcp[i] << " " << p[i] << " " << s.substr(p[i], n - p[i]) << endl;
    // cout << endl;

    SparseTable st;
    st.init(n, lcp);
    

    int m;
    cin >> m;
    vector<pair<int,int>> dic(m);
    for(int i = 0;i < m;i++){
        dic[i].first = quick_read();
        dic[i].second = quick_read();
        // cin >> dic[i].first >> dic[i].second;
        dic[i].first--, dic[i].second--;
    }
    auto cmp = [&](const pair<int,int> pa,const pair<int,int>& pb){
        int a_ind = pa.first, b_ind = pb.first;
        int a_l = pa.second - pa.first + 1, b_l = pb.second - pb.first + 1;
        if(a_ind == b_ind) return pa.second < pb.second;
        // cout << a_ind << " " << b_ind << endl;
        // cout << c[a_ind] << " " << c[b_ind] << endl;
        int pre_c;
        if(c[a_ind] < c[b_ind])
            pre_c = st.query(c[a_ind] + 1, c[b_ind]);
        else 
            pre_c = st.query(c[b_ind] + 1, c[a_ind]);

        // cout << "prec " << pre_c << endl;

        if(pre_c >= min(a_l, b_l)){
            if(a_l == b_l) return pa < pb;
            return a_l < b_l;
        }
        else{
            return c[a_ind] < c[b_ind];
        }
    };
    
   
    sort(begin(dic),end(dic),cmp);
    
    for(auto& [x,y] : dic){
        // cout  << x + 1 << " " << y + 1 << ' '  << s.substr(x, y - x + 1) << "\n";
        cout  << x + 1 << " " << y + 1 << "\n";
    }

    return 0;
}
