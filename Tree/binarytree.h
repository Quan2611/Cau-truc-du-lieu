#ifndef binarytree_h
#define binarytree_h
#include "binarynode.h"
#include "queue.h"
template <class T>
class BinaryTree
{
private:
    BinaryNode<T> *root;
    BinaryNode<T> *GetBinaryNodeByValue(T value, BinaryNode<T> *r) const
    {
        if (r == 0)
            return NULL;
        if (r->data == value)
            return r;
        BinaryNode<T> *pl = GetBinaryNodeByValue(value, r->left);
        BinaryNode<T> *pr = GetBinaryNodeByValue(value, r->right);
        if (pl != NULL)
            return pl;
        if (pr != NULL)
            return pr;
        return NULL;
    }
    BinaryNode<T> *GetFirstNode(BinaryNode<T> *r) const
    {
        if (r->left == 0 || r->right == 0)
            return r;
        else
        {
            Queue<BinaryNode<T> *> q;
            q.EnQueue(r);
            while (!q.IsEmpty())
            {
                BinaryNode<T> *p = q.DeQueue();
                if (p->left == 0 || p->right == 0)
                {
                    return p;
                }
                else
                {
                    q.EnQueue(p->left);
                    q.EnQueue(p->right);
                }
            }
        }
        return 0;
    }

public:
    BinaryTree()
    {
        root = 0;
    };
    void Add(T t)
    {
        BinaryNode<T> *n = new BinaryNode<T>;
        n->data = t;
        n->left = 0;
        n->right = 0;
        if (root == 0)
            root = n;
        else
        {
            BinaryNode<T> *p = GetFirstNode(root);
            if (p->left == 0)
                p->left = n;
            else
                p->right = n;
        }
    };
    T GetLeft(T value) const
    {
        BinaryNode<T> *p = GetBinaryNodeByValue(value, root);
        return p->left->data;
    }
};

#endif