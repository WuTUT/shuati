#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;
char a[100005];
char q[100005];
int main(){
    
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int n,d;
    scanf("%d%d",&n,&d);getchar();
    while(n ||d){

        scanf("%s",a);

        int l=0,r=0;
        int npop=0;
        for(int i=0;i<n;i++){
            while(r-l>0 && q[r-1]<a[i] && npop<d){
                r--;
                npop++;
            }
            
            q[r++]=a[i];

        }   
        // for(int i=l;i<r;i++){
        //     printf("%c",q[i]);
        // }
        for(int i=l;i<n-d;i++){
            printf("%c",q[i]);
        }
       

        printf("\n");
        scanf("%d%d",&n,&d);getchar();
    }
    return 0;
}

//单调队列入队时 如果抛的少于d个就一直把前面的抛出去
//O(n)
//排序删除最坏1111这种，tle
