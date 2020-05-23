#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
int n;
int g[66][66];
int index;
vector<int> ansf;
int dfs(int ex,int ey,int nsize){
    bool iswhite=true;
    bool isblack=true;
    for(int i=ex;i<ex+nsize;i++){
        for(int j=ey;j<ey+nsize;j++){
            if(g[i][j]!=0){
                iswhite=false;
                if(!isblack){
                    break;
                }
            }
            else{
                isblack=false;
                if(!iswhite){
                    break;
                }
            }
        }
        if(!iswhite && !isblack){
            break;
        }
    }

    if(iswhite){
        index++;
    }
    else if(isblack){
        index++;
    }
    int nextsize=nsize>>1;
    int c1=dfs(ex,ey,nextsize);
    int c2=dfs(ex+nextsize,ey,nextsize);
    int c3=dfs(ex,ey+nextsize,nextsize);
    int c4=dfs(ex+nextsize,ey+nextsize,nextsize);
    
}
void f(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&g[i][j]);
        }      
    }
    index=0;
    ansf.clear();
    dfs(0,0,8);
}
void rf(){

}
int main(){
    int kase=0;
    
    scanf("%d",&n);
    while(n!=0){
        if(n>0){
            
            f();
        }
        else{
            rf();
        } 
        scanf("%d",&n);
    }
    return 0;
}   
