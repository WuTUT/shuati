#include <stdio.h>
#include <string.h>
int main(){
    //freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
    char c;
    int count=0;
    int line1=0;
    while (1)
    {
        char puz[5][5];
        int br,bc;
        
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                c=getchar();
                if(c=='Z'){
                    return 0;
                }
                else{
                    if(i==0&&j==0){
                        while (c=='\n')
                        {
                        c=getchar();
                        }
                        if(line1)
                            printf("\n");
                        else
                        {
                            line1=1;
                        }
                        
                    }
                    
                }
                if(j==4){
                    if(c=='\n'){
                        c=' ';
                    }
                    else
                    {
                        getchar();
                    }
                }
                if(c==' '){
                    br=i;
                    bc=j;
                }
                puz[i][j]=c;
                
            }
            
        }
        int good=1;
        
        while ((c=getchar())!='0')
        {
            if(c=='\n'){
                continue;
            }
            if(c==' '){
                continue;
            }
            if(good){
                if(c=='A'&&br>0){
                puz[br][bc]=puz[br-1][bc];
                br--;
                }
                else if(c=='B'&&br<4)
                {
                    puz[br][bc]=puz[br+1][bc];
                    br++;
                }
                else if(c=='L'&&bc>0)
                {
                    puz[br][bc]=puz[br][bc-1];
                    bc--;
                }
                else if(c=='R'&&bc<4)
                {
                    puz[br][bc]=puz[br][bc+1];
                    bc++;
                }
                else{
                    good=0;
                }
            }  
        }
        getchar();
        printf("Puzzle #%d:\n",++count);
        if(good){
            puz[br][bc]=' ';
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    printf("%c ",puz[i][j]);
                }
            printf("\n");
            }
        }
        else
        {
            printf("This puzzle has no final configuration.");
        }
        
        
    }
    return 0;
}


//Presentation error  改不对 不改了