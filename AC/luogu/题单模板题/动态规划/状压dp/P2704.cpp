// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <vector>
// #include <bitset>
// using namespace std;
// const int maxn = 102,maxm = 12;
// char g[maxn][maxm];
// vector<int> la[3];
// int f[3][1<<10][1<<10];
// int n,m;
// int row;
// int ans;
// void dfs(int ind,int num,int j){
//     if(ind == m+1){
//        // cout << j<<endl;
//         // int r1 = (row+2)%3;
//         int r2 = (row+1)%3;
//         int r3 = row%3;
//         for(int ii=0;ii<la[r1].size();ii++){
//             for(int jj=0;jj<la[r2].size();jj++){
//                 int j1=la[r1][ii];
//                 int j2=la[r2][jj];
//                 if( ((j1&j2) == 0) && ((j&j1) == 0) && ((j&j2) == 0)){
//                     //cout << (j1) << "   "<<(j2)<<"  "<<(j)<<endl;
//                     f[r3][j][j1]=max(f[r3][j][j1],f[r1][j1][j2]+num);
//                 }
//             }
//         }
//       //  cout << row <<"  j "<< bitset<4>(j) <<"  "<<f[r3][j][j1]<<endl;
//         la[r3].push_back(j);
        
//     }
//     if(ind > m) return;
//     if(g[row][ind]=='P'){
        
//         if((j&3)==0){
            
//             dfs(ind+1,num+1,(j<<1)|1);
//         }
            
//         dfs(ind+1,num,j<<1);
//     }
//     else{
//         dfs(ind+1,num,j<<1);
//     }
//     return;
// }
// int main(){
//     freopen("data.in","r",stdin);
//     freopen("data.out","w",stdout);
//     cin >> n >> m;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             scanf(" %c",&g[i][j]); 
//         }
        
//     }
    
//     // for(int i=1;i<=n;i++){
//     //     for(int j=1;j<=m;j++){
//     //         cout << g[i][j];
//     //     }
//     //     cout << endl;
//     // }
//     la[0].push_back(0);la[2].push_back(0);
//     for(row=1;row<=n;row++){
        
//         la[row%3].clear();
//         dfs(1,0,0);
//     }
//     int r3 = n%3;int r2=(n-1)%3;
//     for(int i=0;i<la[r3].size();i++){
//         for(int j=0;j<la[r2].size();j++)
//         ans = max(ans,f[r3][la[r3][i]][la[r2][j]]);
//     }
//     cout << ans<<endl;
// }


#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 105,maxm = 12;
int n,m;
int g[maxn];
int v[3][70];
int vs[3];
int f[3][70][70];
int cnt[70];
int state[70];
int top;
inline int cnt2(int j){
    int sum=0;
    
    while(j){
        if(j&1){
            sum++;
        }
        j = j>>1;
    }
    return sum;
}
int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    char ch;
    int si = (1<<m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&ch);
            if(ch == 'H'){
                g[i]=g[i]<<1|1;
            }
            else
                g[i]=g[i]<<1;
        }
    }
    
    for(int j=1;j<si;j++){
        if( (j&(j<<1))==0 && (j&(j<<2)) == 0 && (j&(j>>1))==0 && (j&(j>>2))==0 ) {
           state[++top]=j;
           cnt[top] = cnt2(j);
        }
    }
   // cout << top<<endl;
    for(int i=0;i<=top;i++){
        if((state[i]&g[1])==0){
            f[1][i][0]=cnt[i];
        }

    }
    for(int i=0;i<=top;i++){
        if((state[i]&g[2])==0){
            for(int j=0;j<=top;j++){
                if((state[j]&g[1])==0)
                    f[2][i][j]=f[1][j][0]+cnt[i];
            }
        }
    }
    for(int row = 3;row<=n;row++){
        int r1 = (row+2)%3;
        int r3 = row%3;
        for(int i=0;i<=top;i++){
            if((state[i]&g[row])==0){
                for(int j=0;j<=top;j++){
                    if((state[j]&g[row-1])==0){
                        for(int k=0;k<=top;k++){
                            if((state[k]&g[row-2])==0)
                                if((state[i]&state[j])==0 && (state[j]&state[k])==0 && (state[i]&state[k])==0 )
                                     f[r3][i][j]=max(f[r3][i][j],f[r1][j][k]+cnt[i]);
                        }
                    }
                    
                }
            }
            
        }
    }
    int ans = 0;int r3 =n%3;
    for(int i=0;i<=top;i++){
        for(int j=0;j<=top;j++){
            ans = max(ans,f[r3][i][j]);
        }
    }
    cout << ans<<endl;
}
//455ms 756kb 比前一个967ms 10.97Mb好太多了
//但是容易写错
//其实第一个f也可以用vector，省下空间，但是
//反正记住！位运算 j<<1|1 ok
// (a&b)==0 括号不能省！！！！
// bitset很好用
// 状态可以进一步压缩
// 状态转移方程！f[][][]，开两维是错的，因为前一个转移状态不可以省
// 确实经典