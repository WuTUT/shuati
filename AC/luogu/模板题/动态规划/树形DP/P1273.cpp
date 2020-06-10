#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=3002;
int n,m;
vector<int> c[maxn];
vector<int> e[maxn];
int f[maxn][maxn];
int dfs(int root){
    int csize = c[root].size();
    int leaves=0;
    for(int i=0;i<csize;i++){
        
        int t=dfs(c[root][i]);
        leaves+=t;
        for(int j=leaves;j>0;j--){
            //for(int k=0,kk=min(j,t);k<=kk;k++){//下面这两个都可以
              for(int k=min(j,t);k>=0;k--){  
                f[root][j]=max(f[root][j],f[c[root][i]][k]-e[root][i]+f[root][j-k]);
               // cout << i << "    "<<root<<"   " <<c[root][i]<<"          "<< j<<"   "<<k<<"     " <<f[root][j]<<endl;
                
                
            }
            
        }
        
    }
    return (leaves == 0)?1:leaves;
}
int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    cin >> n >> m;
    int k,x,y;
    for(int i=1;i<=n-m;i++){
        cin >> k;
        for(int j=1;j<=k;j++){
            cin >> x >> y; 
            c[i].push_back(x);
            e[i].push_back(y);
        }
    }
    memset(f,~0x3f,sizeof f);
    for(int i=n-m+1;i<=n;i++){
        cin >> f[i][1];
        
    }
    for(int i=1;i<=n;i++) f[i][0]=0;
   // cout << "i"<<" root"<<"  c[root][i] " <<" j"<<"   k" <<"  f[root][j]"<<endl;
    dfs(1);
    for(int i=m;i>=0;i--){
        //cout << f[1][i]<<endl;
        if(f[1][i]>=0){
            cout << i<<endl;
            break;
        }
    }
    return 0;
}

//1初始化，因为0个节点f[i][0]一定是0
//2初始化负无穷的方法memset(f,~0x3f,sizeof f);
//3边界条件确定
//4树上的背包顺序是前两个循环定顺序，与最后一个无关 优化的是i维，后面有点像完全背包，但是设定了两个状态所以顺序随便
//这个叫分组背包！！！！！
/*
为什么是分组背包
分组背包指在很多组中只能选一种物品，获得的最大利润

回到本题，组就是每一棵子树，物品其实并不是叶子结点，而是叶子节点的满足个数。

比如，在以结点u为根的子树中（第u组）,有一些物品，这些物品是：

满足以结点u为根的子树中，1个叶子结点的需求。
满足以结点u为根的子树中，2个叶子结点的需求。
满足以结点u为根的子树中，3个叶子结点的需求。
满足以结点u为根的子树中，4个叶子结点的需求。
满足以结点u为根的子树中，Size_v个叶子结点的需求。
每一组的各个元素都是互相矛盾只能选一种的。

这就是分组背包。

对于每一个结点都要进行分组背包。


*/
//5树上背包