#include <iostream>
using namespace std;

struct Node{
	int val;
	struct Node*next;
};

struct Node * top = NULL;
struct Node * a = new Node;

void push(int x){
	if(top == NULL){
		top = new Node;
		top -> val = x;
		top -> next = a;
	}
	else{
		struct Node * el = new Node;
		el = a;
		el ->value = x;
		a = new Node;
		el -> next = a;
	}
}

void pop(){
	if(top != NULL){
		int b = top -> val;
		if(top -> next != NULL)
			top = top -> next;
		cout<<b;
	}
	else return;
}

int main(){
	push(10);
	push(1);
	pop();

	return 0;
}