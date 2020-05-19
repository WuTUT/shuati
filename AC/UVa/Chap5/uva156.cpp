#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
map<string,bool> dict;
vector<string> words;
string rev(string s){
    for(int i=0;i<s.length();i++){
        if(isalpha(s[i])){
            s[i]=tolower(s[i]);
        }
            
    }
    sort(s.begin(),s.end());
    return s;
}
int main(){
   // freopen("data.in","r",stdin);
    string s,buf;
    while (cin>>s)
    {
        if(s[0]=='#'){
           // cout<<"111"<<endl;
            break;
        }
        
        //stringstream ss(s);
        //while (ss<<buf)
        {
            string revs=rev(s);
            if(!dict.count(revs)){
                dict[revs]=false;
            }
            else
            {
                dict[revs]=true;
            }
            words.push_back(s);
               
        }
        
    }
    vector<string> ans;
    for(int i=0;i<words.size();++i){
       if(dict[rev(words[i])]==false){
           ans.push_back(words[i]);
       }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}


//字符重排，tolower,sort