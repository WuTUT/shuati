#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n;
int l;
int ans[100];
int count=0;
void dfs(int id){
    if(count==n){
        for(int i=0;i<id;i++){
            if(i%4==0 &&i){
                if(i%64==0){
                    if(i!=id){
                        printf("\n");
                    }
                    
                }else{
                    printf(" ");
                }
            }
            
            printf("%c",ans[i]+'A');
            
        }
        printf("\n%d\n",id);
        return;
    }
    for(int i=0;i<l;i++){
        ans[id]=i;
        int ok=1;
        for(int j=1;j*2<=id+1;j++){
            int ok_k=0;
            for(int k=0;k<j;k++){
                
                if(ans[id-k]!=ans[id-k-j]){
                    ok_k=1;
                    break;
                }
            }
            if(!ok_k){
                ok=0;
                break;
            }
        }
        if(ok){
            count++;
            dfs(id+1);
            if(count==n){return;}
        }
    }
}
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);   
    while(cin>>n>>l && (n || l)){
        count=0;
        dfs(0);
    }
    return 0;
}