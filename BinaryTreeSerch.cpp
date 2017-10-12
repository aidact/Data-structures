#include <iostream>
using namespace std;

struct node {
  int value;
  node *left;
  node *right;
};

//struct node* top = NULL;

bool search(node *top, int x){
  if (top->value == x){
    return true;
  }
  else if (top->value > x){
    if (top->left == NULL){
      return false;
    }
  	return search(top->left, x);
  }
  else if (top->value < x){
    if (top->right == NULL){
      return false;
    }
    return search(top->right, x);
  }
  return false; 
}


node* add(node *top, int value){
  if(top == NULL) {
    top = new node();
    top->value = value;
    top->left = top->right = NULL;
  }
  else if(value <= top->value)
    top->left = add(top->left,value);
  else 
    top->right = add(top->right,value);
  return top;
}

node* findMin(node* top){
  while (top -> left != NULL) 
    top = top -> left;
    return top;
}


struct node* Delete (struct node *top, int value){
  if (top == NULL) return top;
  else if (value < top->value ) top -> left = Delete(top -> left, value);
  else if (value > top->value) top ->right = Delete(top -> right, value);
  else {
    if (top -> left == NULL && top -> right == NULL){
      delete top;
      top = NULL;
    }

    else if (top -> left == NULL){
      struct node *t = top;
      top = top -> right;
      delete t;

    }

    else if (top -> right == NULL){
      struct node *t = top;
      top = top -> left;
      delete t;
    }

    else {

      struct node *t = findMin(top->right);
      top -> value = t ->value;
      top -> right = Delete(top -> right, t -> value);
    }
  }

  return top;
}

void print(node *top){
  cout << "[" << top -> value << " ";
  if (top -> left != NULL){
    print(top-> left);
  }
  if (top -> right != NULL){
    print (top -> right);
  }
  cout << " ]";

}

int main(){
  node* top = NULL;
  top = add(top, 8);
  top = add(top, 4);
  top = add(top, 6);
  top = add(top, 7);
  top = add(top, 1);
  top = Delete(top, 6);
  print(top);

}