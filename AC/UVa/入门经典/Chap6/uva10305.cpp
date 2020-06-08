#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn=104;
int g[maxn][maxn];
int indegree[maxn];
queue<int> q;
vector<int> ans;
int main(){
   // freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    while(n){
        if(m==0 &&n==0){return 0; }
        memset(g,0,sizeof(g));
        memset(indegree,0,sizeof(indegree));
        while (!q.empty())
        {
            q.pop();
        }
        ans.clear();
        for(int k=0;k<m;k++){
            int i,j;
            scanf("%d%d",&i,&j);
            g[i][j]=1;
            indegree[j]++;
        }
        for(int k=1;k<=n;k++){
            if(indegree[k]==0){
                q.push(k);
            }
        }
        int count=0;
        while (!q.empty())
        {
            int v=q.front();
            q.pop();
            count++;
            ans.push_back(v);
            for(int i=1;i<=n;i++){
                if(g[v][i]==1){
                    
                    indegree[i]--;
                    if(indegree[i]==0){
                        q.push(i);
                    }
                }
            }
        }
        if(count<n){
            cout<<"error"<<endl;
        }
        for(int i=0;i<ans.size();i++){
            if(i==0){cout<<ans[i];}
            else cout<<" "<<ans[i];
        }
        cout<<endl;
        scanf("%d%d",&n,&m);
    }
    return 0;
}
