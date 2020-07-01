#include <iostream>
#include <cstdio>
using namespace std;
struct Node
{
    Node *l, *r;
    int val;
    int cnt;
    int sz;
    Node(int val) : val(val), l(NULL), r(NULL), cnt(1) {}
} * root;
inline void update(Node *x)
{
    int tmp = 0;
    if (x->l)
    {
        tmp += x->l->sz;
    }
    if (x->r)
    {
        tmp += x->r->sz;
    }
    tmp += x->cnt;
    x->sz = tmp;
}
inline void lrotate(Node *&x)
{
    Node *t = x->r;
    x->r = t->l;
    t->l = x;

    update(x);
    t = x;
}
inline void rrotate(Node *&x)
{
    Node *t = x->l;
    x->l = t->r;
    t->r = x;
    update(x);
    x = t;
}
void insert(Node *&x)
{
}

int main()
{

    return 0;
}