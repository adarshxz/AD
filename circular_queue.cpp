#include <iostream>
#include <stdexcept>
#include <vector>

// Circular Queue implementation using a fixed-capacity dynamic array
class CircularQueue {
private:
    std::vector<int> queue;
    int frontIndex;
    int rearIndex;
    int currentSize;
    int capacity;

public:
    // Constructor
    explicit CircularQueue(int cap)
        : queue(cap), frontIndex(0), rearIndex(-1), currentSize(0), capacity(cap) {}

    // Checks if the queue is empty
    bool isEmpty() const {
        return currentSize == 0;
    }

    // Checks if the queue is full
    bool isFull() const {
        return currentSize == capacity;
    }

    // Inserts an element into the circular queue
    bool enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is Full! Cannot enqueue " << value << "\n";
            return false;
        }

        // Circular increment of rear index
        rearIndex = (rearIndex + 1) % capacity;
        queue[rearIndex] = value;
        currentSize++;
        std::cout << "Enqueued: " << value << "\n";
        return true;
    }

    // Removes an element from the circular queue
    int dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is Empty! Cannot dequeue.");
        }

        int removedValue = queue[frontIndex];
        // Circular increment of front index
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
        std::cout << "Dequeued: " << removedValue << "\n";
        return removedValue;
    }

    // Returns the front element without removing it
    int peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is Empty! No front element.");
        }
        return queue[frontIndex];
    }

    // Returns the current number of elements
    int size() const {
        return currentSize;
    }

    // Displays all elements currently in the circular queue
    void display() const {
        if (isEmpty()) {
            std::cout << "Queue: [Empty]\n";
            return;
        }

        std::cout << "Queue elements: ";
        for (int i = 0; i < currentSize; ++i) {
            int idx = (frontIndex + i) % capacity;
            std::cout << queue[idx] << " ";
        }
        std::cout << "(Front = " << frontIndex << ", Rear = " << rearIndex << ")\n";
    }
};

int main() {
    std::cout << "--- Circular Queue in C++ ---\n\n";

    CircularQueue cq(5);

    // Enqueue elements
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.display();

    // Dequeue elements to free front slots
    std::cout << "\n--- Dequeue Operations ---\n";
    cq.dequeue();
    cq.dequeue();
    cq.display();

    // Enqueue more elements to test circular wrap-around
    std::cout << "\n--- Wrap-around Enqueue Operations ---\n";
    cq.enqueue(50);
    cq.enqueue(60);
    cq.enqueue(70);
    cq.display();

    // Attempting to enqueue when full
    cq.enqueue(80);

    // Inspect front element
    std::cout << "\nCurrent Front Element: " << cq.peek() << "\n";
    std::cout << "Current Queue Size:    " << cq.size() << "\n";

    return 0;
}
