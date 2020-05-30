#include<queue>
#include<iostream>
#include<cstdio>
#include<string>
#include <set>
using namespace std;
const int a[3]={2,3,5};
typedef long long LL;
int main(){
    //freopen("data.in","r",stdin);
    LL ans;
    priority_queue<LL,vector<LL>,greater<LL> > pq;
    set<LL> s;
    pq.push(1);
    s.insert(1);
    LL x;
    for(int i=1;;){
        if(i==1500){
            cout<<"The 1500'th ugly number is "<<x<<"."<<endl;
            break;
        }
        LL t=pq.top();pq.pop();
        for(int j=0;j<3;j++){
            LL aans=t*a[j];
            if(s.find(aans)==s.end()){
                pq.push(aans);
                s.insert(aans);
                i++;
            }
        }

    }
    
    return 0;
}