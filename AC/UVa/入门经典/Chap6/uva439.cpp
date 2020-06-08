#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;


int sx,sy,ex,ey;
int isvis[8][8];
int minstep[8][8];
const int rw[4]={-2,-1,1,2};
void bfs(int x,int y){
    queue<pair<int,int> > q;
    q.push(pair<int,int>(x,y));
    minstep[x][y]=0;
    isvis[x][y]=1;
    while (!q.empty())
    {
        pair<int,int> p= q.front();
        q.pop();
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(abs(rw[i])+abs(rw[j])==3){
                    int x1=p.first+rw[i];
                    int y1=p.second+rw[j];
                    if( !(x1<0 || x1>=8 || y1<0 || y1>=8)   && !isvis[x1][y1]){
                         q.push(pair<int,int>(x1,y1));
                         isvis[x1][y1]=1;
                         minstep[x1][y1]=minstep[p.first][p.second]+1;
                         if(x1==ex &&y1== ey){
                             return;
                         }
                    }
                       
                }
            }
        }
        
    }
    

}
int main(){
    //freopen("data.in","r",stdin);
    string s1,s2;
    while (cin>>s1)
    {
        cin>>s2;
        memset(isvis,0,sizeof(isvis));
        memset(minstep,0,sizeof(minstep));
        
        
        sx=s1[0]-'a';sy=s1[1]-'1';
        ex=s2[0]-'a';ey=s2[1]-'1';
        
        bfs(sx,sy);
        cout<<"To get from "<<s1<<" to "<<s2<<" takes ";
        cout<<minstep[ex][ey]<<" knight moves."<<endl;
    }
    


    return 0;
}