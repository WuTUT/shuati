#include <iostream>
#include <cstdio>
using namespace std;
int n;
struct BST
{
    BST *l, *r;
    int val;
    int lsz; //左子树的大小
    BST(int val) : val(val), l(NULL), r(NULL), lsz(0) {}
};
BST *root;
int val;

//查找x的排名
int searchv(BST *root)
{
    if (root == NULL) //再加上1
    {
        return 1;
    }
    if (root->val > val)
    {
        return searchv(root->l);
    }
    else if (root->val < val)
    {
        return root->lsz + 1 + searchv(root->r);
    }
    else
    {
        return root->lsz + 1;
    }
}
//查找排名为x的数
int searchi(BST *root, int has) //has为前面计算好的左子树+根
{
    int tmp = root->lsz + 1 + has;
    if (tmp == val)
    {
        return root->val;
    }
    else if (tmp < val)
    {
        return searchi(root->r, tmp);
    }
    else
    {
        return searchi(root->l, has);
    }
}
//前驱
int findpre(BST *root)
{
    if (root == NULL)
    {
        return -2147483647;
    }
    if (root->val < val)
    {
        if (root->r && root->r->val < val)
        {
            return findpre(root->r);
        }
        else
        {
            return root->val;
        }
    }
    else
    {
        return findpre(root->l);
    }
}
//后继
int findpost(BST *root)
{
    if (root == NULL)
    {
        return 2147483647;
    }
    if (root->val > val)
    {
        if (root->l && root->l->val > val)
        {
            return findpost(root->l);
        }
        else
        {
            return root->val;
        }
    }
    else
    {
        return findpost(root->r);
    }
}
void insert(BST *&root)
{

    if (root == NULL)
    {
        root = new BST(val);
        return;
    }
    if (root->val <= val)
    {

        insert(root->r);
    }
    else if (root->val > val)
    {
        root->lsz++;
        insert(root->l);
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    cin >> n;
    int op;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &op, &val);
        if (op == 1)
        {
            printf("%d\n", searchv(root));
        }
        else if (op == 2)
        {
            printf("%d\n", searchi(root, 0));
        }
        else if (op == 3)
        {
            printf("%d\n", findpre(root));
        }
        else if (op == 4)
        {
            printf("%d\n", findpost(root));
        }
        else if (op == 5)
        {
            insert(root);
        }
    }
    return 0;
}