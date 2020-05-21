#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
stack<char> S;
bool f(string& str){
    if(str.empty()) return true;
    
   for(int i=0;i<str.length();i++){
       char tmp=str[i];
       if(tmp==' ') continue;
       if(tmp==')'){
           if(S.size()>=1 && S.top()=='('){
                    S.pop();
            }
            else{
                return false;
            }
       }
       else if(tmp==']'){
           if(S.size()>=1 && S.top()=='['){
                S.pop();
            }
            else{
                return false;
            }   
       }
       else
       {
           S.push(tmp);
       }
       
   }
   return S.empty();
    
}
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int T;
    cin>>T;getchar();
    while(T){
        while(!S.empty()){
            S.pop();
        }
        
        T--;
        string str;
        getline(cin,str);
        //cout<<str<<endl;
        if(f(str)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}