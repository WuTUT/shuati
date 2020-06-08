#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
void print_permutation(int n,int* a,int cur){
    if(cur==n){
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    else{
       
        for(int i=1;i<=n;i++){
            int ok=1;
            for(int j=0;j<cur;j++){
                if(a[j]==i){
                    ok=0;
                }
            }
            if(ok){
                a[cur]=i;
                print_permutation(n,a,cur+1);
            }
        }
    }
}
void print_permutation_P(int n,int * P,int* a,int cur){
    if(cur==n){
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    else{
       
        for(int i=0;i<n;i++)
            if(!i||P[i]!=P[i-1]){
                
                int cnt1=0;int cnt2=0;
                for(int j=0;j<n;j++) 
                    if(P[i]==P[j])
                        cnt1++;
                for(int j=0;j<cur;j++)
                    if(P[i]==a[j])
                        cnt1++;
            
                if(cnt1>cnt2){
                    a[cur]=P[i];
                    print_permutation_P(n,P,a,cur+1);
                }
            }
    }
}
int main(){
    const int n=4;
    int P[n]={1,2,3,4};
    //scanf("%d",&n);  
    //int a[10];
    //print_permutation_P(3,P,a,0);
    do{
        for(int i=0;i<n;i++) printf("%d",P[i]);
        printf("\n");    
    }while(next_permutation(P,P+n));
    return 0;
}