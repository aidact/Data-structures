#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

struct Node *front = NULL;
struct Node *last = NULL;

void push(int x){
	struct Node *a = new Node;
	a -> data = x;
	a -> next = NULL;
	if(front == NULL && last == NULL){
		front = last = a;
		return;
	}
	else{
		last -> next = a;
		last = a;
	}
}

void pop(){
	struct Node *a = front;
	if(front == NULL) return;
	if(front == last){
		front = last = NULL;
	}
	else{
		front = front -> next;
	}
	delete(a);
}

void print(){
	Node *a = front;
	while(a != NULL){
		cout<< a -> data<<' ';
		a = a -> next;
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