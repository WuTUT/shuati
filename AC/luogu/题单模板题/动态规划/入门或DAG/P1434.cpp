#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
const int maxn=105;
int dp[maxn][maxn];
int g[maxn][maxn];
struct Node{
    int x,y,w;
    Node(int x,int y,int w):x(x),y(y),w(w){}
    bool operator <(const Node& rhs) const {
        return w<rhs.w;
    }
};
vector<Node> v;
int main(){
    freopen("data.in","r",stdin);
    int m,n;
    scanf("%d%d",&m,&n);
    int tmpl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&tmpl);
            g[i][j]=tmpl;
            v.push_back(Node(i,j,tmpl));
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
       int& x= v[i].x;
       int& y= v[i].y;
       int& w= v[i].w;
       if(dp[x][y]==0) dp[x][y]=1;
       if(x-1>=0 && g[x-1][y]>g[x][y]){
           dp[x-1][y]=max(dp[x-1][y],dp[x][y]+1);
       }
       if(x+1<m && g[x+1][y]>g[x][y]){
            dp[x+1][y]=max(dp[x+1][y],dp[x][y]+1);
        }
        if(y-1>=0 && g[x][y-1]>g[x][y]){
            dp[x][y-1]=max(dp[x][y-1],dp[x][y]+1);
        }
        if(y+1<n && g[x][y+1]>g[x][y]){    
            dp[x][y+1]=max(dp[x][y+1],dp[x][y]+1);
        }
    }
    int maxlen=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            maxlen=max(maxlen,dp[i][j]);
        }
    }
    printf("%d",maxlen);
    return 0;
}

//DAG中最长路模板题 sort一下，不转1维思路清晰一点 看来没有什么关系