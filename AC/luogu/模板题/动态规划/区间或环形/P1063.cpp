#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=205;

// int a[maxn];
// int f[maxn][maxn];
// int main(){
//     freopen("data.in","r",stdin);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++){
//         scanf("%d",&a[i]);
//     }
//     for(int i=n+1;i<2*n;i++){
//         a[i]=a[i-n];
//     }
    
//     for(int len=3;len<=n;len++){
//         for(int i=1;i+len-1<2*n;i++){
//             int j=i+len-1;
            
//             for(int k=i+1;k<j;k++){
//                 f[i][j]=max(f[i][j],f[i][k]+f[k][j]+a[i]*a[k]*a[j]);
//             }
//             cout << i <<" "<< j <<"  "<<f[i][j] <<endl;
//         }
//     }
//     int ans=0;
//     for(int i=1;i<=n;i++){
//         ans=max(ans,f[i][i+n-1]+a[i]*a[i+n-1]*a[i]);
//     }
//     cout <<ans;
//     return 0;
// }
struct matrix{
    int a,b;
    matrix(){}
    
}ma[maxn];
int a[maxn];
int f[maxn][maxn];
int main(){
    freopen("data.in","r",stdin);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        ma[i].a=a[i];
        ma[i].b=a[i+1];
    }
    ma[n].a=a[n];
    ma[n].b=a[1];
    for(int i=n+1;i<2*n;i++){
        ma[i].a=ma[i-n].a;
        ma[i].b=ma[i-n].b;
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<2*n;i++){
            int j=i+len-1;
            for(int k=i;k<j;k++){
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+ma[i].a*ma[k].b*ma[j].b);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,f[i][i+n-1]);
    }
    cout << ans;
    return 0;
}
//矩阵乘法+环形 裸题