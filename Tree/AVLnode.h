#ifndef avlnode_h
#define avlnode_h
template <class T>
struct AVLNode
{
    T data;
    AVLNode<T> *l;
    AVLNode<T> *r;
    int height;
};

#endif