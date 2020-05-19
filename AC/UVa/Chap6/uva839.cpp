#include <iostream>
#include <cstdio>
using namespace std;
struct Node
{
    int w1,d1,w2,d2;
    struct Node* l;
    struct Node* r;
};
typedef struct Node* Tree;
bool isma;

Tree buildtree(){
    
    Tree root=new Node();
    cin>> root->w1 >> root->d1 >>  root->w2  >>  root->d2;
    if(root->w1==0){
      root->l = buildtree();
    }
    if(root->w2==0){
       root->r = buildtree();
    }
    if(root->w1==0){
        if(root->l){
            root->w1 = root->l->w1+root->l->w2;
        }
    }
    if(root->w2==0){
        if(root->r){
            root->w2 = root->r->w1+root->r->w2;
        }
    }
    if( ((root->w1)*(root->d1)) == ((root->w2)*(root->d2)) ){
        return root;    
    }
    else{
        isma=false;
        return root;
    }
        
    
}
Tree root;
void freetree(Tree root){
    if(!root) return;
    freetree(root->l);
    freetree(root->r);
    delete root;
    return;
}
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int kase;
    cin>>kase;
    while (kase)
    {
        kase--;
        isma=true;
        freetree(root);
        root= buildtree();
        if(isma){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        if(kase){
            cout<<endl<<endl;
        }
        else{
            cout<<endl;
        }
        
    }
    

    return 0;
}


//mo bai da shen zuo pin