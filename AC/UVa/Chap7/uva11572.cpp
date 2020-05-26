#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <cstdlib>
using namespace std;

unordered_set<int> set1;
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T){
        T--;
        int n;
        set1.clear();
        scanf("%d",&n);
        
         int a;
         vector<int> v;
         //v.resize(n);
         int l,r;
         l=r=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            v.push_back(a);
        }
        int ans=0;
        while(r<n){
            
            if(set1.find(v[r])==set1.end()){
                set1.insert(v[r]);
            }
            else{
                while(v[l]!=v[r]){
                    set1.erase(v[l]);
                    l++;
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        printf("%d\n",ans);
    }  
    
   
   
    return 0;
}

//resize 不能和pushback混用！！！！！！！