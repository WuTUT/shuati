#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int maxn=52,INF=0x7f7f7f7f;
int f[maxn][maxn];
char s[maxn];
int main(){ 
    freopen("data.in","r",stdin);
    // char ch;int n=0;
    // while( (ch=getchar())!='\n' && ch != EOF){
    //     s[++n]=ch;
    // }
    cin>>s;int  n=strlen(s);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            f[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++){
        f[i][i]=1;
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            if(s[i-1]==s[j-1]) f[i][j]=min(f[i][j-1],f[i+1][j]);
            else{
                for(int k=i;k<j;k++){
                    f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
                }
            }
            
        }
    }
    cout << f[1][n] <<endl;
    return 0;
}
