#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
typedef set<int> SET;
vector<SET> Setcache;
map<SET,int> IDcache;
#define ALL(x) x.begin(),x.end()
int ID(SET x){
    if(IDcache.count(x)){
        return IDcache[x];
    }
    Setcache.push_back(x);
    IDcache[x]=Setcache.size()-1;
    return IDcache[x];
}

int main(){
    //freopen("data.in","r",stdin);
    
    int t;
    cin>>t;

    while (t)
    {
        t--;
        int n;
        cin>>n;
        string ops;
        stack<int>  s;
        Setcache.clear();
        IDcache.clear();
        for(int i=0;i<n;++i){
            cin>>ops;
            SET set1,set2,set3;
            if(ops=="PUSH"){
                s.push(ID(SET()));            
            }
            else if(ops=="DUP"){
                s.push(ID(Setcache[s.top()])); 
            }
            else if(ops=="UNION"){
                set1=Setcache[s.top()];s.pop();
                set2=Setcache[s.top()];s.pop();
                set_union(ALL(set1),ALL(set2),inserter(set3, set3.begin()));
                s.push(ID(set3));
            }
            else if(ops=="INTERSECT"){
                set1=Setcache[s.top()];s.pop();
                set2=Setcache[s.top()];s.pop();
                set_intersection(ALL(set1),ALL(set2),inserter(set3, set3.begin()));
                s.push(ID(set3));
            }
            else if(ops=="ADD"){
                set1=Setcache[s.top()];s.pop();
                set2=Setcache[s.top()];s.pop();
                set2.insert(ID(set1));
                s.push(ID(set2));
            }
            cout<<Setcache[s.top()].size()<<endl;
        }
        cout<<"***"<<endl;
    }
    
    
    return 0;
}


//对容器编号，map做映射，union和intersection
//INITIALIZATION!!!!!!

//Line 64 Setcache[s.top()].size() 不是s.top() why?