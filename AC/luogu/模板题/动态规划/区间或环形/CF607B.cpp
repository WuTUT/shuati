#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=505,INF=0x7f7f7f7f;
int a[maxn];
int f[maxn][maxn];
int n;
int main(){
    freopen("data.in","r",stdin);
    cin >> n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
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
            if(a[i]==a[j]){
                if(len == 2){
                    f[i][j]=1;
                }
                else 
                    f[i][j]=f[i+1][j-1];
            } 
          //  else{  去掉else 就对了
                for(int k=i;k<j;k++){
                    f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
                }
          //  }
            
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<i;j++){
    //         cout << "  "; 
    //     }
    //     for(int j=i;j<=n;j++){
    //         cout << f[i][j]<<" ";
    //     }
    //     cout <<endl;
    // }
    cout <<f[1][n]<<endl;
    return 0;
} 
// DP 有分类的情况，分开取还是取交集 有没有else要想好 ，这题这样的，不加这个else 又没有影响，加了就会出错