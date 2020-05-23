#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n;
int g[66][66];
char rg[66][66];
vector<int> path;
vector<int> ansf;
void printvector(vector<int> &v){
    for(int i=0;i<v.size();i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}
void dfs(int ex,int ey,int nsize,int forward){
    //cout<<ex<<" "<<ey<<" "<<" "<<nsize<<" "<<forward<<endl;
    path.push_back(forward);
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
        path.pop_back();
        return;
    }
    else if(isblack){
        int tmp=0;
        if(path.empty()){
            ansf.push_back(0);
            return;
        }
        for(int i=path.size()-1;i>0;i--){
            tmp=tmp*5+path[i];
        }
        ansf.push_back(tmp);
        path.pop_back();
        return;
    }
    int nextsize=nsize>>1;
    
    dfs(ex,ey,nextsize,1);
    dfs(ex,ey+nextsize,nextsize,2);
    dfs(ex+nextsize,ey,nextsize,3);
    dfs(ex+nextsize,ey+nextsize,nextsize,4);
    path.pop_back();
        return;
}
void f(){
    getchar();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c=getchar();
            g[i][j]=c-'0';
        }
        getchar();
    }
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%d ",g[i][j]);
    //     }      
    //     printf("\n");
    // }
    path.clear();
    ansf.clear();
    dfs(0,0,n,0);
    sort(ansf.begin(),ansf.end());
    int anssize=ansf.size();
    int pcount=0;
    for(int i=0;i<anssize;i++){
        pcount++;
        if(pcount==12){
            pcount=0;
            if(i!=anssize-1)
                printf("%d\n",ansf[i]);
            else 
                printf("%d",ansf[i]);
        }
        else{
            if(i!=anssize-1)
                printf("%d ",ansf[i]);
            else 
                printf("%d",ansf[i]);
        }
        
    }
    if(anssize!=0) printf("\n");
    printf("Total number of black nodes = %d\n",anssize);
}
void makeg(vector<int>& v){
    if(v.empty()) return;
    int ex=0;int ey=0;int nsize=n;
    for(int i=0;i<v.size();i++){
        nsize=nsize>>1;
        if(v[i]==2){
            ey+=nsize;
        }
        else if(v[i]==3){
            ex+=nsize;
        }
        else if(v[i]==4){
            ex+=nsize;
            ey+=nsize;
        }
        
    }
    for(int i=ex;i<ex+nsize;i++){
        for(int j=ey;j<ey+nsize;j++){
            rg[i][j]='*';
        }
    }
    return;
}
void rf(){
    n=-n;
    int index;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rg[i][j]='.';
        }
    }
    scanf("%d",&index);
    if(index==0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rg[i][j]='*';
            }
        }
        scanf("%d",&index);
        return;
    }
    while(index!=-1){
        vector<int> indexpath;
        while(index!=0){
            indexpath.push_back(index%5);
            index/=5;
        }
        makeg(indexpath);
        scanf("%d",&index);
    }
    return;
}
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int kase=0;
    
    scanf("%d",&n);
    while(n!=0){
        printf("Image %d\n",++kase);
        if(n>0){
            
            f();
        }
        else{
            rf();
            for(int i=0;i<n;i++){
                for (int j = 0; j < n; j++)
                {
                    printf("%c",rg[i][j]);
                }
                printf("\n");
            }
        }
         
        scanf("%d",&n);
        if(n!=0)
            printf("\n");
    }
    return 0;
}   
