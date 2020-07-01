#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    freopen("data.in", "r", stdin);
    unordered_map<string, int> ma;
    int n;
    cin >> n;
    int op;
    string name;
    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> name;
            cin >> a;
            ma[name] = a;
            cout << "OK" << endl;
        }
        else if (op == 2)
        {
            cin >> name;
            if (ma.find(name) != ma.end())
            {
                cout << ma[name] << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
        }
        else if (op == 3)
        {
            cin >> name;
            if (ma.find(name) != ma.end())
            {
                ma.erase(name);
                cout << "Deleted successfully" << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
        }
        else if (op == 4)
        {
            cout << ma.size() << endl;
        }
    }
    return 0;
}