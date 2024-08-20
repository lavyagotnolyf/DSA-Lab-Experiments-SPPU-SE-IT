#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, size;
    int capacity;
    int* queue;

public:
    CircularQueue(int cap) {
        capacity = cap;
        front = rear = -1;
        size = 0;
        queue = new int[capacity];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue is full! Cannot enqueue " << value << "." << endl;
            return;
        }
        if (size == 0) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        queue[rear] = value;
        size++;
        cout << "Enqueued " << value << "." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued " << queue[front] << "." << endl;
        front = (front + 1) % capacity;
        size--;
        if (size == 0) {
            front = rear = -1;  // Reset for empty queue
        }
    }

    // Display the queue
    void display() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements are: ";
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    CircularQueue cq(capacity);

    int choice, value;
    while (true) {
        cout << "\n1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
