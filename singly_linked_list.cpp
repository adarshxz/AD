#include <iostream>

// Node representation for Singly Linked List
struct ListNode {
    int data;
    ListNode* next;

    ListNode(int val) : data(val), next(nullptr) {}
};

// Singly Linked List class
class SinglyLinkedList {
private:
    ListNode* head;
    int size;

public:
    // Constructor
    SinglyLinkedList() : head(nullptr), size(0) {}

    // Destructor to free all allocated memory
    ~SinglyLinkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        size = 0;
    }

    // Insert at beginning (Head)
    void insertAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Insert at end (Tail)
    void insertAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Delete first occurrence of a value
    bool deleteByValue(int val) {
        if (head == nullptr) return false;

        if (head->data == val) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            size--;
            return true;
        }

        ListNode* current = head;
        while (current->next != nullptr && current->next->data != val) {
            current = current->next;
        }

        if (current->next != nullptr) {
            ListNode* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
            size--;
            return true;
        }

        return false;
    }

    // Search for a value in the list
    bool search(int val) const {
        ListNode* current = head;
        while (current != nullptr) {
            if (current->data == val) return true;
            current = current->next;
        }
        return false;
    }

    // Reverse the linked list in-place (O(n) time, O(1) space)
    void reverse() {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Display all elements in the list
    void display() const {
        if (head == nullptr) {
            std::cout << "[Empty List]\n";
            return;
        }

        ListNode* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }

    int getSize() const { return size; }
};

int main() {
    SinglyLinkedList list;

    std::cout << "--- Singly Linked List in C++ ---\n\n";

    // Insert elements
    std::cout << "1. Inserting elements:\n";
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.insertAtHead(5);

    std::cout << "List after insertions: ";
    list.display();
    std::cout << "Total elements: " << list.getSize() << "\n\n";

    // Search
    std::cout << "2. Search operations:\n";
    std::cout << "Search 30: " << (list.search(30) ? "Found" : "Not Found") << "\n";
    std::cout << "Search 99: " << (list.search(99) ? "Found" : "Not Found") << "\n\n";

    // Deletion
    std::cout << "3. Delete operations:\n";
    std::cout << "Deleting 20... " << (list.deleteByValue(20) ? "Success" : "Failed") << "\n";
    std::cout << "Deleting 5 (head)... " << (list.deleteByValue(5) ? "Success" : "Failed") << "\n";
    std::cout << "List after deletions: ";
    list.display();
    std::cout << "Total elements: " << list.getSize() << "\n\n";

    // Reversal
    std::cout << "4. Reversing the list in-place:\n";
    list.reverse();
    std::cout << "Reversed list: ";
    list.display();

    return 0;
}
