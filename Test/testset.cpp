#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
int main()
{
    set<int> s;
    s.insert(4);
    s.insert(5);
    auto it = s.lower_bound(3);
    cout << bool(it == s.begin()) << endl;
    cout << *it << endl;
    return 0;
}