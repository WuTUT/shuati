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
int fa[maxn];
int find(int x){
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
int main(){
    freopen("data.in","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m)==2 && n){
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        int v,u;int cnt=0;
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            int rootu=find(u);
            int rootv=find(v);
            if(rootv!=rootu){
                fa[rootv]=rootu;
                cnt++;
            }
        }
        if(n==1)
            printf("0\n");
        else{
            printf("%d\n",n-1-cnt);
        }
    }   
    

}