#include <iostream>

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List implementation
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
    }

    // Insert at front
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at back
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete first occurrence of a value
    bool deleteValue(int val) {
        Node* current = head;
        while (current != nullptr && current->data != val) {
            current = current->next;
        }

        if (!current) return false; // Value not found

        if (current == head && current == tail) {
            head = tail = nullptr;
        } else if (current == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (current == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
        return true;
    }

    // Print list from head to tail
    void displayForward() const {
        Node* temp = head;
        std::cout << "Forward:  ";
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // Print list from tail to head
    void displayBackward() const {
        Node* temp = tail;
        std::cout << "Backward: ";
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;

    std::cout << "--- Doubly Linked List Operations ---\n";

    dll.insertAtTail(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.insertAtHead(5);

    std::cout << "\nAfter insertions (5 at head, 10, 20, 30 at tail):\n";
    dll.displayForward();
    dll.displayBackward();

    std::cout << "\nDeleting value 20:\n";
    dll.deleteValue(20);
    dll.displayForward();
    dll.displayBackward();

    std::cout << "\nDeleting head (5) and tail (30):\n";
    dll.deleteValue(5);
    dll.deleteValue(30);
    dll.displayForward();
    dll.displayBackward();

    return 0;
}
