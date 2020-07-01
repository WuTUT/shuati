#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
    Node *l, *r;
    int val;
    int height;
    Node(int val) : val(val), l(NULL), r(NULL), height(1) {}
} * avl;
int val;

inline int getBalanced(Node *x)
{
    int lh = 0;
    if (x->l)
    {
        lh = x->l->height;
    }
    int rh = 0;
    if (x->r)
    {
        rh = x->r->height;
    }
    return lh - rh;
}
inline void updateHeight(Node *x)
{
    int lh = 0;
    if (x->l)
    {
        lh = x->l->height;
    }
    int rh = 0;
    if (x->r)
    {
        rh = x->r->height;
    }
    x->height = max(lh, rh) + 1;
    return;
}
void leftRotate(Node *&x)
{
    Node *t = x->r;
    x->r = x->r->l;
    t->l = x;
    updateHeight(x);
    updateHeight(t);
    x = t;
}
void rightRotate(Node *&x)
{
    Node *t = x->l;
    x->l = x->l->r;
    t->r = x;
    updateHeight(x);
    updateHeight(t);
    x = t;
}

void insert(Node *&x)
{
    if (x == NULL)
    {
        x = new Node(val);
        return;
    }
    if (val < x->val)
    {

        insert(x->l);
        updateHeight(x);
        if (getBalanced(x) == 2)
        {
            if (getBalanced(x->l) == 1)
            {
                rightRotate(x);
            }
            else
            {
                leftRotate(x->l);
                rightRotate(x);
            }
        }
    }
    else
    {
        insert(x->r);
        updateHeight(x);
        if (getBalanced(x) == -2)
        {
            if (getBalanced(x->r) == 1)
            {
                rightRotate(x->r);
                leftRotate(x);
            }
            else
            {
                leftRotate(x);
            }
        }
    }
}
vector<int> ans;
bool isct;
void bfs(Node *x)
{
    isct = true;
    bool fir = false;
    if (x == NULL)
        return;
    queue<Node *> q;
    q.push(x);
    while (!q.empty())
    {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            Node *tmp = q.front();
            q.pop();
            ans.push_back(tmp->val);
            if (!tmp->l && !tmp->r)
            {
                fir = true;
            }
            else
            {
                if (fir)
                {
                    isct = false;
                }
                if (tmp->l && tmp->r)
                {
                    q.push(tmp->l);
                    q.push(tmp->r);
                }
                else if (tmp->l && !tmp->r)
                {
                    fir = true;
                    q.push(tmp->l);
                }
                else if (!tmp->l && tmp->r)
                {
                    q.push(tmp->r);
                    isct = false;
                }
            }
        }
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &val);
        insert(avl);
    }
    bfs(avl);
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans[ans.size() - 1] << endl;
    if (isct)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
//完全Complete Tree判断条件
//层序遍历
//PTA1123 Is It a Complete AVL Tree (30分)