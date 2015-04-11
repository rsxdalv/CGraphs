#include <iostream>
#include <stdlib.h>

using namespace std;


struct node
{
	int data;
	node* next;
	node* prev;
};


class dstack
{
	public:
		dstack();
		~dstack();
		void push(int);
		int pop();	
		void out_next();
		void out_prev();
			    
	private:
	    node* head;		
};


dstack::dstack()
{
    head = NULL;
}    


dstack::~dstack()
{
	node* n;
	while (head != NULL)
	{
		n = head;
		head = head->next;
		delete n;
	}		
}

void dstack::push(int a)
{
    if (head == NULL)
    {
        node* n = new node;
        n->data = a;
        head = n;
        n->next = NULL;
        n->prev = head;
    }
    else
    {
        node* n = new node;
        n->data = a;   
       	n->next = head;
        head->prev = n;
        head = n;
        n->prev = head;     
    }        	
}

int dstack::pop()
{
	node* n = head;
	if (head != NULL)
	{
		head = head->next;
		head->prev = NULL;
		delete n;
		return 0;
	}
	return 1;
}


void dstack::out_next()
{
    node *n = head;
    while (n != NULL)
    {
       cout << n->data << endl; 
       n = n->next;
    } 
    cout << endl; 
}    


void dstack::out_prev()
{
    node *n = head;
    while (n->next != NULL)
    {
       n = n->next;
    } 
    while (n != head)
    {
       cout << n->data << endl; 
       n = n->prev;
    }
    cout << head->data << endl; 
} 


int main()
{
  dstack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.pop();
  s.pop();
  s.push(5);
  s.out_next();
  cout << endl;
  s.out_prev();
  cout << endl;
  system("PAUSE");	
  return 0;
}


