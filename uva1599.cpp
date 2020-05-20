#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
const int maxn=100010;
vector<int> g[maxn];
vector<int> rg[maxn];
vector<int> cg[maxn];
int main(){
   // freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
   int n,m;
   while(cin>>n){
       cin>>m;
       int v1,v2;
       int color;
       for(int i=0;i<m;i++){
           cin>>v1>>v2>>color;
           if(v1 == v2 ) continue;
           g[v1].push_back(v2);
           cg[v1].push_back(color);
           rg[v2].push_back(v1);
       }
   }
    return 0;
}