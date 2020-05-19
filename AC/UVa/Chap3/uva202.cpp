#include <stdio.h>
#include <string.h>

int s[4000];
int y[4000];
int main(){
   // freopen("data.in","r",stdin);
    int a,b;


    int count=0;
    
    while (scanf("%d%d",&a,&b)==2)
    {   
        int astore=a;
        int lens=0;
        int start=0;
        int isfind=0;
        for(int i=0;;i++){
            s[i]=a/b;
            
            y[i]=a%b;
            a=(a%b)*10;
            for(int j=0;j<i;++j){
                if(y[j]==y[i]){
                    lens=i-j;
                    start=j+1;
                    isfind=1;
                    break;
                }
            }
            if(isfind){
                break;
            }
        }
        printf("%d/%d = ",astore,b);
        printf("%d.",s[0]);
        for(int i=1;i<start;++i){
            printf("%d",s[i]);
        }    
        printf("(");
        if(lens<=50){
            for(int i=start;i<start+lens;i++){
                printf("%d",s[i]);
            }
        }else{
            for(int i=start;i<start+50;i++){
                printf("%d",s[i]);
            }
            printf("...");
        }
        
        printf(")\n");
        printf("   %d = number of digits in repeating cycle",lens);
        
        printf("\n\n");    
    }
    return 0;
}


//循环小数的循环节