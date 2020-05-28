#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int kase=0;
    int T;scanf("%d",&T);
    while(T--){
       string s,t;
       cin>>s;
       cin>>t;
       int len=s.length();
       int ans=0;int num1=0;int num2=0;int nums0=0,nums1=0,numt0=0,numt1=0;
       for(int i=0;i<len;i++){
           if(s[i]=='1') nums1++;
           else if(s[i]=='0') nums0++;
           if(t[i]=='1') numt1++;
           else numt0++;
        }
        if(nums0<numt0){
            for(int i=0;i<len;i++){
                if(s[i]=='?' && t[i]=='0'){
                    s[i]='0';
                    nums0++;
                    ans++;
                }
            }
        }
        if(nums0<numt0){
            for(int i=0;i<len;i++){
                if(s[i]=='?'){
                    s[i]='0';
                    nums0++;
                    ans++;
                    if(nums0>=numt0){break;}//CASE 1
                }
            }
        }

        
        if(nums0<numt0){
            printf("Case %d: %d\n",++kase,-1);
            continue;
        }
        for(int i=0;i<len;i++){
                if(s[i]=='?'){
                    s[i]=t[i];
                    ans++;
                }
        }
        // cout<<"s :"<<s<<endl;
        // cout<<"t :"<<t<<endl;
        // cout<<"ans " <<ans<<endl;
        for(int i=0;i<len;i++){
            if(s[i]-t[i] >0){
                num1++;
            }else if(s[i]-t[i] <0){
                num2++;
            }
        }
        // cout<<"num1 " <<num1<<endl;
        // cout<<"num2 " <<num2<<endl;
        if(num2>=num1){
            ans+=num1;
            num2-=num1;
            num1=0;
            ans+=num2;
            printf("Case %d: %d\n",++kase,ans);
            continue;
        }
        else{
            printf("What happpend???\n");
        }    
        //printf("Case %d: %d\n",++kase,ans);
    }
    
    return 0;    
}
//贪心，变"?"总不会不如另外一种情况