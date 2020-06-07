#include <iostream>
using namespace std;
const int maxn=15;
int A[maxn]={1,2,3,4,4,5,6};
//           0 1 2 3 4 5 6 
int my_lower_bound(int l,int r,int x){
    
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
}
int my_upper_bound(int l,int r,int x){
    
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
}

int main(){
  cout <<  my_lower_bound(0,6,4) <<endl;
  cout <<  my_upper_bound(0,6,4) <<endl;
  return 0;
}