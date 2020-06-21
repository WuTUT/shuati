#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;
char v[10];
int cur;
int N;
vector<string> ans;
void dfs(int sum){
    if(cur >10 ) return ;
    if(sum > N ) return ;
    if(sum == N && cur == 10){
        string s;
        for(int i=0;i<9;i++){
            s.push_back(v[i]);
            s.push_back(' ');
            
        }
        s.push_back(v[9]);
        ans.push_back(s);
        return ;
    }
    for(int i=1;i<=3;i++){
        v[cur++]=i+'0';
        dfs(sum+i);
        cur--;
    }
    return;
}
int main(){
    freopen("data.in","r",stdin);
    scanf("%d",&N);
    dfs(0);
    int cnt=ans.size();
    cout <<cnt<<endl;
    for(int i=0;i<cnt;i++){
        cout << ans[i] ;
        cout <<endl;
    }

    return 0;
}