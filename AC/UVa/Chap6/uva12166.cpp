#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <cstdlib>
#include <map>
using namespace std;
const int maxn=16;
long a[1<<17];
map<long,long> dict;
int main(){
   // freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
   int T;
   cin>>T;getchar();
   while(T){
       T--;
       int len=1;
       int maxlen=-1;
       long s=0;
       int index=1;
       memset(a,-1,sizeof(a));
       while(1){
           char c=getchar(); 
          
            if(c=='['){
                len++;  
                maxlen=max(maxlen,len);
                index=index<<1;
                continue;
            }else if(c==']'){
                len--;
                
                a[index]=s;
                
                s=0;
                index=index>>1;
                continue;
            }
            else if((c=='\n' || c==' ')){
                if(len!=1)
                    continue;
                else 
                    break;
            }
            else if(c==','){
                a[index]=s;
                s=0;
                index++;
            }
            else{
                if(c==EOF) break;
                if(len==1){
                    maxlen=0;
                    s=c-'0';
                     
                    while( (c=getchar())!='\n' && c!=' ' &&c!=EOF)
                        s=s*10+c-'0';
                    a[1]=s;
                    break;
                }
                else{
                    s=s*10+c-'0';
                    
                }
                
            }
            if(len==1) break;
       }
       
    //    cout<<maxlen<<endl;
    //    for(long i=1;i<(1<<maxlen);i++){
    //        cout<<a[i]<<" ";
    //    }
    //    cout<<endl;
        if(maxlen==0){
            cout<<0<<endl;
        }
        else{
            long count=0;
            dict.clear();
            for(int i=0;i<maxlen;i++){
                for(long j=(1<<i); j<(1<<(i+1));j++){
                    if(a[j]!=0&&a[j]!=-1){
                        count++;
                        dict[a[j]<<(i-1)]++;
                        //cout<<(a[j]<<(i-1))<<" "<<dict[a[j]<<(i-1)]<<endl;
                    }
                }
            }
            long maxp=-1;
            for(map<long,long>::iterator  i=dict.begin();i!=dict.end();i++){
                
                maxp=max(maxp,i->second);
            }
            cout<<count-maxp<<endl;
        }
   }
   return 0; 
}