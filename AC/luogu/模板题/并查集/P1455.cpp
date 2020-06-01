#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
const int maxn=10005;
int worth[maxn];
int price[maxn];
int fa[maxn];
int f[20001];
vector<int> pack;
vector<int> weight;
int find(int x){
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
int main(){
    freopen("P1455_2.in","r",stdin);
    int n,m,w;
    scanf("%d%d%d",&n,&m,&w);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    
    for(int i=1;i<=n;i++){
    
        scanf("%d%d",&price[i],&worth[i]);
        
    }
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        int ru=find(u);
        int rv=find(v);
        if(ru!=rv){
            fa[ru]=rv;
            price[rv]+=price[ru];
            worth[rv]+=worth[ru];
        } 
    }
    long long maxworth=0;
    pack.resize(n);
    weight.resize(n);
    int count=0;
    for(int i=1;i<=n;i++){
        if(i==fa[i]){
            
            pack[count]=(worth[i]);
            weight[count]=(price[i]);
            count++;
        }
    }
    
    for(int i=0;i<count;i++){
        for(int j=w;j>=0;j--){
           if(j>=weight[i]) f[j]=max(f[j-weight[i]]+pack[i],f[j]);
        }
    }
    printf("%d",f[w]);
    return 0;
}

//0-1背包+并查集
//注意的是并查集如何加上额外操作，另外可以将儿子的price和worth归零，
//vector 预先resize好，否则会tle;