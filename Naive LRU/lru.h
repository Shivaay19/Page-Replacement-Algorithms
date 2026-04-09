#ifndef HEADERS_H
#define HEADERS_H
#include <utility>

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
std::pair<bool, pageNode*> searchPage(const int &pageNumber);
void simulateLRU(const int &pageFramesAlloted, const int *const referenceList, const int &pageCount, Misses& missData, int& distinctPageAccesses);
void printList();
void printReferenceList(const int *const referenceList, const int &pageCount);
void evict_And_Add_Page(const int &pageNumber);
void add_Page_To_Frame(const int &pageNumber);
void updateNodePosition(pageNode* (nodePtr));
void freeListMemory();
#endif