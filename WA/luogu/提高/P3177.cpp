#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 2005;
int n,m;
vector<int> g[maxn];
vector<int> w[maxn];
ll f[maxn][maxn];
int sz[maxn];
void dfs(int root,int fa){
    sz[root]=1;
    // f[root][0]=f[root][1]=0;
    for(int i=0;i<g[root].size();i++){
        
        int to = g[root][i];
        if(to==fa) continue;
        dfs(to,root);
        
        for(int j=sz[root];j>=0;j--){
            //int tt=min(m,sz[to]);
            for(int k=sz[to];k>=0;k--){
                
                ll val=k*(m-k)+ (sz[to]-k)*(n-m-sz[to]+k);
                val*=w[root][i];
                f[root][j+k]=max(f[root][j+k],f[root][j]+f[to][k]+val);
            }
        } 
        sz[root]+=sz[to];
    }
}
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int main(){
    freopen("data.in","r",stdin);
   
    cin >> n >> m;
    int fr,to,dis;
    for(int i=0;i<n-1;i++){
        fr=read();to=read();dis=read();
        
        g[fr].push_back(to);
        w[fr].push_back(dis);
        g[to].push_back(fr);
        w[to].push_back(dis);
    }
    dfs(1,-1); 
    cout << f[1][m]<<endl;
    return 0;
}