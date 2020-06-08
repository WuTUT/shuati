#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
char s[1005][35];
int cmp(const void*a,const void*b)
{
	char *s1 = (char *)a;
    char *s2 = (char *)b;
    return strcmp(s1,s2);
}
int main(){
    
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int n;scanf("%d",&n);
    while(n){

        
        
        for(int i=0;i<n;i++){
            scanf("%s",s[i]);
        }
        
        qsort(s,n,sizeof(s[0]),cmp);
        
        int p1,p2;
        p2=n/2;p1=p2-1;
        vector<char> ans;
        int si;
        for(si=0;si<strlen(s[p1]) && si<strlen(s[p2]);si++ ){
            if(s[p1][si]==s[p2][si]){
                ans.push_back(s[p1][si]);
            }
            else{
                break;
            }
        }
      while(1){
          
          if(si!=strlen(s[p1])){
              
            if(si==strlen(s[p1])-1){
                
                ans.push_back(s[p1][si]);
                break;
            }
            char c=s[p1][si]+1;
           // printf("si =%d\n",si);
           // printf("strlen(s[p2]) =%d\n",(int)strlen(s[p2]));
            if( c<s[p2][si] ||  (strlen(s[p2])-si-1)>0 ){//CASE 2 wrong
                ans.push_back(c);
                break;
            }
            else{
                ans.push_back(s[p1][si]);
                bool f1=true;
                for(int i=si+1;i<strlen(s[p1]);i++){
                    if(s[p1][i]=='Z'){
                        ans.push_back(s[p1][i]);
                    }
                    else{
                        if(i==strlen(s[p1])-1){
                            ans.push_back(s[p1][i]);//CASE1 forgotten
                        }
                        else{
                            ans.push_back((char)(s[p1][i]+1));
                        }
                        break;
                    }
                }
                    break;
            }
            
            
            }else{
                break;
            }
      }
        for(int i=0;i<ans.size();i++){
            printf("%c",ans[i]);
        }
        printf("\n");
        scanf("%d",&n);
    }
      return 0;    
}

//读一串串字符,无空格型
//string版本https://blog.csdn.net/DickensTone/article/details/78253549
//qsort 二维字符数组