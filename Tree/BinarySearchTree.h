#include "treenode.h"
#include "queue.h"
#ifndef bst_h
#define bst_h
template <class T>
class BST
{
private:
    TreeNode<T> *root;

    void AddToRoot(TreeNode<T> *&g, T v)
    {
        if (g == 0)
        {
            g = new TreeNode<T>;
            g->data = v;
            g->l = 0;
            g->r = 0;
        }
        else
        {
            if (g->data > v)
                AddToRoot(g->l, v);
            else if (g->data < v)
                AddToRoot(g->r, v);
        }
    };
    bool SearchFromRoot(TreeNode<T> *g, T v) const
    {
        if (g == 0)
            return false;
        if (g->data == v)
            return true;
        else if (g->data > v)
            return SearchFromRoot(g->l, v);
        else
            return SearchFromRoot(g->r, v);
    };

public:
    BST()
    {
        root = 0;
    };
    void Add(T v)
    {
        AddToRoot(root, v);
    };
    bool Search(T v) const
    {
        return SearchFromRoot(root, v);
    };
};

#endif