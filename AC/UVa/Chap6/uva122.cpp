#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;
const int MAXN=300;
char s[MAXN];

struct Node
{
    bool setted;
    int val;
    struct Node* l;
    struct Node* r;
    Node():setted(false),val(0),l(NULL),r(NULL){}
};
typedef struct Node* Tree;
Tree root;

vector<int> ans;
queue<Tree> q;

void freeTree(Tree root){
    if(root){
        freeTree(root->l);
        freeTree(root->r);
        delete root;
    }
    return;
}
bool addNode(int v,char* s){
    int len=strlen(s);
    Tree t=root;
     
    for(int i=0;i<len-1;i++){
        
        if(s[i]=='L'){
            
            if(t->l == NULL){
                t->l=new Node();
                
            }
            t=t->l;
        }
        else if(s[i]=='R')
        {
            
            if(t->r == NULL){
                t->r=new Node();
                
            }
            t=t->r;
        }
        
    }
    if(t->setted){
        return false;
    }
    else{
        t->setted=true;
        t->val=v;
        return true;
    }
}

int main(){
    //freopen("data.in","r",stdin);
    while (1)
    {
        
        bool add_success=false;
        bool iscomplete=true;
        freeTree(root);
        root=new Node();
       
        while (!q.empty())
        {
            q.pop();
        }
        ans.clear();
        while (1)
        {
            if(scanf("%s",s)!=1) return 0;
            if(!strcmp(s,"()")) break;
            int v;
            sscanf(s+1,"%d",&v);
            add_success=addNode(v,strrchr(s,',')+1);
            if(add_success){
                continue;
            }
            else
            {   
                iscomplete=false;
               // break;
            }
            
        }
        Tree t=root;//root couldn't be NULL;
        q.push(t);
        
        while (!q.empty())
        {
            t=q.front();  q.pop();
            if(t->setted){
                ans.push_back(t->val);
            }
            else
            {
                iscomplete=false;
                break;
            }
            
            if((t->l) !=NULL) q.push(t->l);
            if((t->r) !=NULL) q.push(t->r);

        }
        if(iscomplete==false){
            cout<<"not complete"<<endl;
        }
        else
        {
            for(int i=0;i<ans.size();i++){
                if(i==0)
                    cout<<ans[i];
                else
                {
                    cout<<" "<<ans[i];
                }
            }
            cout<<endl;    
                
        }
        
    }
    
    
    return 0;    
}

//DO NOT QUIT when reading input 