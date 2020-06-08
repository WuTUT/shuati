#include <iostream>
#include <cstdio>
#include <unordered_map>

#include <vector>
using namespace std;
int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int n,m;

    while(cin >> n>>m ){
        std::unordered_map<int,vector<int> > ha;
        int x;
        for(int i=1;i<=n;i++){
            cin >> x;
            ha[x].push_back(i);
        }
        int k,v;
        while(m--){
            scanf("%d%d",&k,&v);
            if(ha.find(v) == ha.end() || ha[v].size()<k) cout << 0<<endl;
            else cout << ha[v][k-1] << endl;
        }

    }
    
    return 0;
}