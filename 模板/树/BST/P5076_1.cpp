#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;
struct Node
{
    int val, ls, rs, sz, cnt;
} bst[maxn];
int bnt;
int val;
int n;
inline void newNode(int root)
{
    bst[root].ls = 0;
    bst[root].rs = 0;
    bst[root].cnt = 1;
    bst[root].sz = 1;
    bst[root].val = val;
}
void insert(int root)
{
    if (bnt == 0)
    {
        ++bnt;
        newNode(bnt);
        return;
    }
    bst[root].sz++;
    if (bst[root].val == val)
    {
        bst[root].cnt++;
    }
    else if (bst[root].val < val)
    {
        if (!bst[root].rs)
        {
            bnt++;
            bst[root].rs = bnt;
            newNode(bnt);
        }
        else
        {
            insert(bst[root].rs);
        }
    }
    else
    {
        if (!bst[root].ls)
        {
            bnt++;
            bst[root].ls = bnt;
            newNode(bnt);
        }
        else
        {
            insert(bst[root].ls);
        }
    }
}
int searchr(int root)
{

    if (bst[root].val == val)
    {
        if (bst[root].ls)
        {
            return bst[bst[root].ls].sz + 1;
        }
        else
        {
            return 1;
        }
    }
    else if (bst[root].val < val)
    {
        return bst[root].sz - bst[bst[root].rs].sz + searchr(bst[root].rs);
    }
    else
    {
        return searchr(bst[root].ls);
    }
}
int searchv(int root, int k)
{

    int tmp = 1;
    if (bst[root].ls)
    {
        tmp += bst[bst[root].ls].sz;
    }
    if (tmp == k)
    {
        return bst[root].val;
    }
    else if (tmp < k)
    {
        return searchv(bst[root].rs, k - tmp);
    }
    else
    {
        return searchv(bst[root].ls, k);
    }
}
int findpre(int root)
{

    if (bst[root].val < val)
    {
        if (bst[root].rs && bst[bst[root].rs].val < val)
        {
            return findpre(bst[root].rs);
        }
        else
        {
            return bst[root].val;
        }
    }
    else
    {
        if (bst[root].ls && bst[bst[root].ls].val)
        {
            return findpre(bst[root].ls);
        }
        else
        {
            return -2147483647;
        }
    }
}
int findpost(int root)
{
    if (bst[root].val > val)
    {
        if (bst[root].ls)
        {
            return findpost(bst[root].ls);
        }
        else
        {
            return 2147483647;
        }
    }
    else
    {
        if (bst[root].rs)
        {
            return findpost(bst[root].rs);
        }
        else
        {
            return 2147483647;
        }
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    int op;
    for (int i = 1; i <= n; i++)
    {
        // printf("%d %d %d \n", bst[1].val, bst[2].val, bst[3].val);
        scanf("%d%d", &op, &val);
        if (op == 1)
        {
            printf("%d\n", searchr(1));
        }
        else if (op == 2)
        {
            printf("%d\n", searchv(1, val));
        }
        else if (op == 3)
        {
            printf("%d\n", findpre(1));
        }
        else if (op == 4)
        {
            printf("%d\n", findpost(1));
        }
        else if (op == 5)
        {
            insert(1);
        }
    }
    return 0;
}