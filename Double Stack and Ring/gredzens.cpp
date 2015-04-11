#include <iostream>
#include <stdlib.h>

using namespace std;


struct node
{
	int data;
	node* next;
};


class gredzens
{
	public:
		gredzens();
		~gredzens();
		void push(int);
		int pop();	
		void out(); // visi elementi
		void out(int); // elementu skaits
			    
	private:
	    node* head;		
	    node* tail;	
};


gredzens::gredzens()
{
    head = tail = NULL;
}    


gredzens::~gredzens()
{
	node* n;
	while (head != tail)
	{
		n = head;
		head = head->next;
		delete n;
	}		
}

void gredzens::push(int a)
{
    if (head == NULL)
    {
        node* n = new node;
        n->data = a;
        head = n;
        n->next = n;
        tail = n;
    }
    else
    {
        node* n = new node;
        n->data = a;   
       	n->next = head;
        tail->next = n;
        head = n;
    }  
}

int gredzens::pop() // dzesam to uz kuru noraada head
{
	node* n = head;
	if (head != NULL)
	{
	    tail->next = head->next;
		head = head->next;
		delete n;
		return 0;
	}
	return 1;
}


void gredzens::out()
{
    node *n = head;
    while (n != tail)
    {
       cout << n->data << endl; 
       n = n->next;
    } 
    cout << tail->data;
    cout << endl; 
} 


void gredzens::out(int x)
{
    node *n = head;
    int i = 0;
    while (i<x)
    {
       cout << n->data << endl; 
       n = n->next;
       i++;
    } 
    cout << endl; 
}       


int main()
{
  gredzens s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.pop();
  s.pop();
  s.push(5);
  s.out();
  cout << endl;
  s.out(8);
  system("PAUSE");	
  return 0;
}


