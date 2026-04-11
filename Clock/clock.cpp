#include "clock.h"
#include <iostream>

using namespace std;

pageNode *head = nullptr;
pageNode *tail = nullptr;
pageNode *current = nullptr;

pageNode* addToList(int pageNumber)
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
        current = createdNode;
        tail->next = head;
        head->previous = tail;
        return createdNode;
    }

    head->previous = createdNode;
    tail->next = createdNode;
    createdNode->previous = tail;
    createdNode->next = head;
    tail = createdNode;

    return createdNode;
}
pageNode* evictAndAdd(int pageNumber, unordered_map<int, pageNode*>& hashMap)
{
    while(current->referenceBit)
    {
        current->referenceBit = false;
        current = current->next;
    }
    //current points to the page that can be evicted
    
    pageNode* victimPageAddress = current;

    hashMap.erase(victimPageAddress->pageNumber);
    victimPageAddress->pageNumber = pageNumber;
    victimPageAddress->referenceBit = true;

    current = victimPageAddress->next;

    return victimPageAddress;
}
void printList()
{
    pageNode *temp = head;
    do
    {
        cout << temp->pageNumber << " ";

        if(temp->next && temp->next != head)
        {
            cout << " --> ";
        }

        temp = temp->next;
    } while (temp != head);
    cout << "\n\n";
}
void printReferenceList(const int *const referenceList, int pageCount)
{
    cout << "The reference list of Pages is: \n";
    for (int i = 0; i < pageCount; ++i)
    {
        cout << referenceList[i] << "  ";
    }
    cout << "\n\n";
}
void freeListMemory()
{
    pageNode* temp = head->next;

    while (temp != head)
    {
        pageNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    delete head;

    head = nullptr;
    tail = nullptr;
    current = nullptr;
}