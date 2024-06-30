#include <iostream>

using namespace std;

const int QUEUE_MAX = 10; // Maximum size of the queue

class LinearQueue {
public:
    LinearQueue();
    bool Enqueue(int item); // Adds an item to the queue
    int Dequeue();          // Removes an item from the queue
    bool IsEmpty();         // Checks if the queue is empty
    void Print();           // Prints all items in the queue

private:
    int data[QUEUE_MAX]; // Array to store queue elements
    int front, rear;     // Indices for the front and rear of the queue
};

LinearQueue::LinearQueue() {
    front = -1; // Initialize front index to -1
    rear = -1;  // Initialize rear index to -1
}

bool LinearQueue::IsEmpty() {
    return (front == -1 && rear == -1);
}

bool LinearQueue::Enqueue(int item) {
    if (front >= QUEUE_MAX - 1) // If the queue is full
        return false;
    if (IsEmpty()) // If the queue is empty
        rear++;
    front++;
    data[front] = item;
    return true;
}

int LinearQueue::Dequeue() {
    if (IsEmpty()) // If the queue is empty
        return -1; // Error condition, return -1 or an appropriate error code
    int item = data[rear]; // Get the item at the front of the queue
    for (int i = 0; i < front; i++) {
        data[i] = data[i + 1]; // Shift elements to the left
    }
    front--;
    if (front < 0) { // If the queue is empty
        front = -1;
        rear = -1;
    }
    return item;
}

void LinearQueue::Print() {
    for (int i = 0; i <= front; i++)
        cout << data[i] << " ";
    cout << endl;
}

int linear_queue_main()
{
    LinearQueue queue;

    // Enqueue elements
    queue.Enqueue(5);
    queue.Enqueue(10);
    queue.Enqueue(15);

    // Print the current state of the queue
    cout << "Queue State: ";
    queue.Print();

    // Dequeue an element
    cout << "Dequeued Element: " << queue.Dequeue() << endl;

    // Print the updated state of the queue
    cout << "Updated Queue State: ";
    queue.Print();

    return 0;
}
