#include <iostream>
#include <queue>
#include <cstdio>
#include <cassert>
using namespace std;
struct Node{
    char color;
    struct Node* c1,*c2,*c3,*c4;
    Node():color(' '),c1(NULL),c2(NULL),c3(NULL),c4(NULL){}
};
typedef struct Node* Quadtree;
Quadtree t1,t2,rest;
Quadtree buildtree(){
    Quadtree t=new Node();
    char c=getchar();
    while(c=='\n') c=getchar();
    t->color=c;
    cout<<"color"<<" "<<c<<endl;
    if(c=='p'){
        t->c1=buildtree();
        t->c2=buildtree();
        t->c3=buildtree();
        t->c4=buildtree();
    }
    return t;
}
void freetree(Quadtree root){
    if(root == NULL) return;
    freetree(root->c1);
    freetree(root->c2);
    freetree(root->c3);
    freetree(root->c4);
    delete root;
}
Quadtree mergetree(Quadtree t1,Quadtree t2){
    if(t1 == NULL) return t2;
    if(t2 == NULL) return t1;
    Quadtree t=new Node();
    if((t1->color=='f')||(t2->color=='f')){
        t->color='f';
        return t;
    }
    if((t1->color=='e')&&(t2->color=='e')){
        t->color='e';
        return t;
    }
    
    t->c1=mergetree(t1->c1,t2->c1);
    t->c2=mergetree(t1->c2,t2->c2);
    t->c3=mergetree(t1->c3,t2->c3);
    t->c4=mergetree(t1->c4,t2->c4);

    t->color='p';
    return t;
}
void printtree(Quadtree t){
    if(!t) return;
    printf("%c",t->color);
    printtree(t->c1);
    printtree(t->c2);
    printtree(t->c3);
    printtree(t->c4);
}
queue<Quadtree> q;
int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T;
    cin>>T;
    
    while (T)
    {
        T--;
        
        while (!q.empty())
        {
            q.pop();
        }
        
        freetree(t1);
        freetree(t2);
        freetree(rest);
        // if(t1!=NULL){
        //     cout<<t1->color<<endl;
        // }
        // if(t2!=NULL){
        //     cout<<t2->color<<endl;
        // }
        // if(rest!=NULL){
        //     cout<<rest->color<<endl;
        // }
         assert(t1==NULL);
        // assert(t2==NULL);
        // assert(rest==NULL);
        t1= buildtree();
        //printtree(t1);
        //cout<<endl;
        
        t2= buildtree();
        //printtree(t2);
        //cout<<endl;
        rest=mergetree(t1,t2);
        //printtree(rest);
        //cout<<endl;
        q.push(rest);
        int ans=0;int size;
        int lev=1024;
        
        while (!q.empty())
        {
        
            int tmp=0;
            size=q.size();
            //cout<<size<<endl;
            for(int i=0;i<size;i++){
                
                Quadtree t=q.front();
                q.pop();
                if(t->color=='f'){
                    tmp++;
                }
                if((t->c1)) q.push(t->c1);
                if((t->c2)) q.push(t->c2);
                if((t->c3)) q.push(t->c3);
                if((t->c4)) q.push(t->c4);
            }
            //cout<<tmp<<endl;
            tmp=tmp*lev;
            
            ans += tmp;
            lev/=4;

        }
        
        cout<<"There are "<<ans<<" black pixels."<<endl;
    }
    
    return 0;
}