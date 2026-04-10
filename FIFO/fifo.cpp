#include "fifo.h"
#include <iostream>
#include <unordered_map>

using namespace std;

pageNode *head = nullptr;
pageNode *tail = nullptr;

void printList()
{
    pageNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->pageNumber;
        if(temp == head)
        {
            cout << " (First In) ";
        }
        if(temp->next)
        {
            cout << " --> ";
        }
        temp = temp->next;
    }
    cout << "\n\n";
}
void printReferenceList(const int *const referenceList, const int &pageCount)
{
    cout << "The reference list of Pages is: \n";
    for (int i = 0; i < pageCount; ++i)
    {
        cout << referenceList[i] << "  ";
    }
    cout << "\n\n";
}
pageNode* createList(const int& pageNumber)
{
    pageNode* createdNode {new(nothrow) pageNode(pageNumber)};
    if(createdNode == nullptr)
    {
        cerr << "Memory Allocation Failed\n";
        exit(1);
    }

    if(head == nullptr && tail == nullptr)
    {
        head = createdNode;
        tail = createdNode;
        return createdNode;
    }

    tail->next = createdNode;
    createdNode->previous = tail;
    tail = createdNode;

    return createdNode;
}
pageNode* evict_and_add(const int& pageNumber, unordered_map<int, pageNode*>& hashMap)
{
    pageNode* createdNode {new(nothrow) pageNode(pageNumber)};
    if(createdNode == nullptr)
    {
        cerr << "Memory Allocation Failed\n";
        exit(1);
    }

    tail->next = createdNode;
    createdNode->previous = tail;
    tail = createdNode;

    cout << "Page Number : " << head->pageNumber << " --> Evicted\n";

    hashMap.erase(head->pageNumber);
    head = head->next;
    delete head->previous;
    head->previous = nullptr;
    return createdNode;
}
void freeListMemory()
{
    pageNode *temp {};
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}