#include <iostream>
#include <stdlib.h>

using namespace std;


struct node
{
	int data;
	node* next;
};


class stack
{
	public:
		stack();
		~stack();
		void push(int);
		int pop();
        int popf();	
        int popt();
		void out();
		void outt();
			    
	private:
	    node* head;
        node* tail;	
};


stack::stack()
{
    head = NULL;
}    


stack::~stack()
{
    if(head==NULL) return ;
	node* n;
	while (head != tail)
	{
		n = head;
		head = head->next;
		delete n;
	}		
}

//Push last
void stack::push(int a)
{
	node* n = new node;
	n->data = a;
	n->next = head;
	if(head==NULL)
	   tail = n;
    tail->next=n;
	head = n;
}

//Pop first
int stack::pop()
{
	node* n = head;
	if (head != NULL)
	{
		head = head->next;
		delete n;
		return 0;
	}
	return 1;
}
int stack::popf()
{
	node* n = head;
	if (head != NULL)
	{
        node* x; 
        while(n->next!=NULL)
        {
            x=n;
            n = n->next;
        }
        delete n;
        x->next=NULL;
        return 0;
    }	
	return 1;
}

int stack::popt()
{
    node* n= head;
    if (head!=NULL)
    {
        while(n->next!=tail)
        {
            n=n->next;
        }    
        delete n->next;
        n->next=NULL;
        tail=n;
        return 0;
    }    
    return 1;
}

void stack::out()
{
    node *n = head;
    while (n != NULL)
    {
       cout << n->data << endl; 
       n = n->next;
    } 
    cout << endl; 
}   

void stack::outt()
{
    if(head==NULL) return ;
    
    node *n = head;
    while(n!=tail)
    {
        cout << n->data <<endl;
        n = n->next;
    }
    cout << n->data <<endl;
    /*
    cout << n->data << endl;
    n = n->data;
    while(n!=head)
    {
        cout << n->data <<endl;
        n = n->next;
    }
    cout <<endl;
    */
    cout <<endl;
}     


int main()
{
  stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.popt();
  s.popt();
  s.push(5);
  s.outt();
  system("PAUSE");	
  return 0;
}


