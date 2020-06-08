#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <cassert>
#include <deque>
#include <queue>
using namespace std;
int var[26];
int t[5];

typedef pair<int,int> rq_ins;
deque<rq_ins> readyq;
queue<rq_ins> chokeq;
struct instruction{
    int ins;
    char var_id;
    int value;
};
typedef struct instruction _instruction;
vector<_instruction> prog[10005];
// const string insstr[5]={"Var","Print","Lock","Unlock","End"};
// string instostr(int ins){
//     return insstr[ins];
// }
//A,Out,Lock,unlock,end
//0 1    2    3      4
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int T;
    cin>>T;
    int Q;
    int n;
    int num_lock;
    while (T)
    {
        T--;
        num_lock=-1;
        for(int i=0;i<26;i++){
            var[i]=0;
        }
        while (!readyq.empty())
        {
            readyq.pop_back();
        }
        while (!chokeq.empty())
        {
            chokeq.pop();
        }
        
        cin>>n;
        for(int i=0;i<n;i++){
            prog[i].clear();
        }
        for(int i=0;i<5;i++){
            cin>>t[i];
        }
        cin>>Q;
        
        string s;
        int prog_id=0;
       // getchar();
        while(getline(cin,s)){
            //cout<<s<<endl;
            _instruction exi;
            exi.ins=1;
            exi.value=0;
            exi.var_id='a';
            if(s[1]=='r'){//print
                exi.ins=1;
                exi.var_id=s[6];
                prog[prog_id].push_back(exi);
            }
            else if(s[1]=='o'){//lock
                exi.ins=2;
                prog[prog_id].push_back(exi);
            }
            else if(s[1]=='n'&&s[0]=='e'){//end
                exi.ins=4;
                prog[prog_id].push_back(exi);
                prog_id++;
                if(prog_id==n){
                    break;
                }
            }
            else if(s[1]=='n'&&s[0]=='u'){//unlock
                exi.ins=3;
                prog[prog_id].push_back(exi);
            }
            else if(s[2]=='='){
                exi.ins=0;
                exi.var_id=s[0];
                exi.value=atoi(s.substr(4).c_str());
                prog[prog_id].push_back(exi);
            }
            
        }
        //cout<<Q<<" "<<n<<endl;
        // for(int outid=0;outid<n;outid++){
        //     for(int i=0;i<prog[outid].size();i++){
        //     cout<<instostr(prog[outid][i].ins)<<" "<<prog[outid][i].var_id<<" "<<prog[outid][i].value<<endl;
        //     }
        // }
        
        for(int i=0;i<n;i++){
            readyq.push_back(rq_ins(i,0));
        }
        //A,Out,Lock,unlock,end
        //0 1    2    3      4
        while (!readyq.empty())
        {
            //cout<<"Size is"<<readyq.size()<<endl;
            int qleft=Q;
            rq_ins ex_rq_ins= readyq.front();
            readyq.pop_front();
            int progid=ex_rq_ins.first;
            int line=ex_rq_ins.second;
            
            //cout<<"Line is"<<line<<endl;
            
            
            bool is_end=false;bool is_lock=false;
            
            while(qleft>0){
                
                
                if( (prog[progid][line].ins) == 1){
                    cout<<(progid+1)<<": "<<var[(prog[progid][line].var_id-'a')]<<endl;
                    qleft-=t[1];
                }
                else if( (prog[progid][line].ins) == 2){
                    if(num_lock!=-1){
                        
                        chokeq.push(rq_ins(progid,line));
                        is_lock=true;
                        
                        break;
                    }
                    else{
                        num_lock=progid;
                        qleft-=t[2];
                    }
                }
                else if( (prog[progid][line].ins) == 3 ){
                    num_lock=-1;
                    qleft-=t[3];
                    if(!chokeq.empty()){
                        readyq.push_front(chokeq.front());
                        chokeq.pop();
                    }
                    
                }
                else if( (prog[progid][line].ins) == 4 ){
                    is_end=true;
                    qleft-=t[4];
                    break;
                }
                else if( (prog[progid][line].ins) == 0 ){
                    var[(prog[progid][line].var_id-'a')]=prog[progid][line].value;
                    qleft-=t[0];
                }
                line++;
               
            }
            
            if((!is_end)&&(!is_lock)){
                readyq.push_back(rq_ins(progid,line));
            }
            //cout<<"ReadyQ Size is"<<readyq.size()<<endl;    
        }
        
        if(T){
            
            cout << endl;
            
        } 
    }
    
    


    return 0;
}


//痛不欲生的输入输出