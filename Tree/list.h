#ifndef list_h
#define list_h
#include "node.h"
template <class T>
class List
{
private:
    Node<T> *head;

public:
    List()
    {
        head = 0;
    }
    void Add(T v)
    {
        if (head == 0)
        {
            head = new Node<T>;
            head->data = v;
            head->next = 0;
        }
        else
        {
            Node<T> *p = new Node<T>;
            p->data = v;
            p->next = head;
            head = p;
        }
    }
    bool Search(T v) const
    {
        Node<T> *h = head;
        while (h != 0)
        {
            if (h->data == v)
        }
        }
};

#endif