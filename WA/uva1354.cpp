#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=6;
int s;
int T;
double r;
double w[maxn],sum[1<<maxn];
struct Tree {
  double l, r; // distance from the root to the leftmost/rightmost point
  Tree():l(0),r(0) {}
};
vector<Tree> tree[1<<maxn];
bool isvis[1<<maxn];
void dfs(int subset){
    if(isvis[subset]) return;
    isvis[subset]=1;
    if(((subset-1)&subset)==0) tree[subset].push_back(Tree{});
    else{
        for(int left=(subset&(subset-1));left>0;left=((left-1)&subset)){
            int right=left^subset;
            dfs(left);dfs(right);
            double dl=sum[right]/sum[subset];
            double dr=sum[left]/sum[subset];
            for(auto tl:tree[left]){
                for(auto tr:tree[right]){
                    Tree t;
                    t.l=max(tl.l+dl,tr.l-dr);
                    t.r=max(tr.r+dr,tl.r-dl);
                    if(t.l+t.r<r) tree[subset].push_back(t);
                }
            }
        }
    }
    
}
int main(){
    
     //freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    scanf("%d",&T);
    while(T){
        T--;
        scanf("%lf %d",&r,&s);
        for(int i=0;i<s;i++){
            scanf("%lf",&w[i]);
        }
        for(int i=0;i<(1<<s);i++){
            sum[i]=0;tree[i].clear();
            for(int j=0;j<s;j++){
               // sum[i]+=(i&(1<<j))*w[j];
               if(i&(1<<j)) sum[i]+=w[j];
            }
        }
        memset(isvis,0,sizeof(isvis));//
        int root=(1<<s)-1;//

        dfs(root);//
        double ans=-1;//
        for(int i=0;i<tree[root].size();i++){
            ans=max(tree[root][i].l+tree[root][i].r,ans);
        }
        if(ans+1<1e-5) printf("-1\n");
        else
        {
            printf("%.16lf\n",ans);
        }
        
    }
    

    return 0;    
}