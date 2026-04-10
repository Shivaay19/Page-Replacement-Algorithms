#ifndef HEADERS_H
#define HEADERS_H
#include <unordered_map>

class pageNode
{
    public:
    int pageNumber{};
    pageNode *next{nullptr};
    pageNode *previous{nullptr};
    
    pageNode(int p_pageNumber) : next(nullptr), previous(nullptr), pageNumber(p_pageNumber) {}
    pageNode() = default;
};

struct Misses
{
    int compulsoryMiss {};
    int capacityMiss {};
};

extern pageNode *head;
extern pageNode *tail;
void printList();
void printReferenceList(const int *const referenceList, const int &pageCount);
pageNode* createList(const int& pageNumber);
pageNode* evict_and_add(const int& pageNumber, std::unordered_map<int, pageNode*>& hashMap);
void freeListMemory();
#endif