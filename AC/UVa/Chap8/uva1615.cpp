#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int maxn=100000 +5;
int L;int D;
struct Node{
    double st;
    double en;
    Node(int x,int y){
      st=max(x-sqrt(D*D-y*y),0.0);
      en=min(double(L),x+sqrt(D*D-y*y));
    }

};
bool cmp(const struct Node& x,const struct Node& y){ //should be const ,or compile error
    if(x.en==y.en) return x.st>y.st;
    return x.en<y.en;
}
vector<Node> v;
int main(){
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int n;
    
    while(cin>>L){
        cin>>D;cin>>n;
        int x,y;
        v.clear();
        for(int i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            v.push_back(Node(x,y));
        }
        sort(v.begin(),v.end(),cmp);
        int ans=1;int id=0;
        for(int i=1;i<n;i++){
            if(v[id].en>=v[i].st){

            }
            else{
                id=i;
                ans++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}