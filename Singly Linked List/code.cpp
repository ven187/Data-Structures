#include <windows.h> // Windows-specific header, not used in this code
#include <iostream>

using namespace std;

// Definition of the node class for the linked list
class Node
{
public:
    int Data;           // Data stored in the node
    Node* pNext;        // Pointer to the next node

    // Constructor to initialize a node
    Node()
    {
        Data = 0;       // Initialize data to 0
        pNext = nullptr; // Initialize next pointer to nullptr
    }
};

// Function to add a node to the end of the linked list
void Append(Node* pHead, Node* pNewNode)
{
    while (pHead->pNext != nullptr) // Traverse to the last node
    {
        pHead = pHead->pNext;
    }
    pHead->pNext = pNewNode; // Append pNewNode (new node) to the end
}

// Function to remove and return the last node from the linked list
Node* RemoveLast(Node* pHead)
{
    while (pHead->pNext->pNext != nullptr) // Traverse to the second last node
    {
        pHead = pHead->pNext;
    }
    Node* pTemp = pHead->pNext; // Store the last node
    pHead->pNext = nullptr; // Remove the link to the last node
    return pTemp; // Return the removed node
}

// Function to add a node after a specific index in the linked list
void InsertAfter(Node* pHead, Node* pNewNode, int index)
{
    for (int i = 0; i < index - 1; i++) // Traverse to the node just before the index
    {
        pHead = pHead->pNext;
    }
    pNewNode->pNext = pHead->pNext; // Insert pNewNode after the node at 'index'
    pHead->pNext = pNewNode;
}

// Function to remove and return a node at a specific index from the linked list
Node* RemoveAtIndex(Node* pHead, int index)
{
    for (int i = 0; i < index - 1; i++) // Traverse to the node just before the index
    {
        pHead = pHead->pNext;
    }
    Node* pTemp = pHead->pNext; // Store the node to be removed
    pHead->pNext = pHead->pNext->pNext; // Remove the link to the node
    return pTemp; // Return the removed node
}

// Main function demonstrating usage of the linked list functions
int main()
{
    // Creating nodes
    Node* pNode1 = new Node();
    Node* pNode2 = new Node();
    Node* pNode3 = new Node();
    Node* pNode4 = new Node();
    
    // Assigning data to nodes
    pNode1->Data = 25;
    pNode2->Data = 30;
    pNode3->Data = 40;
    pNode4->Data = 50;

    // Constructing the initial linked list structure
    pNode1->pNext = pNode3;
    pNode3->pNext = pNode4;

    // Adding new nodes to the end of the linked list
    Node* pNewNode1 = new Node();
    pNewNode1->Data = 55;
    Append(pNode1, pNewNode1);
    
    Node* pNewNode2 = new Node();
    pNewNode2->Data = 120;
    Append(pNode1, pNewNode2);

    // Traversing and printing the linked list
    Node* pTemp = pNode1;
    while (pTemp != nullptr)
    {
        cout << pTemp->Data << endl;
        pTemp = pTemp->pNext;
    }

    return 0;
}
