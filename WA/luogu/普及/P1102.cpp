#include <iostream>
#include <cstdio>
#include <map>
#include <unordered_map>
using namespace std;
const int maxn=2e5+5;
int n,c;
unordered_map<int,int> ma;
int a[maxn];
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> c;long long cnt=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ma[a[i]]++;
    }
    for(int i=1;i<=n;i++){
       cnt+=ma[a[i]+c];
    }
   
    cout <<cnt;
    return 0;
}

//双指针也太难写了吧？？？？
//AC了但是...我晕