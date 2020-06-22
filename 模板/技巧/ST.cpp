//Sparse Table
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 1e5+5;
int st[maxn][21];
int lg[maxn];
int bin[21];
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int n,m;
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;lg[1]=0;
    for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
    bin[0]=1;
    for(int i=1;i<21;i++) bin[i]=bin[i-1]*2;
    
    for(int i=1;i<=n;i++){
        st[i][0]=read();
    }
    for(int j=1;j<21;j++){
        for(int i=1;i+bin[j]-1<=n;i++){
            st[i][j]=max(st[i][j-1],st[i+bin[j-1]][j-1]);
        }
    }
    
    int l,r;int p;
    for(int i=1;i<=m;i++){
        l=read();r=read();
        p=lg[r-l+1];
         
        printf("%d\n",max(st[l][p],st[r-bin[p]+1][p]));
    }
    return 0;
}