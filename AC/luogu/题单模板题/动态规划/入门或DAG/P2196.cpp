#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
const int maxn=25;
int a[maxn];
int dp[maxn];
int g[maxn][maxn];
int indegree[maxn];
int pa[maxn];

void print(int maxai){
    if(pa[maxai]){
        print(pa[maxai]);
        
        printf(" %d",maxai);
    }
    else{
        printf("%d",maxai);
    }
}
int main(){
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            scanf("%d",&g[i][i+j+1]);
            if(g[i][i+j+1]==1)
                indegree[i+j+1]++;
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<indegree[i]<<" ";
    // }
    // cout <<endl;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indegree[i]){
            q.push(i);
            dp[i]=a[i];
            pa[i]=0;
        }
    }
    while(!q.empty()){
        int i=q.front();q.pop();
        for(int j=i+1;j<=n;j++){
            if(g[i][j]==1){
                if(dp[i]+a[j]>=dp[j]){
                    dp[j]=dp[i]+a[j];
                    pa[j]=i;   
                }
                
                if(!(--indegree[j])){
                    q.push(j);
                }
            }
        }
        
    }
    int maxa=0;int maxai=-1;
    
    for(int i=1;i<=n;i++){
        if(dp[i]>=maxa){
            maxa=dp[i];
            maxai=i;
        }
    }
    print(maxai);
    printf("\n%d",maxa);
    return 0;
}

//一样的DAG，lrj确实厉害