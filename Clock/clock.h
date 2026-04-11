#ifndef HEADERS_H
#define HEADERS_H
#include <unordered_map>

class pageNode
{
    public:
    int pageNumber{};
    pageNode *next{nullptr};
    pageNode *previous{nullptr};
    bool referenceBit {true};
    
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
extern pageNode *current;

void printList();
pageNode* addToList(int pageNumber);
pageNode* evictAndAdd(int pageNumber, std::unordered_map<int, pageNode*>& hashMap);
void printReferenceList(const int *const referenceList, int pageCount);
void freeListMemory();
#endif