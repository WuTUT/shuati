#include <iostream>
#include <cstdio>
using namespace std;
long long a;
int main()
{
    cin >> a;
    long long x = a % (1 << 16);
    long long y = a / (1 << 16);
    cout << ((x << 16ULL) + y) << endl;
}
