#include <iostream>
#include <stdexcept>
#include <vector>

// Double-Ended Queue (Deque) using a circular dynamic array
class Deque {
private:
    std::vector<int> arr;
    int frontIndex;
    int rearIndex;
    int currentSize;
    int capacity;

public:
    // Constructor
    explicit Deque(int cap)
        : arr(cap), frontIndex(-1), rearIndex(-1), currentSize(0), capacity(cap) {}

    // Checks if the deque is empty
    bool isEmpty() const {
        return currentSize == 0;
    }

    // Checks if the deque is full
    bool isFull() const {
        return currentSize == capacity;
    }

    // Insert an element at the front end
    bool insertFront(int value) {
        if (isFull()) {
            std::cout << "Deque is Full! Cannot insert " << value << " at front.\n";
            return false;
        }

        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = 0;
        } else {
            // Circular decrement
            frontIndex = (frontIndex - 1 + capacity) % capacity;
        }

        arr[frontIndex] = value;
        currentSize++;
        std::cout << "Inserted at Front: " << value << "\n";
        return true;
    }

    // Insert an element at the rear end
    bool insertRear(int value) {
        if (isFull()) {
            std::cout << "Deque is Full! Cannot insert " << value << " at rear.\n";
            return false;
        }

        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = 0;
        } else {
            // Circular increment
            rearIndex = (rearIndex + 1) % capacity;
        }

        arr[rearIndex] = value;
        currentSize++;
        std::cout << "Inserted at Rear : " << value << "\n";
        return true;
    }

    // Delete an element from the front end
    int deleteFront() {
        if (isEmpty()) {
            throw std::underflow_error("Deque is Empty! Cannot delete from front.");
        }

        int removedValue = arr[frontIndex];

        if (frontIndex == rearIndex) {
            // Only one element was present
            frontIndex = -1;
            rearIndex = -1;
        } else {
            frontIndex = (frontIndex + 1) % capacity;
        }

        currentSize--;
        std::cout << "Deleted from Front: " << removedValue << "\n";
        return removedValue;
    }

    // Delete an element from the rear end
    int deleteRear() {
        if (isEmpty()) {
            throw std::underflow_error("Deque is Empty! Cannot delete from rear.");
        }

        int removedValue = arr[rearIndex];

        if (frontIndex == rearIndex) {
            // Only one element was present
            frontIndex = -1;
            rearIndex = -1;
        } else {
            rearIndex = (rearIndex - 1 + capacity) % capacity;
        }

        currentSize--;
        std::cout << "Deleted from Rear : " << removedValue << "\n";
        return removedValue;
    }

    // Get the front element
    int getFront() const {
        if (isEmpty()) {
            throw std::underflow_error("Deque is Empty! No front element.");
        }
        return arr[frontIndex];
    }

    // Get the rear element
    int getRear() const {
        if (isEmpty()) {
            throw std::underflow_error("Deque is Empty! No rear element.");
        }
        return arr[rearIndex];
    }

    // Get current number of elements
    int size() const {
        return currentSize;
    }

    // Displays all elements from front to rear
    void display() const {
        if (isEmpty()) {
            std::cout << "Deque: [Empty]\n";
            return;
        }

        std::cout << "Deque elements (Front -> Rear): ";
        for (int i = 0; i < currentSize; ++i) {
            int idx = (frontIndex + i) % capacity;
            std::cout << arr[idx] << " ";
        }
        std::cout << "(Front index = " << frontIndex << ", Rear index = " << rearIndex << ")\n";
    }
};

int main() {
    std::cout << "--- Double-Ended Queue (Deque) in C++ ---\n\n";

    Deque dq(5);

    // Insert elements at rear and front
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);
    dq.insertRear(30);
    dq.display();

    // Attempt insert when full
    dq.insertRear(40);

    std::cout << "\nCurrent Front: " << dq.getFront() << "\n";
    std::cout << "Current Rear : " << dq.getRear() << "\n\n";

    // Deletions
    dq.deleteFront();
    dq.deleteRear();
    dq.display();

    // Insert again to test wrap-around
    dq.insertFront(100);
    dq.insertRear(200);
    dq.display();

    std::cout << "\nFinal Deque Size: " << dq.size() << "\n";

    return 0;
}
