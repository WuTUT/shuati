#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
using namespace std;
vector<vector<int> > g;
queue<int> q; 
int getid(char c1,char c2){
    if(c1=='0'||c2=='0') return -1;
    int res=(c1-'A')*2;
    if(c2=='+') return res+0;
    else return res+1;
}
bool bfs(){
    int indg[52]={0};

    for(int i=0;i<g.size();i++){
        for(int j=0;j<g[i].size();j++){
            indg[g[i][j]]++;
        }
    }
    int count=0;
    for(int i=0;i<52;i++){
        if(indg[i]==0){
            q.push(i);
            
        }
    }
    while(!q.empty()){
      int i=  q.front();
      q.pop();count++;
        for(int j=0;j<g[i].size();j++){
            if(--indg[g[i][j]] == 0){
                q.push(g[i][j]);
            }
        }
    }
    return count==52;
}
int main(){
    int n;
   // freopen("data.in","r",stdin);
    while (cin>>n)
    {
        while(!q.empty()){
            q.pop();
        }
        for(int i=0;i<g.size();i++){
            g[i].clear();
        }
        g.clear();
        g.resize(52);
        string s;
        for(int i=0;i<n;i++){
            cin>>s;   
            int node[4];
            for(int j=0;j<4;j++){
                node[j]=getid(s[j*2],s[j*2+1]);
            }
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    if(j!=k && node[j]!=-1 && node[k]!=-1){
                            g[node[j]^1].push_back(node[k]);
                    }
                }
            }

        }
        bool a=bfs();
        if(a) cout<<"bounded"<<endl;
        else
        {
            cout<<"unbounded"<<endl;
        }
        
    }
    
    return 0;
}

//观光题...