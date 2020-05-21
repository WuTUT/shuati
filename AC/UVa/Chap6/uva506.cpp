#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <list>
using namespace std;
const int maxn=16385;
vector<int> depend[maxn];
list<int> isneed[maxn];
int install[maxn];
int isexplicit[maxn];
list<int> l;
map<string,int> dict;  
vector<string> pset;
int ID(string s){
    if(dict.count(s)) return dict[s];
    pset.push_back(s);
    dict[s]=pset.size()-1;
    return pset.size()-1;
}
void Install(int id_pack0){
    
    int dependsize=depend[id_pack0].size();
    for(int i=0;i<dependsize;i++){
         int d_id=depend[id_pack0][i];
        isneed[d_id].push_back(id_pack0);
        if(install[d_id]==0){
            Install(d_id);
            
        }
    }
    l.push_back(id_pack0);
    install[id_pack0]=1;
    cout<<"   Installing "<<pset[id_pack0]<<endl;
}
void Remove(int id_pack0){
    int dependsize=depend[id_pack0].size();
    for(int i=0;i<dependsize;i++){
        isneed[depend[id_pack0][i]].remove(id_pack0); //#1
    }
    l.remove(id_pack0);
    install[id_pack0]=0;   
    for(int i=0;i<dependsize;i++){
        int d_id=depend[id_pack0][i];
        if(isexplicit[d_id]!=1 && isneed[d_id].empty() && install[d_id]){ //#2
            cout<<"   Removing "<<pset[d_id]<<endl;
            Remove(d_id);
        }
    }
}
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    string s;
    while(getline(cin,s)){
        cout<<s<<endl;
        stringstream ss(s);
        string ops;
        ss>>ops;
        string pack0;
        if(ops[0]=='E'){
            return 0;
            l.clear();
            memset(install,0,sizeof(install));
            memset(isexplicit,0,sizeof(isexplicit));
            fill(depend,depend+maxn,vector<int>{});
            fill(isneed,isneed+maxn,list<int>{});
            dict.clear();
            pset.clear();
            continue;
        }
        
        if(ops[0]=='D'){
            ss>>pack0;
            string depack;
            int id_pack0=ID(pack0);
            while(ss>>depack){
                depend[id_pack0].push_back(ID(depack));
            }
        }
        else if(ops[0]=='L')
        {
           for(auto i=l.begin();i!=l.end();i++){
               cout<<"   "<<pset[*i]<<endl;
           }
        }
        else if(ops[0]=='I'){
            ss>>pack0;
            int id_pack0=ID(pack0);
            if(install[id_pack0]!=0){
                cout<<"   "<<pack0<<" is already installed."<<endl;
            }
            else{
                isexplicit[id_pack0]=1;
                Install(id_pack0);
            }

        }
        else if(ops[0]=='R'){
            ss>>pack0;
            int id_pack0=ID(pack0);
            if(install[id_pack0]==0){
                cout<<"   "<<pack0<<" is not installed."<<endl;
            }
            else{
                if(!isneed[id_pack0].empty()){
                    cout<<"   "<<pack0<<" is still needed."<<endl;
                }else{
                    cout<<"   Removing "<<pack0<<endl;
                    isexplicit[id_pack0]=0;
                    Remove(id_pack0);
                }    
                
            }
        }
        
    }
    
    return 0;
}