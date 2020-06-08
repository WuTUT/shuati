#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
const char* dir="NEWS";
const char* turn="FLR";
const int maxn=10;
//int maze[maxn][maxn][4];
int okturn[maxn][maxn][4][3];
int d[maxn][maxn][4];
int entx,enty,goalx,goaly;char ent_direct;
//N E S W 
//0 1 2 3
//F L R
//0 -1 1
//0 1  2

int turntoint(char c){
    if(c=='F') return 0;
    if(c=='L') return -1;
    if(c=='R') return 1;
    return -2;
}
int dirtoint(char c){
    if(c=='N') return 0;
    if(c=='E') return 1;
    if(c=='S') return 2;
    if(c=='W') return 3;
    return -1;
}
int sovturn(int i){
    if(i==0) return 0;
    if(i==1) return -1;
    if(i==2) return 1;
}
int turntosov(int i){
    if(i==0) return 0;
    if(i==-1) return 1;
    if(i==1) return 2;
}
char dirtochar(int d){
    if(d==0) return 'N';
    if(d==1) return 'E';
    if(d==2) return 'S';
    if(d==3) return 'W';
}

char turntochar(int t){
    if(t==0) return 'F';
    if(t==-1) return 'L';
    if(t==1) return 'R';
}
struct Node{
    int x;
    int y;
    int direct;
    Node():x(0),y(0),direct(-1){}
    Node(int x,int y,int direct):x(x),y(y),direct(direct){}
};
struct Node path[maxn][maxn][4];
struct Node goturn(struct Node node,int turn){
    node.direct= (node.direct+turn+4)%4 ;
    if(node.direct==0){
        node.x-=1;
    } 
    if(node.direct==1){
        node.y+=1;
    } 
    if(node.direct==2){
        node.x+=1;
    } 
    if(node.direct==3){
        node.y-=1;
    } 
    
    return node;
}
using namespace std;
//N E S W 
//0 1 2 3
//F L R
//0 -1 1
//0 1  2
void printnode(struct Node node){
    printf("%d,%d  towards  %c\n",node.x,node.y,dirtochar(node.direct));
}
int lastdirect;
struct Node nextent;
void bfs(){
    queue<struct Node> q;
    nextent= goturn( Node(entx,enty,dirtoint(ent_direct)),0 );
    q.push(nextent);

    while (!q.empty())
    {
        struct Node no=q.front();
        //printnode(no);
        q.pop();
        if(no.x == goalx && no.y==goaly){
            lastdirect=no.direct;
            return;
        }
        for(int turni=0;turni<3;turni++){
            
           // printf("turn %c is %d\n",turntochar(sovturn(turni)),okturn[no.x][no.y][no.direct][turni]);
            if(okturn[no.x][no.y][no.direct][turni]==1){
                
               struct Node nonext= goturn(no,sovturn(turni));
               if( d[nonext.x][nonext.y][nonext.direct]==0){
                   q.push(nonext);
                   d[nonext.x][nonext.y][nonext.direct]=d[no.x][no.y][nonext.direct]+1;
                   path[nonext.x][nonext.y][nonext.direct]=no;
                   
               }
            //    if(nonext.x==goalx && nonext.y == goaly){
            //        lastdirect=nonext.direct;
            //        return;
            //    }
            }
        }
        

    }
    
}
vector<pair<int,int> > ans;
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    string name;
    while(1){
        //memset(maze,0,sizeof(maze));
        memset(d,0,sizeof(d));
        memset(path,0,sizeof(path));
        memset(okturn,0,sizeof(okturn));
        lastdirect=-1;
        
        
        cin>>name;
        if(name=="END") {
            return 0;
        }
        
        cin>>entx>>enty>>ent_direct>>goalx>>goaly;
        //cout<<entx<<enty<<ent_turn<<goalx<<goaly<<endl;
        okturn[entx][enty][dirtoint(ent_direct)][0]=1;
        int x,y;
        scanf("%d",&x);
        while(x!=0){
            scanf("%d",&y);
            
            string s;
            while(cin>>s){
                if(s=="*"){
                    break;
                }
                int len=s.length();
                int direction_i=dirtoint(s[0]); 

                for(int i=1;i<len;i++){
                    okturn[x][y][direction_i][turntosov(turntoint(s[i]))]=1;
                }
            }
            scanf("%d",&x);
        }
        
        bfs();
        cout<<name<<endl;
        ans.clear();
        if(lastdirect==-1){
            cout<<"  "<<"No Solution Possible"<<endl;
        }
        else{
            
            ans.push_back(pair<int,int> (goalx,goaly));
            
            int tmpx=goalx;
            int tmpy=goaly;
            while (1)
            {
               if(tmpx==nextent.x &&tmpy==nextent.y &&lastdirect == nextent.direct){
                   break;
               } 
               struct Node tmpno= path[tmpx][tmpy][lastdirect];
               ans.push_back(pair<int,int> (tmpno.x,tmpno.y));
               
               tmpx=tmpno.x;
               tmpy=tmpno.y;
               lastdirect=tmpno.direct;
            }
            ans.push_back(pair<int,int> (entx,enty));
            int count=0;
            printf("  ");
            for(int i=ans.size()-1;i>=0;i--){
                count++;
                if(count==10){
                    
                    printf("(%d,%d)",ans[i].first,ans[i].second);
                    
                    if(i!=0){printf("\n  ");}
                    count=0;
                }
                else
                {
                    printf("(%d,%d)",ans[i].first,ans[i].second);
                    if(i!=0) printf(" ");
                }
                
            }
            
            cout<<endl;
        }
    }
    

    return 0;
}