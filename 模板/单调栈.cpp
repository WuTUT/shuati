#include <stack>
using namespace std;

int main(){
    int n;
    int a[10];int L[10];
    stack<int> S;
    for(int i=1 ;i<=n ;i++){
        while(S.size() && a[S.top()] >= a[i]) S.pop();

        if(S.empty())     L[i] = 0;
        else              L[i] = S.top();

        S.push(i);
    }
}