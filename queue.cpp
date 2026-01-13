#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    queue<int> q;
    q.push(10); q.push(20); q.push(30);
    
    cout << "Original queue (front to back): ";
    queue<int> temp = q;
    while(!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Delete last added using stack
    stack<int> s;
    while(!q.empty()) { s.push(q.front()); q.pop(); }
    cout << "Deleting last: " << s.top() << endl;
    s.pop();

    // Restore queue
    while(!s.empty()) { q.push(s.top()); s.pop(); }

    cout << "After delete (front to back): ";
    temp = q;
    while(!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    return 0;
}
