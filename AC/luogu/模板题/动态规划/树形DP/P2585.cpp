#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int maxn = 5e5+5;
string s;int ssize;
struct Tree{
    Tree* l,*r;
    //int col;
    int f[3];
    int g[3];
    Tree(){l=r=NULL;f[0]=f[1]=f[2]=0;g[0]=g[1]=g[2]=0;}
};

int rootid;
void dfs(Tree* root){
    if(rootid >= ssize) return;
    //cout << s[rootid] <<" ";
    if(s[rootid]=='1'){
        Tree* l =new Tree();
        root->l = l; 
        rootid++;
        dfs(l);
    }
    else if(s[rootid] == '2'){
        Tree* l =new Tree();
        root->l = l; 
        rootid++;
        dfs(l);
        Tree* r =new Tree();
        root->r = r; 
        rootid++;
        dfs(r);
    }
    else if(s[rootid]=='0'){
        //rootid++;
    }
    return;
}

void PrintTree(Tree* root){
    if(!root) return ;
   // cout << root->col<<endl;
    if(root->l) PrintTree(root->l);
    if(root->r) PrintTree(root->r);
    return ;
}
Tree* root;

void sol(Tree* root){
    if(!root) return;
    int* f= root->f;int * g=root->g;
    if(!root->l && !root->r){
        f[0]=1;g[0]=1;
    }
    else if(root->l && root->r){
        sol(root->l);
        sol(root->r);
        f[0]=max(root->l->f[1]+root->r->f[2],root->l->f[2]+root->r->f[1])+1;
        f[1]=max(root->l->f[2]+root->r->f[0],root->l->f[0]+root->r->f[2]);
        f[2]=max(root->l->f[1]+root->r->f[0],root->l->f[0]+root->r->f[1]);

        g[0]=min(root->l->g[1]+root->r->g[2],root->l->g[2]+root->r->g[1])+1;
        g[1]=min(root->l->g[2]+root->r->g[0],root->l->g[0]+root->r->g[2]);
        g[2]=min(root->l->g[1]+root->r->g[0],root->l->g[0]+root->r->g[1]);
    }
    else{
        sol(root->l);
        f[0]=max(root->l->f[1],root->l->f[2])+1;
        f[1]=max(root->l->f[2],root->l->f[0]);
        f[2]=max(root->l->f[1],root->l->f[0]);

        g[0]=min(root->l->g[1],root->l->g[2])+1;
        g[1]=min(root->l->g[2],root->l->g[0]);
        g[2]=min(root->l->g[1],root->l->g[0]);
    }
    return;
}

int main(){
    freopen("data.in","r",stdin);
    cin >> s;ssize = s.length();
    
    root = new Tree();
    dfs(root);
   
  //  PrintTree(root);
    sol(root);
    int ans1 = max(root->f[0],max(root->f[1],root->f[2]));
    int ans2 = min(root->g[0],min(root->g[1],root->g[2]));
    cout << ans1<<" "<<ans2;
    
    return 0;
}
//min max 型还是比背包简单