#include <stdio.h>
#include <string.h>
int main(){
    int t;
    scanf("%d",&t);
    while (t)
    {
        t--;
        char s[100];
        scanf("%s",s);
        int n=1;
        int len=strlen(s); 
          
        while(1){
            int count=0; 
            for(int i=0;i<len;++i){
                if(s[i]==s[(i+n)%len]){
                    count++;
                }
            }
            if(count==len)
                break;
            n++;    
        }
        printf("%d\n",n);
        if(t!=0){
            printf("\n");
        }
    }
    
    return 0;
}


//当成环形的字符串
