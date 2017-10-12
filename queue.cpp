#include <iostream>

using namespace std;

int a[100100], l = 0, r = 0;

bool isEmpty() {
    if (l == r) return true;
    return false;
}

int getSize() {
    return r - l;
}

void push(int value) {
    a[r++] = value;
}

int front() {
    if (l != r) return a[l];
    else return -1;
}

void pop() {
    if (l != r) l++;
}

int main () {

    return 0;
}