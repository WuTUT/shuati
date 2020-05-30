#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int s[30];
int pos[30];
vector<int> g[30];
int main(){
    
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    char c;
    
    while((c=getchar())!='#'){
        
        fill(g,g+n+1,vector<int>{});
        n=-1;
        while(c!='\n'){
            int nodei=c-'A';
            n=max(nodei,n);
            c=getchar();
           // if(c!=':'&&c!='\n'){continue;}
            while((c=getchar())<='Z'&& (c>='A')){
                g[nodei].push_back(c-'A');
                g[c-'A'].push_back(nodei);
                n=max(c-'A',n);
            }
            if(c=='\n') break;
            c=getchar();
        }
        
        for(int i=0;i<=n;i++){
            s[i]=i;
            
        }
        int ans[30];
        int minbw=100000;
        do{
            
            for(int i=0;i<=n;i++){
                pos[s[i]]=i;
            }
            int maxbw=-1;
            for(int i=0;i<=n;i++){
                int gisize=g[i].size();
                
                for(int j=0;j<gisize;j++){
                    maxbw= max(maxbw,abs(pos[g[i][j]]-pos[i]));
                    // if(maxbw>=minbw){
                    //     break;
                    // } 
                }
                // if(maxbw>=minbw){
                //         break;
                // } 
            }
            if(minbw>maxbw){
                
                memcpy(ans,s,sizeof(ans));
                minbw=maxbw;
            }
            
        }while(next_permutation(s,s+n+1));//s+n+1 [start,end)
        
        for(int i=0;i<=n;i++){
            printf("%c ",ans[i]+'A');
        }
        printf("-> %d\n",minbw);
    }
    return 0;
}