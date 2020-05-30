#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
const int maxn=10005;
int fa[maxn];
int find(int x){
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
int main(){
    freopen("data.in","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int x,y,z;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
    
        scanf("%d%d%d",&z,&x,&y);
        if(z==1){
            fa[find(x)]=find(y);
        }else if(z==2){
            if(find(x)==find(y)){
                printf("Y\n");
            }else{
                printf("N\n");
            }
        }
    }
    return 0;
}