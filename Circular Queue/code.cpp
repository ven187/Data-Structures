#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Queue size
class CircularQueue
{
public:
    CircularQueue();
    bool Enqueue(int item);    // Adds an item to the end of the queue
    int Dequeue();             // Removes the item at the front of the queue
    bool IsEmpty();            // Checks if the queue is empty
    void Print();              // Prints all items from the front to the end of the queue
private:
    int data[MAX_SIZE];
    int front, rear, itemCount;
};

CircularQueue::CircularQueue()
{
    front = 0;     // Front of the queue
    rear = -1;     // End of the queue (initialized to -1 since the queue is empty initially)
    itemCount = 0; // Number of items in the queue
}

bool CircularQueue::IsEmpty()
{
    return (itemCount == 0);
}

bool CircularQueue::Enqueue(int item)
{
    if (itemCount >= MAX_SIZE)   // If the queue is full
        return false;

    rear = (rear + 1) % MAX_SIZE; // Move the end of the queue to the next position
    data[rear] = item;            // Add the new item to the end of the queue
    itemCount++;                  // Increase the item count
    return true;
}

int CircularQueue::Dequeue()
{
    if (IsEmpty())    // If the queue is empty
        return -1;    // Error condition, return -1 or an appropriate error code

    int removed = data[front];      // Get the item at the front of the queue
    front = (front + 1) % MAX_SIZE; // Move the front of the queue to the next position
    itemCount--;                    // Decrease the item count
    return removed;
}

void CircularQueue::Print()
{
    if (IsEmpty())
    {
        cout << "The queue is empty." << endl;
        return;
    }

    cout << "Queue elements: ";
    int count = itemCount;
    int i = front;
    while (count > 0)
    {
        cout << data[i] << " ";
        i = (i + 1) % MAX_SIZE;
        count--;
    }
    cout << endl;
}

int circular_queue_main()
{
    CircularQueue cq;
    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);

    cq.Print();

    cq.Dequeue();
    
    cq.Enqueue(50);
    cq.Enqueue(60);
    cq.Enqueue(70);
    cq.Dequeue();

    cq.Enqueue(300);
    cq.Print();

    return 0; // successfully
}
