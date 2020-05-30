#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
const int maxn=5005;
int fa[maxn];
int find(int x){
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
int main(){
    freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    int pi,pj;
    for(int i=0;i<=n;i++){//必须的初始化，保证不同祖先 而不能在下面做，否则会有一些node都指向0从而有相同祖先
        fa[i]=i;
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&pi,&pj);
        fa[find(pj)]=find(pi);//Union只对根操作，即必须用两个find
    }
    for(int i=1;i<=p;i++){
        scanf("%d%d",&pi,&pj);
        if(find(pi)==find(pj)) printf("Yes\n");
        else printf("No\n");
    } 
          
    return 0;
}