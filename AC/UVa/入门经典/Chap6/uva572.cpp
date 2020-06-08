#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=105;
char pix[maxn][maxn];
int idx[maxn][maxn];
int m,n;
int ans;

void dfs(int i,int j,bool isfind){
    if(i<0||i>=m||j<0||j>=n) return;
    if(idx[i][j]==1) return;
    if(pix[i][j]=='*') return;
    else
    {
        if(!isfind){
            isfind=true;
            ans++;
        }   
        
    }
    
    idx[i][j]=1; 
    dfs(i+1,j,isfind);
    dfs(i-1,j,isfind);
    dfs(i,j+1,isfind);
    dfs(i,j-1,isfind);
    dfs(i+1,j+1,isfind);
    dfs(i-1,j+1,isfind);
    dfs(i+1,j-1,isfind);
    dfs(i-1,j-1,isfind);

}
int main(){
    //freopen("data.in","r",stdin);
    while(scanf("%d%d",&m,&n)==2 && m &&n){
        memset(idx,0,sizeof(idx));
        ans=0;
        for(int i=0;i<m;i++){
            scanf("%s",pix[i]);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(i,j,false);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}