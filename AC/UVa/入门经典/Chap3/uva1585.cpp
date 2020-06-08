#define LOCAL
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    #ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    #endif
    int t;
    char s[100];
    scanf("%d",&t);
    while (t)
    {
        t--;
        scanf("%s",s);
        int len=strlen(s);
        int score=0;
        int before=0;
        for(int i=0;i<len;i++){
            if(s[i]=='O'){
                before++;
                if(before>1){
                
                score+=before;
            }
            else
            {
                score+=1;
            }
            
            }
            else
            {
              before=0;   
            }
               
        }
        printf("%d\n",score);
    }
    
    return 0; 
}

