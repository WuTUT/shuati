#include <iostream>
#include <queue>
#include <string>
#include <cstdio>
#include <map>

using namespace std;
#define MAXQUENUM 1003
map<int,int> dict;

queue<int> inqu[MAXQUENUM];
queue<queue<int>* > qu;
int main(){
    //freopen("data.in","r",stdin);
    int qn;
    int n;int num;int kase=0;
    while (cin>>qn)
    {

        if(qn==0){
            break;
        }
        cout<<"Scenario #"<<++kase<<endl;
        dict.clear();
        while (!qu.empty())
        {
            qu.pop();
        }
        for(int i=0;i<qn;i++){
            while (!inqu[i].empty())
            {
                inqu[i].pop();
            }
        }
        
        

        for(int i=0;i<qn;i++){
            cin>>n;
            
            for(int j=0;j<n;j++){
                cin>>num;
                
                dict[num]=i;
            }
        }
        while(1){
            string ops;
            cin>>ops;
            
            if(ops[0]=='S'){
                cout<<endl;
                break;
            }
            else if(ops[0]=='E')
            {
                
                cin>>num;
                
                int qi=dict[num];
                if(inqu[qi].empty()){
                    
                    qu.push(&inqu[qi]);
                }
                inqu[qi].push(num);
                
            }
            else if(ops[0]=='D')   
            {
                //cout<<"qu front is"<<inqu[0].back()<<endl;
                
                
                cout<<qu.front()->front()<<endl;
                qu.front()->pop();
                if(qu.front()->empty()){
                    qu.pop();
                }
            }

        }
        
        
        
    }
    
    

    return 0;
}
