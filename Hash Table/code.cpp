#include <iostream>
#include <locale>

const int MAX = 10; // Maximum size for the hash table

class Cell
{
public:
    int Key;
    int Status;
    Cell()
    {
        Status = 0; // 0 indicates an empty cell
    }
};

const int LIMIT = 10; // Limit for the hash table

class HashOpen
{
public:
    void List(); // List all elements
    Cell Data[LIMIT];
    HashOpen();
    bool Add(int Key);    // Add a key to the hash table
    bool Remove(int Key); // Remove a key from the hash table
    Cell* Get(int Key);   // Get a cell by key
};

HashOpen::HashOpen()
{
    for (int i = 0; i < LIMIT; i++)
        Data[i].Status = 0;
}

bool HashOpen::Add(int Key)
{
    int mod = Key % LIMIT;
    int i = mod;
    while (Data[i].Status == 1)
    {
        if (i == LIMIT - 1)
            i = 0;
        else
            i++;
        if (i == mod)
            return false;
    }
    Data[i].Key = Key;
    Data[i].Status = 1;
    return true;
}

bool HashOpen::Remove(int Key)
{
    int mod = Key % LIMIT;
    int i = mod;
    while (Data[i].Status != 0)
    {
        if (Data[i].Key == Key)
        {
            if (Data[i].Status == 1)
            {
                Data[i].Status = 2;
                return true;
            }
        }
        if (i == LIMIT - 1)
            i = 0;
        else
            i++;
        if (i == mod)
            return false;
    }
    return false;
}

void HashOpen::List()
{
    for (int i = 0; i < LIMIT; ++i)
    {
        if (Data[i].Status == 1)
        {
            std::cout << "Key: " << Data[i].Key << std::endl;
        }
    }
}

class Node
{
public:
    int Key;
    Node* Next;

    Node(int Key)
    {
        this->Key = Key;
        this->Next = nullptr;
    }
};

class HashTable
{
public:
    void List(); // List all elements
    Node* Data[MAX];
    HashTable();
    void Add(int Key);    // Add a key to the hash table
    Node* Get(int Key);   // Get a node by key
    bool Remove(int Key); // Remove a key from the hash table
};

HashTable::HashTable()
{
    for (int i = 0; i < MAX; i++)
        Data[i] = nullptr;
}

void HashTable::Add(int Key)
{
    Node* newNode = new Node(Key);
    int mod = Key % MAX;
    if (!Data[mod])
    {
        Data[mod] = newNode;
    }
    else
    {
        Node* temp = Data[mod];
        while (temp->Next != nullptr)
            temp = temp->Next;
        temp->Next = newNode;
    }
}

Node* HashTable::Get(int Key)
{
    int mod = Key % MAX;
    Node* temp = Data[mod];
    while (temp != nullptr)
    {
        if (temp->Key == Key)
            return temp;
        temp = temp->Next;
    }
    return nullptr;
}

bool HashTable::Remove(int Key)
{
    int mod = Key % MAX;
    if (!Data[mod])
        return false;

    if (!Data[mod]->Next)
    {
        if (Data[mod]->Key == Key)
        {
            delete Data[mod];
            Data[mod] = nullptr;
            return true;
        }
        return false;
    }

    if (Data[mod]->Key == Key)
    {
        Node* toDelete = Data[mod];
        Data[mod] = Data[mod]->Next;
        delete toDelete;
        return true;
    }

    Node* temp = Data[mod];
    while (temp->Next != nullptr)
    {
        if (temp->Next->Key == Key)
        {
            Node* toDelete = temp->Next;
            temp->Next = toDelete->Next;
            delete toDelete;
            return true;
        }
        temp = temp->Next;
    }
    return false;
}

void HashTable::List()
{
    for (int i = 0; i < MAX; ++i)
    {
        Node* temp = Data[i];
        while (temp != nullptr)
        {
            std::cout << "Key: " << temp->Key << std::endl;
            temp = temp->Next;
        }
    }
}

int hash_table_main()
{
    setlocale(LC_ALL, "turkish");

    // HashOpen example
    HashOpen hashOpen;
    // Add keys
    hashOpen.Add(12);
    hashOpen.Add(22);
    hashOpen.Add(7);
    hashOpen.Add(15);

    // List elements in HashOpen class
    std::cout << "HashOpen Class:" << std::endl;
    hashOpen.List();
    std::cout << std::endl;

    // Remove keys
    hashOpen.Remove(22);
    hashOpen.Remove(15);

    // List elements in HashOpen class after removal
    std::cout << "HashOpen Class (After Removal):" << std::endl;
    hashOpen.List();
    std::cout << std::endl;

    // HashTable example
    HashTable hashTable;

    // Add keys
    hashTable.Add(12);
    hashTable.Add(22);
    hashTable.Add(7);
    hashTable.Add(15);

    // List elements in HashTable class
    std::cout << "HashTable Class:" << std::endl;
    hashTable.List();
    std::cout << std::endl;

    // Remove keys
    hashTable.Remove(22);
    hashTable.Remove(15);

    // List elements in HashTable class after removal
    std::cout << "HashTable Class (After Removal):" << std::endl;
    hashTable.List();
    std::cout << std::endl;

    return 0;
}
