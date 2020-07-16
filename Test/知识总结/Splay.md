**Splay Tree 伸展树**

1. 递归版本、指针版本、自顶而下
   * 插入
   ```cpp
    void insert(Node *&x, int val)
    {
        if (x == NULL)
        {
            x = new Node(val);
            splay(x, root);//记得写，且不能写在外面
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
            splay(x, root);//同样不能写在外面
        }
    }
   ```
   * Zig Zag Splay
   ```cpp
    inline void zag(Node *&x)
    {
        Node *t = x->r;
        x->r = t->l;
        t->l = x;
        update(t);
        update(x);
        x = t;
    }
    inline void zig(Node *&x)
    {
        Node *t = x->l;
        x->l = t->r;
        t->r = x;
        update(t);
        update(x);
        x = t;
    }
   ``` 
   Splay
   ```cpp
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
                if (x->val < y->l->val)//zig zig
                {
                    splay(x, y->l->l);
                    zig(y); //?????如果zig(y->l)怎么样
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
                if (x->val < y->r->val)//zag zig
                {
                    splay(x, y->r->l);
                    zag(y->r);
                    zag(y);
                }
                else//zag zag
                {
                    splay(x, y->r->r);
                    zag(y);
                    zag(y);
                }
            }
        }
    }
   ```

   `splay(x,goal)` 原型 `splay(Node*x,Node*&y)` 注意x指向的内容会改变，因此Splay后一定不能使用`x->` 而是要操作y，而且y是传入的指针的引用所以y被改为了x

   如果是三点一线的话（x，x的父亲，x的祖父）需要先rotate x的父亲，否则需要先rotate x本身（否则会形成单旋使平衡树失衡）