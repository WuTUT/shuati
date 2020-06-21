#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 104;
int n,q;
vector<int> e[maxn];
vector<int> c[maxn];

int f[maxn][maxn];
void dfs(int root,int fa){
    
   // cout << root <<"  " <<le<<" ";
   for(int i=0;i<e[root].size();i++){
       int to= c[root][i];
      
       if(fa!=to){
           dfs(to,root);
           for(int j=q;j>=1;j--){
            for(int k=j-1;k>=0;k--){
            
                f[root][j]=max(f[root][j],f[root][j-k-1]+f[to][k]+e[root][i]);
            }
            } 
       }
       
   }
   //cout << f[root][le]<<endl;
   return ;
}
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> q;
   
    int x,y,w;
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&x,&y,&w);
        c[x].push_back(y);
        e[x].push_back(w);
        c[y].push_back(x);
        e[y].push_back(w);
    }
    
    dfs(1,0);
    cout << f[1][q];
    return 0;
}
//树上的背包你学到了吗，没学到背下来了吗
