//#define LOCAL
#include <stdio.h>
#include <string.h>
int count[10];
int main(){
    #ifdef LOCAL
    freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    #endif 
    int t;
    scanf("%d",&t);
    
    while(t){
        t--;
        int n;
        scanf("%d",&n);
        memset(count,0,sizeof(count));
        for(int i=1;i<=n;++i){
            int num=i;
            while(num){
                count[num%10]++;
                num/=10;
            }
        }
        printf("%d",count[0]);
        for(int i=1;i<10;++i){
           printf(" %d",count[i]);
        }
        printf("\n");
    }
    
}
