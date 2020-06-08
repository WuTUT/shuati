#include<iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
using namespace std;
const int maxn=205;
vector<string> gr;
void dfs(int row,int col){
    printf("%c(",gr[row][col]);
    if(row+1 == gr.size()){
        printf(")");
        return;
    }
    if(gr[row+1][col]=='|'){
        
        
        int i;int end=-1;
        for(i=col;i<gr[row+2].size();i++){
            if(gr[row+2][i]!='-'){
                end=i;    
                break;
            }
                
        }
        if(end==-1) end=gr[row+2].size();
        for(i=col;i>=0;i--){
            if(gr[row+2][i]!='-')
                break;
        }
        int start=i;
        for(int i=start+1;i<end;i++){
            if( i<gr[row+3].size() &&gr[row+3][i]!=' ' 
            &&gr[row+3][i]!='-' &&gr[row+3][i]!='|'){
                dfs(row+3,i);
            }
        }
    }
    printf(")");
    return;
}
int main(){
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int T;
    cin>>T;
    getchar();
    
    while(T){
        T--;
        string s;
        int line=0;
        gr.clear();
        while(1){
            getline(cin,s);
            if(s[0]=='#') break;
            gr.push_back(s);
            line++;
        }
        if(line==0) {printf("()\n");continue;}
        // for(int i=0;i<gr.size();i++){
        //     cout<<gr[i]<<endl;
        // }
        printf("(");
        for(int i=0;i<gr[0].size();i++){
            if(gr[0][i]!=' ' &&gr[0][i]!='-'
                 &&gr[0][i]!='|'){
                dfs(0,i);
                break;
            }
        }
        printf(")\n");
        
    }
    return 0;

}

//注意输入的读法
//字符串处理很麻烦