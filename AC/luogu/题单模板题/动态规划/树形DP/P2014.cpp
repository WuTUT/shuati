#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=305;
vector<int> c[maxn];
int w[maxn];
int f[maxn][maxn];
int n,m;
void dfs(int root){
    int csize=c[root].size();
    
        f[root][1]=w[root];
    
    for(int i=0;i<csize;i++){
        int c1= c[root][i];
         dfs(c1);
        for(int j=m+1;j>0;j--){
            for(int k=j-1;k>0;k--){
                f[root][j]=max(f[root][j],f[c1][k]+f[root][j-k]);
            }
        }
       
    }
    return;    
}
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    int x,y;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        c[x].push_back(i);
        w[i]=y;

    } 
    dfs(0);
    cout << f[0][m+1]<<endl;
    
    // cout << f[3][1]<<endl;
    // cout << f[2][3]<<endl;
    // cout << f[7][2]<<endl;
    // cout << f[6][1]<<endl;
    
    return 0;
}