#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
vector<int> v;
int n,k;
bool judge(int mid){
    int vsize=v.size();
    int num=0;
    for(int i=0;i<vsize;i++){
        num+=v[i]/mid;
        if(num>=k) return true;
    }
    return false;
}
int main(){
    freopen("data.in","r",stdin);
    scanf("%d%d",&n,&k);
    int m;int r;r=-1;long long sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        v.push_back(m);
        sum+=m;
        r=max(r,m);
    }
    
    int l=r/k;
    r=sum/k;
    if(r==0){
        printf("%d",r);
        return 0;
    } 
    int mid;
    while(l<r){
        //printf("%d %d\n",l,r);
        mid=l+(r-l)/2;
        if(!judge(mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    if(judge(l))
        printf("%d",l);
    else
    {
        printf("%d",l-1);
    }
    

}

//二分用l=mid+1跳出循环，但是之后要判断
//RE原因 mid=0，除0，重！要！