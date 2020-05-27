#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);  
    int n;
    scanf("%d",&n);
    long long sum;
    long long sum1;
    int a;
    while(n){
        sum=0;sum1=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            sum1+=a;
            sum=sum+abs(sum1);
        
        }
        printf("%lld\n",sum);
        scanf("%d",&n);
        
    }
    return 0;
}