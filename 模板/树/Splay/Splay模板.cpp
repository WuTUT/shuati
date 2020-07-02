#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000 + 5, INF = 0x7fffffff;
struct Splay_Tree
{
    struct Node
    {
        int val, maxv, addv, sz, son[2];
        bool rev;
        void init(int _val)
        {
            maxv = val = _val;
            sz = 1;
            addv = rev = son[0] = son[1] = 0;
        }

    } T[maxn];
    int fa[maxn], root;
    void push_up(int x)
    {
        T[x].maxv = T[x].val, T[x].sz = 1;
        if (T[x].son[0])
        {
            T[x].maxv = max(T[x].maxv, T[T[x].son[0]].maxv);
            T[x].sz += T[T[x].son[0]].sz;
        }
        if (T[x].son[1])
        {
            T[x].maxv = max(T[x].maxv, T[T[x].son[1]].maxv);
            T[x].sz += T[T[x].son[1]].sz;
        }
    }
    void push_down(int x)
    {
        if (x == 0)
            return;
        if (T[x].addv)
        {
            if (T[x].son[0])
            {
                T[T[x].son[0]].val += T[x].addv;
                T[T[x].son[0]].maxv += T[x].addv;
                T[T[x].son[0]].addv += T[x].addv;
            }
            if (T[x].son[1])
            {
                T[T[x].son[1]].val += T[x].addv;
                T[T[x].son[1]].maxv += T[x].addv;
                T[T[x].son[1]].addv += T[x].addv;
            }
            T[x].addv = 0;
        }
        if (T[x].rev)
        {
            if (T[x].son[0])
                T[T[x].son[0]].rev ^= 1;
            if (T[x].son[1])
                T[T[x].son[1]].rev ^= 1;
            std::swap(T[x].son[0], T[x].son[1]);
            T[x].rev = 0;
        }
    }
    void rotate(int x, int kind) //1右旋，0左旋
    {
        int y = fa[x], z = fa[y];
        T[y].son[!kind] = T[x].son[kind], fa[T[x].son[kind]] = y;
        T[x].son[kind] = y, fa[y] = x;
        T[z].son[T[z].son[1] == y] = x, fa[x] = z;
        push_up(y);
    }
    void splay(int x, int goal)
    {
        if (x == goal)
            return;
        while (fa[x] != goal)
        {
            int y = fa[x], z = fa[y];
            push_down(z), push_down(y), push_down(x);
            int rx = T[y].son[0] == x, ry = T[z].son[0] == y;
            if (z == goal)
                rotate(x, rx);
            else
            {
                if (rx == ry)
                    rotate(y, ry);
                else
                    rotate(x, rx);
                rotate(x, ry);
            }
        }
        push_up(x);
        if (goal == 0)
            root = x;
    }
    int select(int pos)
    {
        int u = root;
        push_down(u);
        while (T[T[u].son[0]].sz != pos)
        {
            if (pos < T[T[u].son[0]].sz)
                u = T[u].son[0];
            else
            {
                pos -= T[T[u].son[0]].sz + 1;
                u = T[u].son[1];
            }
            push_down(u);
        }
        return u;
    }
    void add(int L, int R, int val)
    {
        int u = select(L - 1), v = select(R + 1);
        splay(u, 0);
        splay(v, u);

        T[T[v].son[0]].val += val;
        T[T[v].son[0]].maxv += val;
        T[T[v].son[0]].addv += val;
    }
    void reverse(int L, int R)
    {
        int u = select(L - 1), v = select(R + 1);
        splay(u, 0);
        splay(v, u);
        T[T[v].son[0]].rev ^= 1;
    }
    int query(int L, int R)
    {
        int u = select(L - 1), v = select(R + 1);
        splay(u, 0);
        splay(v, u);
        return T[T[v].son[0]].maxv;
    }
    int build(int L, int R)
    {
        if (L > R)
            return 0;
        if (L == R)
            return L;
        int mid = (L + R) >> 1, sL, sR;
        T[mid].son[0] = sL = build(L, mid - 1);
        T[mid].son[1] = sR = build(mid + 1, R);
        fa[sL] = fa[sR] = mid;
        push_up(mid);
        return mid;
    }
    void init(int n)
    {
        T[0].init(-INF), T[1].init(-INF), T[n + 2].init(-INF);
        for (int i = 2; i <= n + 1; i++)
            T[i].init(0);
        root = build(1, n + 2), fa[root] = 0;
        fa[0] = 0, T[0].son[1] = root, T[0].sz = 0;
    }
} spl;

int main()
{
    freopen("data.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);

    spl.init(n);
    for (int i = 0; i < m; ++i)
    {
        // printf("%d %d\n", n, m);
        int op, l, r, v;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d%d", &l, &r, &v);
            spl.add(l, r, v);
        }
        else if (op == 2)
        {
            scanf("%d%d", &l, &r);
            spl.reverse(l, r);
        }
        else
        {
            scanf("%d%d", &l, &r);
            printf("%d\n", spl.query(l, r));
        }
    }
    return 0;
}
