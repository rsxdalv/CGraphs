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
		void out();
			    
	private:
	    node* head;		
};


stack::stack()
{
    head = NULL;
}    


stack::~stack()
{
	node* n;
	while (head != NULL)
	{
		n = head;
		head = head->next;
		delete n;
	}		
}

void stack::push(int a)
{
	node* n = new node;
	n->data = a;
	n->next = head;
	head = n;
}

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


int main()
{
  stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.pop();
  s.pop();
  s.push(5);
  s.out();
  system("PAUSE");	
  return 0;
}


