#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
set<int> se;
vector<string> ans;
bool isdistinct(int i){
    if(i<10000) se.insert(0);
    while(i){
       se.insert(i%10);
       i/=10;
    }
    return se.size()==5;
}
bool isdistinct1(int i){
    if(i<10000) se.insert(0);
    while(i){
       se.insert(i%10);
       i/=10;
    }
    return se.size()==10;
}
int main(){
    //freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
    int n;
    scanf("%d",&n);
    while(n){
        bool flag=false;
        for(int i=1234;i<50000;i++){
            se.clear();
            if(isdistinct(i)){
                int res=i*n;
                if(res>98765){
                    break;
                }
                if(isdistinct1(res)){
                    printf("%05d / %05d = %d\n",res,i,n);
                    flag=true;
                }
            }
        }
        if(!flag){
            printf("There are no solutions for %d.\n",n);
        }
        
        scanf("%d",&n);
        if(n){
            cout<<endl;
        }
    }
    
    return 0;
}
//set 是很慢的，换成数组,anyway...