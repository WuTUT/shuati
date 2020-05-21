#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
string s1,s2;
void dfs(int l1,int r1,int l2,int r2){
    if(l1>r1) return;
    if(l2>r2) return;
    int i;
    for(i=l2;i<=r2;i++){
        if(s2[i]==s1[l1]){
            break;
        }
    }
   
    dfs(l1+1,l1+i-l2,l2,i-1);
    dfs(l1+i+1-l2,r1,i+1,r2);
    printf("%c",s1[l1]);
}
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    
    while(cin>>s1){
        cin>>s2;
        
        dfs(0,s1.length()-1,0,s2.length()-1);
        cout<<endl;
    }
    return 0;    
}