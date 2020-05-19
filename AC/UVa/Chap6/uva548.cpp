#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
vector<int> post;
vector<int> in;
bool readlist(vector<int>& v){
    string s;
    if (getline(cin,s))
    {
        stringstream ss(s);
        int x;
        while (ss>>x)
        {
            v.push_back(x);
            
        }
        return true;
    }
    else return false;

}
struct Node{
    int val;
    struct Node* l;
    struct Node* r;
};
typedef struct Node* Tree; 
Tree root;

Tree buildtree(int l1,int r1,int l2,int r2){
    int i;
   
    if(l1>r1) return NULL;
    if(l1==r1) {Tree t= new Node();t->val=in[l1]; return t; }
    for(i=l1;i<=r1;i++){
        if(post[r2]==in[i]){
            break;
        }
    }
    Tree t=new Node();
    t->val=in[i];
    int count=i-l1;
    t->l=buildtree(l1,i-1,l2,l2+count-1);
    t->r=buildtree(i+1,r1,l2+count,r2-1);
    return t;
}
int bestn;
int leafv;
void dfs(Tree root,int tmpn){
    if(root==NULL){
        return;
    }
    tmpn+=root->val;
    if( (root->l==NULL) && (root->r==NULL) ){
        if(bestn> tmpn){
            bestn = tmpn;
            leafv = root->val;
        }
        else if(bestn==tmpn)
        {
            leafv= leafv<(root->val)?leafv:root->val;
        }
        return;
    }
    
    if(root->l){
        dfs(root->l,tmpn);
    }
    if(root->r){
        dfs(root->r,tmpn);
    }
    return;
}
void freeTree(Tree root){
    if(!root) return;
    freeTree(root->l);
    freeTree(root->r);
    delete root;
    return;
}
int main(){
    //freopen("data.in","r",stdin);
    
    while (1)
    {
        post.clear();
        in.clear();
        bestn=1000000;
        freeTree(root);
        if(readlist(in)){
            readlist(post);
            //cout<<in.size()<<" "<<post.size()<<endl;
            root=buildtree(0,in.size()-1,0,post.size()-1);
            //cout<<root->val<<endl;
        }
        else{
            break;
        }
        dfs(root,0);
        cout<<leafv<<endl;
    }
    
    
    
    return 0;
}



//tmpn+=root->val; 注意位置
//注意建树时两个遍历对应大小一致