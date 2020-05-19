#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> blo;
vector<string> strcache;
map<string,int> id; 
map<blo,int> sk; 
int db[10005][11];
int IDstr(const string& s){
    if(!id.count(s)){
        strcache.push_back(s);
        return id[s]=strcache.size()-1;
    }
    return id[s];    
}
int main(){
    int n,m;
    int c1,c2,r1,r2;
    bool isfind;
    //freopen("data.in","r",stdin);
    while (scanf("%d%d\n",&n,&m)==2)
    {

        
        id.clear();
        strcache.clear();
        isfind=false;
        sk.clear();
        string s;
        //int readn=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char c;
                
                while (((c=getchar())!='\n')&&(c!=',')&&(c!=EOF))
                {
                    s.push_back(c);
                    
                }
                db[i][j]=IDstr(s);
                
                s.clear();
            }
        }
        
      /*  for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<db[i][j]<<endl;
            }
        }
        */
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;++j){
                for(int k=0;k<n;k++){
                    blo b(db[k][i],db[k][j]);
                    if(!sk.count(b)){
                        sk[b]=k;
                    }
                    else
                    {
                        r1=sk[b]+1;
                        r2=k+1;
                        c1=i+1;
                        c2=j+1;
                        isfind=true;
                        break;
                    }
                       
                }
                sk.clear();
                if(isfind){
                    break;
                }
            }
            if(isfind){
                    break;
            }
        }
        if(isfind){
            cout<<"NO"<<endl;
            cout<<r1<<" "<<r2<<endl;
            cout<<c1<<" "<<c2<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
        
    }
    

    return 0;
}