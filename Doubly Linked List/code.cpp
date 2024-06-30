#include <iostream>

using namespace std;

class DoublyLinkedNode
{
public:
    DoublyLinkedNode()
    {
        Data = 0;
        next = NULL;
        prev = NULL;
    }
    int Data; // Data stored in the node
    DoublyLinkedNode* next; // Pointer to the next node
    DoublyLinkedNode* prev; // Pointer to the previous node
};

// Function to add a new node to the end of the list
void AddToEnd(DoublyLinkedNode* head, DoublyLinkedNode* newNode)
{
    DoublyLinkedNode* temp = head;

    // Traverse to the end of the list
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Add the new node at the end
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
}

// Function to remove a node from the end of the list
DoublyLinkedNode* RemoveFromEnd(DoublyLinkedNode* head)
{
    // Traverse to the second last node
    while (head->next->next != NULL)
    {
        head = head->next;
    }
    DoublyLinkedNode* temp = head->next;
    head->next = NULL;
    temp->prev = NULL;
    return temp;
}

// Function to add a new node at a specific index in the list
void AddInBetween(DoublyLinkedNode* head, DoublyLinkedNode* newNode, int index)
{
    // Traverse to the node before the specified index
    for (int i = 0; i < index - 2; i++)
    {
        head = head->next;
    }
    // Insert the new node
    newNode->next = head->next;
    if (head->next != NULL)
    {
        head->next->prev = newNode;
    }
    head->next = newNode;
    newNode->prev = head;
}

// Function to remove a node at a specific index in the list
DoublyLinkedNode* RemoveFromBetween(DoublyLinkedNode* head, int index)
{
    // Traverse to the node before the specified index
    for (int i = 0; i < index - 2; i++)
    {
        head = head->next;
    }

    // Remove the node at the specified index
    DoublyLinkedNode* temp = head->next;
    head->next = head->next->next;
    if (head->next != NULL)
    {
        head->next->prev = head;
    }
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

// Function to remove a node with a specific value from the list
DoublyLinkedNode* Remove(DoublyLinkedNode* head, int item) {
    // Traverse to find the node with the specified value
    while (head != NULL && head->Data != item) {
        head = head->next;
    }

    if (head == NULL) {
        // Node with the specified value not found
        cout << "The searched value could not be found" << endl;
        return NULL;
    }
    else if (head->next == NULL && head->prev == NULL) {
        // If there's only one node
        return NULL;
    }
    else if (head->next == NULL) {
        // If it's the last node
        head->prev->next = NULL;
        return head;
    }
    else if (head->prev == NULL) {
        // If it's the first node
        head->next->prev = NULL;
        return head;
    }
    else {
        // If it's a middle node
        head->prev->next = head->next;
        head->next->prev = head->prev;
        return head;
    }
}

// Main function to demonstrate the usage of the doubly linked list
int doubly_linked_list_main()
{
    // Create nodes
    DoublyLinkedNode* n1 = new DoublyLinkedNode();
    DoublyLinkedNode* n2 = new DoublyLinkedNode();
    DoublyLinkedNode* n3 = new DoublyLinkedNode();
    DoublyLinkedNode* n4 = new DoublyLinkedNode();

    // Assign values to the nodes
    n1->Data = 25;
    n2->Data = 30;
    n3->Data = 40;
    n4->Data = 50;

    // Link nodes
    n1->next = n3;
    n3->prev = n1;
    n3->next = n4;
    n4->prev = n3;

    // Add new nodes to the end of the list
    DoublyLinkedNode* new1 = new DoublyLinkedNode();
    new1->Data = 55;
    AddToEnd(n1, new1);

    DoublyLinkedNode* new2 = new DoublyLinkedNode();
    new2->Data = 120;
    AddToEnd(n1, new2);

    // Traverse and print the list
    DoublyLinkedNode* temp = n1;
    while (temp != NULL)
    {
        cout << temp->Data << endl;
        temp = temp->next;
    }

    return 0;
}
