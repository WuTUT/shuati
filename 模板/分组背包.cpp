#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=1005;
int f[maxn];
vector<int> w[maxn];
vector<int> v[maxn];
int main(){
    freopen("data.in","r",stdin);
    int m,n;
    cin >> m >> n;
    int x,y,z;
    int ksize=0;
    for(int i=1;i<=n;i++){
        cin >> x>>y>>z;
        w[z].push_back(x);
        v[z].push_back(y);
        ksize=max(ksize,z);
    }
    for(int i=1;i<=ksize;i++){
        for(int j=m;j>0;j--){
            for(int k=v[i].size()-1;k>=0;k--){
              if(j>=w[i][k])  f[j]=max(f[j],f[j-w[i][k]]+v[i][k]);
            }
        }
    }
    cout << f[m]<<endl;
    return 0;
}

//分组背包模板https://www.luogu.com.cn/problem/P1757
