//#define LOCAL
#include <stdio.h>
#include <string.h>
#include <ctype.h>
const double saw[20]={0,0,12.01,0,0,0,0,1.008,0,0,0,0,0,14.01,16.00};
int main(){
    #ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    while (t)
    {
        t--;
        char s[102];
        scanf("%s",s);
        int len=strlen(s);
        int num=0;double an=0;
        
        double tot=0;int i;
        for(i=0;i<len;++i){
            if(isalpha(s[i])){
                
                
                if(num==0)
                num=1;
                tot+=an*num;
                num=0;
                
                an=saw[s[i]-'A'];

            }
            else
            {
                num=num*10+s[i]-'0';
            }
            
        }
        i--;
        if(isalpha(s[i])){
            tot+=saw[s[i]-'A'];
        }
        else
        {
            tot+=num*an;
        }
        
        printf("%.3lf\n",tot);
    }
    
}
