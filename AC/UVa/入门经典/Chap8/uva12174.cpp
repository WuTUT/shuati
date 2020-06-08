#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn=100000 +5;
int in[3*maxn],ok[maxn*2],c[maxn];
int main(){
    
    freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T){
        T--;
        int n,s;
        scanf("%d%d",&s,&n);
        memset(in,-1,sizeof(in));
        memset(ok,0,sizeof(ok));
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++){
            scanf("%d",&in[i]);
        }
        int tot=1;ok[0]=1;c[in[0]]++; 
        
        for(int i=1;i<s;i++){
            if(in[i]!=-1){
                if(c[in[i]]==0){
                tot++;
                }
                c[in[i]]++;
                
            }
            
            if(tot==i+1) ok[i]=1;
        }
        
        for(int i=s;i<n;i++){
            if(in[i-s]!=-1){
            c[in[i-s]]--;
            if(c[in[i-s]]==0){
                tot--;
            }
            }
            //printf("&&%d\n",in[i]);
            if(in[i]!=-1){
                if(c[in[i]]==0){
                 tot++;
                }
                c[in[i]]++;
            }
             
            // for(int ti=1;ti<=s;ti++){
            //     cout<<c[ti]<<" ";
            // }
            //     cout<<endl;
            if(tot == s) ok[i]=1;
        }
       
        for(int i=n;i<n+s-1;i++){
            if(in[i-s]!=-1){
                c[in[i-s]]--;
                if(c[in[i-s]]==0){
                    tot--;
                }
            }    
            
            if(tot == n+s-1-i) ok[i]=1;
        }
        // for(int i=0;i<n+s-1;i++){
        //     printf("%d ",ok[i]);
        // }
        // printf("\n");
        bool isok=true;
        int can=0;
        for(int i=0;i<s;i++){
            isok=true;
            for(int j=i;j<n+s-1;j+=s){
                 if(ok[j]!=1){
                    isok=false;
                    break;
                }
            }
               
            if(isok) {//printf("i is %d\n",i);
            can++;
            }    
        }
        if(can==n+1) can=s;
        printf("%d\n",can);
    }
    

    return 0;    
}

//????莫名ac了
//怎么设置窗口 如下
/*
    
        1 2 ... s-1 s .... s+n
                    3 4 3 ...1
ok[1]   [-----------]
          [-----------]
            [-----------]
              [-----------]
            .............  
ok[n]            [-----------]
            .............
ok[s+n]                    [----------]  
*/