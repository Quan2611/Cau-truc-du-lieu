#ifndef LIST_H
#define LIST_H
#include "node.h"

template <class T>
class List
{
private:
    Node<T> *head;

public:
    List()
    {
        head = NULL;
    };
    List(int spt, T t){

    };

    void AddTruoc(T v) // Add trước
    {
        Node<T> *p = new Node;
        p->data = v;
        p->next = head;
        head = p;
    };

    void Add(T t) // Add cuối
    {
        Node<T> *n = new Node<T>;
        n->data = t;
        n->next = NULL;

        if (head == NULL)
            head = n;
        else
        {
            Node<T> *h = head;
            while (h->next != NULL)
                h = h->next;
            h->next = n;
        }
    };

    T GetItem(int pos) const
    {
        Node<T> *h = head;
        for (int i = 1; i < pos; i++)
            h = h->next;
        return h->data;
    };

    int GetItemAt(T N)
    {
        Node<T> *p = head;
        while (N > 1)
        {
            p = p->next;
            N--;
        }
        /*Cách 2:
        Node<T> *p = head;
        for(int i；i<N；i++)
        {
          p=p->next;
        }


        //Cách 3:
        Node<T> *p = head;
        while(i<N)
        {
          p=p->next;
          i++;
        }
        */
    }

    int Count() const
    {
        Node<T> *h = head;
        int dem = 0;
        while (h != NULL)
        {
            h = h->next;
            dem++;
        }
        return dem;
    };

    void Update(int pos, T value)
    {
        Node<T> *h = head;
        for (int i = 1; i < pos; i++)
            h = h->next;
        h->data = value;
    };

    void Insert(T value, int pos)
    {
        Node<T> *n = new Node<T>;
        n->data = value;
        if (pos == 1)
        {
            n->next = head;
            head = n;
        }
        else
        {
            Node<T> *h = head;
            for (int i = 1; i < pos - 1; i++)
            {
                h = h->next;
            }
            n->next = h->next;
            h->next = n;
        }
    };

    void Replace(T old_value, T new_value)
    {
        Node<T> *h = head;
        while (h != NULL)
        {
            if (h->data == old_value)
            {
                h->data = new_value;
            }
            h = h->next;
        }
    };

    void Delete(int pos)
    {
        if (pos == 1)
        {
            Node<T> *q = head;
            head = head->next;
            delete q;
        }
        else
        {
            Node<T> *h = head;
            for (int i = 1; i < pos - 1; i++)
            {
                h = h->next;
            }
            // Nếu không có lệnh sau thì Node cần xóa không được giải phóng
            Node<T> *q = h->next; // q là Node cần xóa
            h->next = q->next;
            delete q;
        }
    };

    void Swap(int pos1, int pos2)
    {
        Node<T> *p = head;
        for (int i = 1; i < pos1; i++)
        {
            p = p->next;
        }
        Node<T> *q = head;
        for (int i = 1; i < pos2; i++)
        {
            q = q->next;
        }

        T t = p->data;
        p->data = q->data;
        q->data = t;
    }

    int LastIndex(T v) const
    {
        int index = 0, pos = 1;
        Node<T> *h = head;
        while (h != 0)
        {
            if (h->data == v)
                index = pos;
            pos++;
            h = h->next;
        }
    }
    return index;

    int FirstIndex(T v) const
    {
        Node<T> *h = head;
        int i = 1;
        while (h != NULL)
        {
            if (h->data == v)
            {
                return i;
            }
            i++;
            h = h->next;
        }
        return 0;
    };
};
// void UpdateValue(T old_value, T new_value)
// {
//     Node<T> *h = head;
//     while (h != NULL)
//     {
//         if (h->data == old_value)
//         {
//             h->data = new_value;
//         }
//         h = h->next;
//     }
// };

// void Insert(T value, int pos)
// {
//     Node<T> *n = new Node<T>;
//     n->data = value;
//     if (pos == 1)
//     {
//         n->next = head;
//         head = n;
//     }
//     else
//     {
//         Node<T> *h = head;
//         for (int i = 1; i < pos - 1; i++)
//         {
//             h = h->next;
//         }
//         n->next = h->next;
//         h->next = n;
//     }
// };
#endif