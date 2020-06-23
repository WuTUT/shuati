#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 105*2;
int n,m,wi,vi;
int f[maxn][602];
int w[maxn],v[maxn];
int tr[maxn];
// void dfs(Tree* &root){//必须加&
//     root = new Tree();
    
//     cin >> wi >> vi;
//     if(vi==0){
//         root->w=wi;
//         root->v=0;
//         dfs(root->l);
//         dfs(root->r);
//     }
//     else{
//         root->w=wi;
//         root->v=vi;
//         root->l=root->r=NULL;
//     }
// }
// void print(Tree* root){
//     if(root==NULL) return;
//     printf("%d\n",root->w);
//     print(root->l);
//     print(root->r);
// }
void dfs(int root){
    cin >> wi >> vi;
    w[root]=wi*2;
    v[root]=vi;
    if(vi==0){
        
        dfs(root*2);
        dfs(root*2+1);
    }
    
}
int dp(int root){
    int dr1=0,dr2=0;
    if(v[root]){
        
        for(int i=w[root];i<=m;i++)
            f[root][i]=min((i-w[root])/5,v[root]);
        return v[root];
    }
    else{
        //版本1
        // dr1=dp(root*2);
        // dr2=dp(root*2+1);
        // for(int i=m;i>=w[root];i--){
        //     int tt= i-w[root];
        //     //int tt=min(i-w[root],dr1*5);
        //     for(int j=0;j<=tt;j++){
        //         f[root][i]=max(f[root*2][j]+f[root*2+1][i-j-w[root]],f[root][i]);
        //     }
        // }
        //真分组背包
        dr1=dp(root*2);
        for(int i=m;i>=w[root];i--){
            int tt= i-w[root];
            //int tt=min(i-w[root],dr1*5);//不可以对背包的空间进行优化！好像只能优化状态选择为子节点个数的情形
            for(int j=0;j<=tt;j++){
                f[root][i]=max(f[root*2][j]+f[root][i-j],f[root][i]);
            }
        }
        dr2=dp(root*2+1);
        for(int i=m;i>=w[root];i--){
            int tt= i-w[root];
            //int tt=min(i-w[root],dr2*5);
            for(int j=0;j<=tt;j++){
                f[root][i]=max(f[root*2+1][j]+f[root][i-j],f[root][i]);
            }
        }
    }
    return dr1+dr2;
}
int main(){
    freopen("data.in","r",stdin);
    cin >> m;m--;
    
    dfs(1);
    //printf("%d",root->w);
    // for(int i=1;i<=7;i++) printf("%d ",w[i]);
    // printf("\n");
    // for(int i=1;i<=7;i++) printf("%d ",v[i]);
    // printf("\n");
    //print(root);
    dp(1);
    cout << f[1][m]<<endl;
    // for(int i=1;i<=7;i++){
    //     for(int j=0;j<=m;j++){
    //         printf("%02d ",f[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}