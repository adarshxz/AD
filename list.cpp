#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* front = NULL;  // Empty list

    // STEP 1-3: Insert at front (newest first)
    front = new Node{10, front};
    front = new Node{20, front};
    front = new Node{30, front};
    cout << "List: 30 20 10" << endl;

    // STEP 4-5: Delete front
    if (front) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    cout << "After delete: 20 10" << endl;

    return 0;
}

