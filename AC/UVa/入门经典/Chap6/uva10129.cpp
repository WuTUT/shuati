#include<iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int g[26][26];
int in[26];
int out[26];
int isvisit[26];
int has[26];
void dfs(int i){
    for(int j=0;j<26;j++){
        if(has[j]){
            if( (g[i][j]!=0 || g[j][i] !=0) && !isvisit[j]){
            isvisit[j]=1;
            dfs(j);
            }
        }
        
    }
}
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int T;
    cin>>T;
    while(T){
        T--;
        memset(g,0,sizeof(g));
        memset(isvisit,0,sizeof(isvisit) );
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        memset(has,0,sizeof(has));
        bool eula=true;
        int edges;
        cin>>edges;
        string s;
        
        for(int i=0;i<edges;i++){
            cin>>s;
            g[s[0]-'a'][s[(s.length()-1)]-'a']+=1;
            has[s[0]-'a']=has[s[(s.length()-1)]-'a']=1;
        }
        
        for(int i=0;i<26;i++){
            for (int j = 0; j < 26; j++)
            {
                in[i]+=g[i][j];
                out[j]+=g[i][j];
            }
            
        } 
        
        for(int i=0;i<26;i++){
            if(has[i]){
                isvisit[i]=1;
                dfs(i);
                break;
            }
            
        }
        
        for(int i=0;i<26;i++){
            if(has[i]  && !isvisit[i]){
                eula=false;
                break;
            }
        }
        int bad_in=0;
        int bad_out=0;
        int bad_v=0;
        for(int i=0;i<26;i++){
            if(has[i]){
                if(in[i]!=out[i]){
                    bad_v++;
                    if(bad_v==1){
                        bad_in=i;
                    }
                    else if(bad_v==2){
                        bad_out=i;
                    }
                    else if(bad_v>2){
                        
                        break;
                    }
                }
            }
            
        }
        //cout<<(char)('a'+bad_in)<<" "<<(char)('a'+bad_out)<<endl;
        //cout<<bad_v<<endl;
        //cout<<eula<<endl;
        if(bad_v == 1) eula =false;
        else if(bad_v ==2 ){
            int flag1=in[bad_in]-out[bad_in];
            int flag2=in[bad_out]-out[bad_out];
            
            if(! ((flag1==1 && flag2==-1) || (flag2==1 && flag1==-1)) ){
                
                eula=false;
            }
        }  
        else if(bad_v > 2) eula =false;

        if(eula){
            cout<<"Ordering is possible."<<endl;
        }
        else
        {
            cout<<"The door cannot be opened."<<endl;
        }
        
    }

   return 0;     
}


//有向图的欧拉道路存在：（1）当成无向图看，是连通图 注意！在建图的时候是当有向图建立的，所以应该DFS时应该注意考虑两个方向
//(2)case 1: 所有点入度等于出度
//   case 2: 入度不等于出度的点有两个，其中一个差为1，另一个差为-1；      