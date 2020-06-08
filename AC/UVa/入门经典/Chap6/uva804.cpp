#include<iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <list>
using namespace std;
const int maxn=105;
int tokens[maxn];
struct transition
{
    int out[maxn];
    int in[maxn];
    
};
vector<struct transition> vt;
int main(){
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int np;
    scanf("%d",&np);
    int kase=0;
    while (np)
    {
        vt.clear();
        
        for(int i=1;i<=np;i++){
            scanf("%d",&tokens[i]);
        }
        int nt;
        scanf("%d",&nt);
        for(int i=0;i<nt;i++){
            struct transition tr;
            memset(&tr,0,sizeof(struct transition));
            int buf;scanf("%d",&buf);
            while(buf!=0){
                if(buf<0){
                   tr.out[-buf]++;
                }
                else{
                   tr.in[buf]++;
                }
                scanf("%d",&buf);
            }
            vt.push_back(tr);
        }
        int vtsize=vt.size();
        int nf;scanf("%d",&nf);
        bool islive=true;
        int ni;
        for(ni=1;ni<=nf;ni++){
            bool istrans=false;
            for(int i=0;i<vtsize;i++){
                bool cantrans=true;
                for(int j=1;j<=np;j++){
                    if(vt[i].out[j]>tokens[j]){
                        cantrans=false;
                        break;
                    }
                }
                if(cantrans){
                    for(int j=1;j<=np;j++){
                        tokens[j]-=vt[i].out[j];
                        tokens[j]+=vt[i].in[j];
                    }
                    istrans=true;
                    break;
                }
            }
            if(!istrans){
                islive=false;
                break;
            }
        }
        if(islive){
            printf("Case %d: still live after %d transitions\n",++kase,nf);
        }
        else{
            printf("Case %d: dead after %d transitions\n",++kase,ni-1);
        }
        printf("Places with tokens:");
            for (int i=1;i<=np;i++)
            {
               if(tokens[i]>0){
                   printf(" %d (%d)",i,tokens[i]);
               } 
            }
        printf("\n\n");
        scanf("%d",&np);
    }
    
    
}
