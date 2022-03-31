#ifndef queue_h
#define queue_h
template <class T>
class Queue
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    Queue()
    {
        head = 0;
        tail = 0;
    };
    void EnQueue(T t)
    {
        Node<T> *n = new Node<T>;
        n->data = t;
        n->next = NULL;

        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
    };
    T DeQueue()
    {
        T t = head->data;
        Node<T> *p = head;
        head = head->next;
        delete p;
        return t;
    };
    T GetFirst() const
    {
        return head->data;
    };
    bool IsEmpty() const
    {
        return head == 0;
    };
};

#endif