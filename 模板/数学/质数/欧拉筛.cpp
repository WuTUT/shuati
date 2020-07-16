//素数的O（n）筛法
#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;
int n, q;
vector<int> prime;
const int maxn = 1e8 + 5;
bitset<maxn> bs;
void shai()
{
    for (int i = 2; i <= n; i++)
    {
        if (bs[i])
        {
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size(); j++)
        {
            if (i * prime[j] > n)
            {
                break;
            }
            bs[i * prime[j]] = 0;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}
int main()
{

    cin >> n >> q;

    bs.set();
    shai();
    for (int i = 1, tmp; i <= q; i++)
    {
        scanf("%d", &tmp);
        printf("%d\n", prime[tmp - 1]);
    }
}