#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
const string Move="move";
const string Pile="pile";
const string Onto="onto";
const string Over="over";
const int MAXN=30;
vector<int> v[MAXN];
int n;
int findblo(int a,int &j){
    for(int i=0;i<n;i++){
        for(j=0;j<v[i].size();++j){
            if(v[i][j]==a){
                return i;
            }
        }
            
    }
}
void gw(vector<int>&vi,int j){
    int js=j;
    for(;j<vi.size();j++){
        v[vi[j]].push_back(vi[j]);
    }
    int num=vi.size()-js;
     while (num>0)
    {
        vi.pop_back();
        num--;
    }
}
void luo(vector<int>& va,int ai,vector<int>& vb){
    int as=ai;
    for(;ai<va.size();ai++){
        vb.push_back(va[ai]);
    }
    int num=va.size()-as;
    while (num>0)
    {
        va.pop_back();
        num--;
    }
}
int main(){
    //freopen("data.in","r",stdin);
    string s1,s2;
    int a,b;
    
    cin>>n;
    for(int i=0;i<n;i++){
        v[i].push_back(i);
    }
    while (cin>>s1>>a>>s2>>b)
    {
        int ja;int jb;
        int vnuma,vnumb;
        vnuma= findblo(a,ja);
        vnumb= findblo(b,jb); 
        if(vnuma==vnumb){
            continue;
        }   
        if(s1==Move){
            if(s2==Onto){
                gw(v[vnuma],ja+1);
                gw(v[vnumb],jb+1);
                luo(v[vnuma],ja,v[vnumb]);

            }else if(s2==Over)
            {        
                gw(v[vnuma],ja+1);
                luo(v[vnuma],ja,v[vnumb]);
            }
            
        }
        else if(s1==Pile)
        {
            if(s2==Onto){
                gw(v[vnumb],jb+1);
                luo(v[vnuma],ja,v[vnumb]);
            }else if(s2==Over)
            {   
                luo(v[vnuma],ja,v[vnumb]);
            }
        }
        else if(s1=="quit"){
            break;
        }
       
    }
     for(int i=0;i<n;i++){
            cout<<i<<":";
            for(int j=0;j<v[i].size();j++){
                cout<<" "<<v[i][j];
            }
            cout<<endl;
        }
    return 0;
}
