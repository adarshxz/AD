#include <iostream>
using namespace std;

#define MAX 5

int stack_arr[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1)
        cout << "Stack Overflow\n";
    else {
        stack_arr[++top] = x;
        cout << x << " pushed\n";
    }
}

void pop() {
    if (top == -1)
        cout << "Stack Underflow\n";
    else
        cout << stack_arr[top--] << " popped\n";
}

int main() {
    push(10);
    push(20);
    pop();
    pop();
    pop();   // underflow check
    return 0;
}

