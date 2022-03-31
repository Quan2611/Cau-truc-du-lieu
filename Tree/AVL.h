#ifndef avl_h
#define avl_h
#include "AVLnode.h"
#include "queue.h"
template <class T>
class AVL
{
private:
    {};

public:
    AVLNode<T> *root;
    AVLNode<T> *root;
    AVLNode<T> *GetBinaryNodeByValue(T value, AVLNode<T> *r) const
    {
        if (r == 0)
            return 0;
        if (r->data == value)
            return r;
        AVLNode<T> *pl = GetBinaryNodeByValue(value, r->l);
        AVLNode<T> *pr = GetBinaryNodeByValue(value, r->r);
        if (pl != 0)
            return pl;
        if (pr != 0)
            return pr;
        return 0;
    }
    AVLNode<T> *GetFirstNode(AVLNode<T> *r) const
    {
        if (r->l == 0 || r->r == 0)
            return r;
        else
        {
            Queue<AVLNode<T> *> q;
            q.EnQueue(r);
            while (!q.IsEmpty())
            {
                AVLNode<T> *p = q.DeQueue();
                if (p->l == 0 || p->r == 0)
                {
                    return p;
                }
                else
                {
                    q.EnQueue(p->l);
                    q.EnQueue(p->r);
                }
            }
        }
        return 0;
    }
    int height(AVLNode *h)
    {
        if (h == 0)
        {
            return 0;
        }
        return h->height;
    };
};
#endif