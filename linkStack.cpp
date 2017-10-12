#include <iostream>
using namespace std;

struct Node // cerate struct with two parametrs
{
	int data; // the element
	struct Node *next; // link to next element
};

struct Node *top = NULL; // last element of stack? firstly there is nothing

void push(int x){ // add
	struct Node *a = new Node; 
	a -> data = x; // current's element is x
	a -> next = top; // then this a licnks on the next element
	top = a; // new element will be the last
}

void pop(){
	struct Node *a;
	if(top == NULL) // there is nothing in stack
		return;
	a = top; // current is last
	top = top -> next; 
	delete(a); 
}

void print(){
	Node *a = top; // start from top
	while(a != NULL){ // until it's not nothing
		cout<< a -> data<<' '; // we print elements
		a = a -> next; // then go to the next
	}
}

int main(){
	push(7);
	push(6);
	push(8);
	push(9);
	pop();
	pop();
	print();

	return 0;
}