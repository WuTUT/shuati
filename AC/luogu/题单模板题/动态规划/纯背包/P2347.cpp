#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int a[7];
int b[7]={0,1,2,3,5,10,20};
int f[1001];int cnt;

int main(){
    freopen("data.in","r",stdin);
    for(int i=1;i<=6;i++){
        cin >> a[i];
    }
    for(int i=0;i<=a[1];i++){
        f[i]=1;
    }
    for(int i=2;i<=6;i++){
        for(int j=1000;j>=0;j--){
            int t =min(j,a[i]*b[i]);
            for(int k=0;k<=t;k+=b[i]){
                f[j]=max(f[j],f[j-k]);
            }
        }
        
    }
    for(int i=1;i<=1000;i++){
        if(f[i]) cnt++;
    }
    cout <<"Total=" <<cnt<<endl;
    return 0;
}