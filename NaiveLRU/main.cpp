#include "lru.h"
#include <iostream>
#include <unordered_set>

using namespace std;

void simulateLRU(const int &pageFramesAlloted, const int *const referenceList, const int &pageCount, Misses& missData)
{
    int pageFramesUsed {};
    unordered_set<int> seenPages {};
    for (int i = 0; i < pageCount; ++i)
    {
        pair<bool, pageNode *> status{searchPage(referenceList[i])};

        if (status.first)
        {
            cout << "Page Number : " << referenceList[i] << " --> Page Hit\n";
            updateNodePosition(status.second);
        }
        else
        {
            if(seenPages.find(referenceList[i]) == seenPages.end())
            {
                cout << "Page Number : " << referenceList[i] << " --> Page Miss --> Compulsory Miss\n";
                seenPages.insert(referenceList[i]);
                ++(missData.compulsoryMiss);
            }
            else
            {
                cout << "Page Number : " << referenceList[i] << " --> Page Miss --> Capacity Miss\n";
                ++(missData.capacityMiss);
            }
            if (pageFramesUsed == pageFramesAlloted)
            {
                evict_And_Add_Page(referenceList[i]);
            }
            else
            {
                add_Page_To_Frame(referenceList[i]);
                ++pageFramesUsed;
            }
        }
        cout << "Current LRU List: ";
        printList();
    }
}

int main()
{
    int pageFramesAlloted{};
    int pageCount{};

    cout << "Enter the Number of Physical Page Frames available\n";
    cin >> pageFramesAlloted;

    cout << "Enter the Number of Pages Referenced\n";
    cin >> pageCount;
    
    if(pageFramesAlloted <= 0 || pageCount <= 0)
    {
        cerr << "Invalid Request\n";
        exit(1);
    }

    int *referenceList{new int[pageCount]};

    for (int i = 0; i < pageCount; ++i)
    {
        cout << "Enter the Page Number Referenced : ";
        cin >> referenceList[i];
    }
    cout << '\n';
    printReferenceList(referenceList, pageCount);

    Misses missData {};

    simulateLRU(pageFramesAlloted, referenceList, pageCount, missData);
    
    cout << "Want Miss/Hit Ratio? (y/n) : ";
    char choice {};
    cin >> choice;

    while(true)
    {
        if(choice == 'y')
        {
            cout << "Compulsory Misses : " << missData.compulsoryMiss << '\n';
            cout << "Capacity Misses : " << missData.capacityMiss << '\n';
            cout << "Total Page Access : " << pageCount << '\n';
            cout << "Miss Ratio : " << (static_cast<double>(missData.compulsoryMiss) + static_cast<double>(missData.capacityMiss)) / pageCount << '\n';
            cout << "Calculate Hit Ratio Yourself :) (Hint : Subtract Miss Ratio from 1)\n";
            break;
        }
        else if(choice == 'n') break;
        else
        {
            cout << "Invalid Choice! Please Choose (y/n).\n";
            cin >> choice;
        }
    }

    freeListMemory();
    delete[] referenceList;
    return 0;
}