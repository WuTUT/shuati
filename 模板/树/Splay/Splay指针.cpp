#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct Node
{
    Node *l, *r;
    int val;
    int cnt;
    int sz;
    Node(int val) : val(val), l(NULL), r(NULL), cnt(1), sz(1) {}
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
inline void zag(Node *&x)
{
    Node *t = x->r; //不可以是引用
    x->r = t->l;
    t->l = x;
    update(x);
    update(t);

    x = t;
}
inline void zig(Node *&x)
{
    Node *t = x->l; //不可以是引用
    x->l = t->r;
    t->r = x;
    update(x);
    update(t);

    x = t;
}
void splay(Node *x, Node *&y)
{
    if (x == y)
    {
        return;
    }
    if (y->l == x)
    {
        zig(y);
    }
    else if (y->r == x)
    {
        zag(y);
    }
    else
    {
        if (x->val < y->val)
        {
            if (x->val < y->l->val) //zig zig
            {
                splay(x, y->l->l);
                zig(y);
                zig(y);
            }
            else //zig zag
            {
                splay(x, y->l->r);
                zag(y->l);
                zig(y);
            }
        }
        else
        {
            if (x->val < y->r->val) //zag zig
            {
                splay(x, y->r->l);
                zig(y->r);
                zag(y);
            }
            else //zag zag
            {
                splay(x, y->r->r);
                zag(y);
                zag(y);
            }
        }
    }
    //cout << x->val << endl;
}
void insert(Node *&x, int val)
{
    if (x == NULL)
    {
        x = new Node(val);
        splay(x, root);
    }
    else if (val < x->val)
    {
        insert(x->l, val);
    }
    else if (val > x->val)
    {
        insert(x->r, val);
    }
    else
    {
        x->sz++;
        x->cnt++;
        splay(x, root);
    }
}

void delNode(Node *&x)
{
    splay(x, root);
    //x=root //也不对,root下面的节点乱了
    if (root->cnt > 1)
    {
        root->cnt--;
        root->sz--;
    }
    else
    {
        if (root->r == NULL)
        {
            Node *t = root;
            root = root->l;
            free(t);
            t = NULL;
            //  update(root);
        }
        else
        {
            Node *t = root->r;
            while (t->l)
            {
                t = t->l;
            }
            splay(t, root->r);
            root->r->l = root->l;
            t = root;
            root = root->r;
            free(t);
            t = NULL;

            update(root);
        }
    }
}
void del(Node *&x, int val)
{
    //  cout << "IIII " << x->val << " " << val << endl;
    if (x->val < val)
    {
        del(x->r, val);
    }
    else if (x->val > val)
    {
        del(x->l, val);
    }
    else
    {
        delNode(x);
    }
}

int getRank(int val)
{
    int tmp = 1;
    Node *p = root;
    while (p)
    {
        if (p->val < val)
        {
            if (p->l)
            {
                tmp += p->l->sz;
            }
            tmp += p->cnt;
            p = p->r;
        }
        else if (p->val > val)
        {
            p = p->l;
        }
        else
        {
            if (p->l)
            {
                tmp += p->l->sz;
            }
            splay(p, root);
            break;
        }
    }
    return tmp;
}
int getVal(int rank)
{
    Node *p = root;

    while (p)
    {
        if (p->l && p->l->sz >= rank)
        {
            p = p->l;
            continue;
        }
        int tmp = p->cnt;
        if (p->l)
        {
            tmp += p->l->sz;
        }
        if (tmp >= rank)
        {
            int ans = p->val;
            splay(p, root);
            return ans;
        }
        else
        {
            rank -= tmp;
            p = p->r;
        }
    }
}

int getPre(int val)
{

    int ret = -2147483647;
    Node *p = root;
    Node *q;
    while (p)
    {
        if (p->val < val)
        {
            ret = p->val;
            q = p;
            p = p->r;
        }
        else
        {

            p = p->l;
        }
    }
    if (q != NULL)
        splay(q, root);
    return ret;
}
int getPost(int val)
{
    int ret = 2147483647;
    Node *p = root;
    Node *q;
    while (p)
    {
        if (p->val > val)
        {
            ret = p->val;
            q = p;
            p = p->l;
        }
        else
        {
            p = p->r;
        }
    }

    // cout << ret << endl;
    if (q != NULL)
        splay(q, root);
    return ret;
}
void inorder(Node *p)
{
    if (p == NULL)
        return;
    inorder(p->l);
    cout << p->val << " ";
    inorder(p->r);
}
int main()
{
    int n;
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    cin >> n;
    int op;
    int val;
    for (int i = 1; i <= n; i++)
    {
        //printf("which i %d\n", i);
        scanf("%d%d", &op, &val);
        if (op == 1)
        {
            insert(root, val);
            // inorder(root);
            // cout << endl;
            //printf("1\n");
        }
        else if (op == 2)
        {
            del(root, val);
            //printf("1\n");
        }
        else if (op == 3)
        {

            printf("%d\n", getRank(val));
        }
        else if (op == 4)
        {

            printf("%d\n", getVal(val));
        }
        else if (op == 5)
        {
            printf("%d\n", getPre(val));
        }
        else if (op == 6)
        {
            printf("%d\n", getPost(val));
        }
    }
    return 0;
}