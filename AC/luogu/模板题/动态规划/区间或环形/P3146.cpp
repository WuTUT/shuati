#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn= 250;
int a[maxn];
int f[maxn][maxn];
int main(){
    freopen("data.in","r",stdin);
    int n;
    cin>>n;
    int maxnum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[i][i]=a[i];
        maxnum = max(maxnum,a[i]);
    }
    
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            for(int k=i;k<j;k++){
                if(f[i][k]==f[k+1][j])
                    f[i][j]=max(f[i][j],f[i][k]+1);
                    
            }
            maxnum=max(maxnum,f[i][j]);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<i;j++){
    //         cout <<"  "; 
    //     }
    //     for(int j=i;j<=n;j++){
    //         cout << f[i][j]<<" ";
    //     }
    //     cout <<endl;
    // }
    cout << maxnum<<endl;
    return 0;
}

//合并石子改了一点