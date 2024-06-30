#include <iostream>

using namespace std;

const int STACK_MAX = 10; // Maximum size of the stack

class Stack {
public:
    Stack(); // Constructor to initialize the stack
    bool Push(int item); // Push an item onto the stack
    int Pop(); // Pop an item from the stack
    bool IsEmpty(); // Check if the stack is empty
    int TopRet(); // Return the top item without popping it
    void WriteAll(); // Write all items and pop them
    void DeleteAll(); // Delete all items in the stack
    void WriteAllNotDelete(); // Write all items without popping them
    int Top_get(); // (Unused) Return the top item without popping it

private:
    int D[STACK_MAX]; // Array to store stack items
    int Top; // Index of the top item
};

Stack::Stack() {
    Top = 0; // Initialize the stack as empty
}

bool Stack::IsEmpty() {
    return Top <= 0; // Return true if the stack is empty
}

bool Stack::Push(int item) {
    if (Top >= STACK_MAX)
        return false; // Return false if the stack is full
    D[Top] = item; // Add the item to the stack
    Top++; // Increment the top index
    return true;
}

int Stack::Pop() {
    if (Top <= 0)
        return -1; // Return -1 if the stack is empty
    Top--; // Decrement the top index
    return D[Top]; // Return the top item
}

int Stack::TopRet() {
    if (Top <= 0)
        return -1; // Return -1 if the stack is empty
    return D[Top - 1]; // Return the top item without popping it
}

void Stack::DeleteAll() {
    Top = 0; // Reset the stack to empty
}

void Stack::WriteAll() {
    while (TopRet() != -1)
        cout << Pop() << " - "; // Pop and print all items
    cout << endl;
}

void Stack::WriteAllNotDelete() {
    cout << "Stack elements: ";
    for (int i = Top - 1; i >= 0; --i) 
    {
        cout << D[i];
        if (i > 0) {
            cout << " - ";
        }
    }
    cout << endl;
}

int stack_main() {
    Stack myStack;

    // Push items onto the stack
    myStack.Push(10);
    myStack.Push(20);
    myStack.Push(30);

    // Print all items without deleting them
    myStack.WriteAllNotDelete();

    // Print the top item
    cout << "Top element of the stack: " << myStack.TopRet() << endl;

    // Pop an item and print it
    int popped = myStack.Pop();
    cout << "Popped element: " << popped << endl;

    // Check if the stack is empty and print the result
    if (myStack.IsEmpty()) {
        cout << "The stack is empty." << endl;
    }
    else {
        cout << "The stack is not empty." << endl;
    }

    return 0;
}
