#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int V,E,T;
int degree[1005];
vector<int> g[1005];
int count;
int isvis[1005];
int odd;
void dfs(int i){
    
    isvis[i]=1;
    int gsize=g[i].size();
    for(int j=0;j<gsize;j++){
        if(!isvis[g[i][j]]){
            if(degree[g[i][j]]&1)
                odd++;
            
            isvis[g[i][j]]=1;
            dfs(g[i][j]);
        }
    }
}
int main(){
    // freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
   int kase=0;
    while(cin>>V>>E>>T && (V||E||T)){
        memset(degree,0,sizeof(degree));
        memset(isvis,0,sizeof(isvis));
        fill(g,g+V+1,vector<int>{});
        count=0;
        for(int i=0;i<E;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
            degree[x]++;
            degree[y]++;
        }
        int add_edge=0;
        for (int i = 1; i <= V; i++)
        {
            if(degree[i]==0) continue;
            odd=0;
           
            if(!isvis[i]){
                if(degree[i]&1)
                    odd++;
                count++;
                
                dfs(i);
                
                
            }   
            add_edge+= max((odd-2)/2,0);
        }
        //cout<<"count= "<<count<<endl;
        
        int ans=E+add_edge+count-1;
        ans*=T;
        if(ans<0) ans=0;
        cout<<"Case "<<++kase<<": "<<ans<<endl;
    }

   
   return 0;

}

//每个联通块构造为欧拉通路（2个奇点）
//用新加的一条边联通两个联通块
//这样所有的都可以一笔画