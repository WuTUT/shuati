#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
const int maxn = 5005; 
int n,m;
vector<int> v[maxn];
struct Edge{
    int x,y;
}edges[maxn];
int isvis[maxn];
int ans[maxn];
int top;
int minans[maxn];
void dfs(int root){
    if(isvis[root]) return;
    isvis[root] = true;
    ans[++top] = root;
    for(int i=0;i<v[root].size();i++){
        int to = v[root][i];
        if(!isvis[to]){
            dfs(to);
        }
    }
    
}

int dex,dey;
void dfs2(int root){
    
    if(isvis[root]) return;
    isvis[root] = true;
    ans[++top] = root;
    // if(ans[top]>minans[top]){ //字典序剪枝是大错特错！！！！
    //     fla =false;
    //     return;
    // }
    for(int i=0;i<v[root].size();i++){
        int to = v[root][i];
        if((to == dey && root == dex) || (root == dey && to == dex)){
            continue;
        } 
        if(!isvis[to]){
            dfs2(to);
        }
    }
}
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    int vx,ux;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&vx,&ux);
        v[vx].push_back(ux);
        v[ux].push_back(vx);
        edges[i].x=vx;
        edges[i].y=ux;
    }
    
    if(n==m+1){
        for(int i=1;i<=n;i++){
            sort(v[i].begin(),v[i].end());
        }
        dfs(1);
        for(int i=1;i<n;i++){
            printf("%d ",ans[i]);
        }
        printf("%d",ans[n]);
    }
    else{
        for(int i=1;i<=n;i++){
            sort(v[i].begin(),v[i].end());
        }
        dex=edges[1].x;
        dey=edges[1].y;
        
        
        memset(minans,0x7f,sizeof(int)*(n+1));
        dfs2(1);
        memcpy(minans,ans,sizeof(int)*(top+1)); 
        

      //  cout <<mintop<<endl;
        for(int i=2;i<=m;i++){
            dex=edges[i].x;
            dey=edges[i].y;
            
            
            top =0;
            memset(isvis,0,sizeof(int)*(n+1));
            dfs2(1);
           // cout << top<<endl;
            // for(int i=1;i<n;i++){
            // printf("%d ",ans[i]);
            // }
            // printf("%d\n",ans[n]);
            if(top<n){
                continue;
            }else{
                bool ismin=false;
                for(int i=1;i<=n;i++){
                    if(ans[i]==minans[i]){
                        continue;
                    }
                    else if(ans[i]<minans[i]){
                        ismin = true;
                        break;
                    }
                    else if(ans[i]>minans[i]){
                        break;
                    }
                }
                if(ismin)
                    memcpy(minans,ans,sizeof(int)*(n+1));    
            }
        }
        for(int i=1;i<n;i++){
            printf("%d ",minans[i]);
        }
        printf("%d",minans[n]);
    }
    return 0;
}
//注意的细节太多
// memset(isvis,0,sizeof(int)*(n+1));每次初始化都做完整了吗？？？
// memcpy 不要写成了memccpy
// 字典序剪枝是大错特错！！！！ 千万不能剪枝！！！！
// 字典序比较！！！！
// 找bug找吐了 