#ifndef binarynode_h
#define binarynode_h
template <class T>
struct BinaryNode
{
    T data;
    BinaryNode<T> *left;
    BinaryNode<T> *right;
};

#endif