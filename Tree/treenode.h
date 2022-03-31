#ifndef treenode_h
#define treenode_h
template <class T>
struct TreeNode
{
    T data;
    TreeNode<T> *l;
    TreeNode<T> *r;
};

#endif