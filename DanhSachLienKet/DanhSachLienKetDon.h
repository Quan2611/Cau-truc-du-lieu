#include <iostream>
using namespace std;
template <class T>
class List
{
private:
	struct Node 
	{
		T data;
		Node *next;
	};
	Node *head;
	int size;
public:
	List()
	{
		size=0;
		head=NULL;
	}	
	List(int N, T value)
	{
		size=0;
		for(int i=1; i<=N; i++)
		{
			Add(value);
		}
	}
	void Add(T value)  //add truoc
	{
		Node *p=new Node;
		p->data=value;
		p->next=head;
		head=p;
		size++;
	}
	void Add1(T value) //add cuoi
	{
		Node *n = new Node;
		n->data = value;
		n->next = 0;		
		if (head == 0)
			head = n;
		else
		{
			Node *p = head;
			while (p->next != 0)
				p = p->next;
			p->next = n;
		}
		size++;
	}
	void Delete_Trc()
	{
		if(!isEmpty())
		{
			Node *p=head;
			head=head->next;
			delete p;
		}
	}
	void Delete(int pos)
	{
		if(pos==1)
		{
			Node *p=head;
			head=head->next;
			delete p;
		}
		else
		{
			Node *n=head;
			for(int i=1; i<pos-1; i++)
			{
				n=n->next;
			}
			Node *q=n->next;
			n->next=n->next->next;
			delete q;
		}
		size--;
	}
	T GetItem(int n)
	{
		Node *p=head;
		for(int i=1;i<n; i++)
		{
			p=p->next;
		}
		return p->data;
	}
	void Insert (T value, int pos)
	{
		Node *n=new Node;
		n->data=value;
		if(pos==1)
		{
			n->next=head;
			head=n;
		}
		else
		{
			Node *p=head;
			for(int i=1; i<pos-1; i++)
			{
				p=p->next;
			}
			n->next=p->next;
			p->next=n;
		}
		size++;
	}
	void Update(T newValue, int pos)
	{
		if(pos==1)
		{
			Node *p=head;
			p->data=newValue;
		}
		else
		{ 
			Node *n=head;
			for(int i=1; i<pos; i++)
			{
				n=n->next;
			}
			n->data=newValue;
		}
	}
	int Count() const
	{
		return size;
	}
	int Count(T value)
	{
		int dem=0;
		Node *p=head;
		while(p!=0)
		{
			if(p->data==value)
				dem++;
			p=p->next;	
		}
		return dem;
	}
	int Count(T value, int a, int b)
	{
		int dem=0;
		Node *p=head;
		for(int i=1; i<a; i++)
			p=p->next;
		for(int i=a; i<=b; i++)
		{
			if(p->data==value)
				dem++;
			p=p->next;	
		}
		return dem;
	}
	bool isEmpty()
	{
		return head==0;
	}
	List<T> GetListPos(T value)
	{
		List<int> a;
		Node *p=head;
		for(int i=1; p!=0; i++)
		{
			if(p->data==value)
				a.Add(i);
			p=p->next;	
		}
		return a;
	}
	friend ostream& operator<<(ostream& out, List<T> h)
	{
		Node *p=h.head;
		while(p!=0)
		{
			out<<p->data<<" ";
			p=p->next;
		}
		return out;
	}

	List<T> GetSubList(int from, int to)
	{
		List<int> a;
		Node *p=head;
		for(int i=1; i<from; i++)
			p=p->next;
		for(int i=from; i<=to; i++)
		{
			a.Add(p->data);
			p=p->next;	
		}
		return a;
	}

	List<T> Inverse() const
	{
		List<int> a;
		Node *p=head;
		while(p!=0)
		{
			a.Add(p->data);
			p=p->next;
		}
		return a;
	}
	List<T> Inverse(int fr, int to) const
	{
		List<int> a;
		Node *p=head;
		for(int i=1; i<fr; i++)
			p=p->next;
		for(int i=fr; i<=to; i++)
		{
			a.Add(p->data);
			p=p->next;
		}	
		return a;
	}
	// List<T> Giao(List<T> ds) const
	// {
	// 	List<int> a;
	// 	Node *p=head;
	// 	Node *n=ds.head;
	// 	while(p!=0&&n!=0)
	// 	{
	// 		if(p->data==n->data)
	// 			a.Add(p->data);
	// 		p=p->next;
	// 		n=n->next;
	// 	}	
	// }
};
