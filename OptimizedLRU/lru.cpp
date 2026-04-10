#include "lru.h"
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
        cout << temp->pageNumber << " ";
        if(temp == head)
        {
            cout << "(LRU) ";
        }
        if(temp->next)
        {
            cout << " --> ";
        }
        else if(temp->next == nullptr && temp != head)
        {
            cout << "(MRU)  ";
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
pageNode* evict_And_Add_Page(const int &pageNumber, unordered_map<int, pageNode*>& hashMap)
{
    pageNode *createdNode{new(nothrow) pageNode(pageNumber)};
    
    if(createdNode == nullptr)
    {
        cerr << "Memory Allocation Failed\n";
        exit(1);
    }
    createdNode->previous = tail;
    tail->next = createdNode;
    tail = createdNode;
    
    cout << "Page Number : " << head->pageNumber << " --> Evicted\n";

    hashMap.erase(head->pageNumber);
    head = head->next;
    delete head->previous;
    head->previous = nullptr;
    
    return createdNode;
}
pageNode* add_Page_To_Frame(const int &pageNumber)
{
    pageNode *createdNode{new(nothrow) pageNode(pageNumber)};
    if(createdNode == nullptr)
    {
        cerr << "Memory Allocation Failed\n";
        exit(1);
    }
    if (head == nullptr && tail == nullptr)
    {
        head = createdNode;
        tail = createdNode;
        return createdNode;
    }
    createdNode->previous = tail;
    tail->next = createdNode;
    tail = createdNode;

    return createdNode;
}
pageNode* updateNodePosition(pageNode* nodePtr)
{
    if ((nodePtr)->next && (nodePtr)->previous)
    {
        (nodePtr)->previous->next = (nodePtr)->next;
        (nodePtr)->next->previous = (nodePtr)->previous;
        (nodePtr)->next = nullptr;
        (nodePtr)->previous = tail;
        tail->next = (nodePtr);
        tail = (nodePtr);
    }
    else if ((nodePtr)->next && !(nodePtr)->previous)
    {
        //Referenced Page is at the Head of the LRU List
        tail->next = (nodePtr);
        (nodePtr)->previous = tail;
        head = head->next;
        (nodePtr)->next = nullptr;
        head->previous = nullptr;
        tail = (nodePtr);
    }
    else if (!(nodePtr)->next && (nodePtr)->previous)
    {
        //Referenced Page is at the Tail of the LRU List i.e MRU. Thus no-operation required
    }
    return tail;
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