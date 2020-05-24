#include<iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
int bfs[1005];
int n;
vector<int> ans[1005];
stack<int> s;
int main(){
   // freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
    

    while(cin>>n){
        fill(ans,ans+n+1,vector<int>{});
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            bfs[x]=i;
        }
        int root;
        scanf("%d",&root);
        s.push(root);
        for(int i=1;i<n;++i){
            int x;
            scanf("%d",&x);
            while(!s.empty()){
                int y=s.top();
                if(bfs[y]+1<bfs[x]||y==root){
                    ans[y].push_back(x);
                    s.push(x);
                    break;
                }
                else{
                    s.pop();
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            cout<<i<<":";
            for(int j=0;j<ans[i].size();j++){
                cout<<" "<<ans[i][j];
            }
            cout<<endl;
        }
    }
   return 0;
}

//https://www.luogu.com.cn/problem/solution/UVA10410
//考虑DFS序，相邻的两个节点，(1)如果他们在BFS序相邻，视作为彼此为兄弟节点，比如1,2,3  ，1,2,3
/*  1      1
   2 3    2
         3    
    虽然都满足题意，但是只考虑第一种情形，即优先填满这一层，（不一定是二叉树）
 (2)如果后者的BFS序在前者的前面，××说明前一个节点的下面已经遍历完成，因此可以出栈××
 (3)如果后者的BFS序在前者的后面且大于1，则看做是前者的儿子（当成二叉树来处理）  
*/