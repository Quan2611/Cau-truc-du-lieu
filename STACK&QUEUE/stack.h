#ifndef STACK_H
#define STACK_H
template <class T>
class Stack
{
private:
    Node<T> *top;

public:
    Stack()
    {
        top == 0;
    };

    void push(T newdata)
    {
        Node<T> *p = new Node<T>;
        p->data = newdata;
        p->next = top;
        top = p;
    };

    T pop()
    {
        T p = top->data;
        Node<T> *t = top;
        top = top->next;
        delete t;
        return p;
    };

    void getTop()
    {
        return top->data;
    };

    bool isEmpty() const
    {
        return top == 0;
    };
};
#endif