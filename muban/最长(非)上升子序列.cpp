#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e5+5,INF=0x7fffffff;
int a[maxn];
int dp[maxn];
int main(){
    freopen("data.in","r",stdin);
    int n=0;int x;
    while(cin>>x){
        a[++n]=x;
    }
    
    dp[1]=a[1];int len=1;
    for(int i=2;i<=n;i++){
        if(a[i]<=dp[len]){
            dp[++len]=a[i];
        }
        else{
            int l=1,r=len;
            while(l<r){ //upper_bound with greater<>
                int mid=l+(r-l)/2;
                if(a[i]>dp[mid]){
                    r=mid;
                }else{
                    l=mid+1;
                }
            }
            dp[l]=a[i];    
        }
    }
    cout<<len<<endl;

    
    dp[1]=a[1];len = 1;

    for(int i=2;i<=n;i++){
        if(a[i]>dp[len]){
            dp[++len]=a[i];
        }
        else{
            int l=1,r=len;
            while(l<r){
                int mid=l+(r-l)/2;// lower_bound
                if(dp[mid]>=a[i]){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
            dp[l]=a[i];
        }    

    }
    cout << len<<endl;
    return 0;

}

//LIS O(nlogn)  https://www.luogu.com.cn/problem/P1020
//upper_bound and lower_bound

/*
    lower bound
    int l,r;
    while(l<r){
        int mid=l+(r-l)/2;
        if(A[mid]>=x){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return l;


    upper bound
    int l,r;
    while(l<r){
        int mid=l+(r-l)/2;
        if(A[mid]>x){
            r=mid;
        }
        else{
            l=mid+1;
        }    
    }
    return l;

*/