#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=100000 +5;
int n;
struct order{
    int q;int d;
    order(int q,int d):q(q),d(d){}
    bool operator <(const struct order& o)const {
        
        return q<o.q;
    }
};
vector<order> v;
bool cmp(const struct order& o1,const struct order& o2){
    if(o1.d==o2.d) return o1.q<o2.q;
    return o1.d<o2.d;
}
priority_queue<struct order,vector<struct order> > pq;
int main(){
    
    //freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        v.clear();
        while(!pq.empty()) pq.pop();
        scanf("%d",&n);
        int q,d;
        for(int i=0;i<n;i++){
            scanf("%d%d",&q,&d);
            v.push_back(order(q,d));
        }
        sort(v.begin(),v.end(),cmp);
        int cur=0;
        for(int i=0;i<n;i++){
            if(cur+v[i].q<=v[i].d){
                pq.push(v[i]);
                cur+=v[i].q;
            }else{
                if(pq.empty()) continue;
                order tmp=pq.top();
                if(v[i].q<tmp.q){
                    cur=cur-tmp.q+v[i].q;
                    pq.pop();
                    pq.push(v[i]);
                }
            }
        }
        printf("%d\n",(int)pq.size());
        if(T) printf("\n");
    }
    

    return 0;    
}