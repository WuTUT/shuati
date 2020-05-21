#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int maxn=7;
int a[1<<maxn];
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int n;
    cin>>n;
    getchar();
    int kase=0;
    while(n){
        cout<<"S-Tree #"<<(++kase)<<":"<<endl;
        string ans;
        string s;
        getline(cin,s);
        getline(cin,s);
        int len=s.length();
        
        for(int i=0;i<len;i++){
            a[i]=s[i]-'0';
        }
        int T;
        cin>>T;getchar();
        while (T)
        {
            T--;
            getline(cin,s);
            int index=0;
            for(int i=0;i<n;i++){
                index=index*2+s[i]-'0';
            }
            ans.push_back((char)(a[index]+'0'));
        }
        cout<<ans<<endl<<endl;
        cin>>n;getchar();
    }
    return 0;
}