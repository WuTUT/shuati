#include<iostream>
#include <cstdio>
const int MAXN=100005;
char s[MAXN];
int ne[MAXN];
using namespace std;
int main(){
    //freopen("data.in","r",stdin);
    char c;
    int last;
    int cur;
    int num;
    while(1){
        last=0;
        cur=0;
        num=0;
        s[0]=' ';
        ne[0]=0;
        while (( (c=getchar()) != '\n')  && (c!=EOF) )
        {
            if(c=='['){
                
                cur=0;
            }
            else if(c==']'){
                cur=last;
            }
            else{
                num++;
                s[num]=c;
                ne[num]=0;
                
                if(cur==last)
                {
                    ne[last]=num;
                    last=num;
                    cur=num;
                }
                else{
                    ne[num]=ne[cur];
                    ne[cur]=num;
                    cur=num;
                }
                
            }
        }
        // for(int i=0;i<num;i++){
        //     printf("%3d",i);
        //     //cout<<first;
        //    // first=ne[first];

        // }
        // cout<<endl;
        // for(int i=0;i<num;i++){
        //     printf("%3c",s[i]);
        //     //cout<<first;
        //    // first=ne[first];

        // }
        // cout<<endl;
        // for(int i=0;i<num;i++){
        //     printf("%3d",ne[i]);
        //     //cout<<first;
        //     //first=ne[first];

        // }
        // cout<<endl;
        if(c==EOF){
           break;
       }
        for(int i=ne[0];i!=0;i=ne[i]){
            cout<<s[i];
            
        }
        cout<<endl;
        
    }
    return 0;
    
}


//我已经被绕晕了.....