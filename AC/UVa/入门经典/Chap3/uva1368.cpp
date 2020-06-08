#include <stdio.h>
#include <string.h>
char d[52][1005];
int count[4][1005];
char ans[1005];
char to_dna(int i){
    if(i==0) return 'A';
    if(i==1) return 'C';
    if(i==2) return 'G';
    if(i==3) return 'T';

}
void pcount(int n){
    for(int i=0;i<4;i++){
        for(int j=0;j<n;++j){
            printf("%d ",count[i][j]);
        }
        printf("\n");
    }
    printf("end\n");
}
int main(){
   // freopen("data.in","r",stdin);
    int t;
    scanf("%d",&t);
    while (t)
    {
        t--;
        int m,n;
        int ha=0;
        
        scanf("%d%d",&m,&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                count[j][i]=0;
            }
        }
        
        //printf("%d %d",m,n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;++j){
                scanf("%c",&d[i][j]);
                while (d[i][j]=='\n')
                {
                    scanf("%c",&d[i][j]);
                }
                
               // d[i][j]=getchar();
                
                
                if(d[i][j]=='A') count[0][j]++;
                if(d[i][j]=='C') count[1][j]++;
                if(d[i][j]=='G') count[2][j]++;
                if(d[i][j]=='T') count[3][j]++;
            }
            //getchar();
        }
       // pcount(n);
        
       // printf("nnnn%d\n",n);
        for(int j=0;j<n;++j){
            int maxn=-1;
            for(int i=0;i<4;i++){
                if(maxn<count[i][j]){
                    maxn=count[i][j];
                    ans[j]=to_dna(i);
                }
                ha+=count[i][j];
            }
            ha-=maxn;
            
        }
        for(int i=0;i<n;++i){
            printf("%c",ans[i]);
        }
        
        printf("\n");
        printf("%d",ha);
        
        printf("\n");
    }
    
    return 0;
    
}


//scanf("%c",&c) 的读回车问题:getchar()=='\n' or EOF ...

//WA