# Optimized LRU Implementation

This directory contains a C++ implementation of the **Least Recently Used (LRU)** Page Replacement algorithm.

## Architecture & Data Structures
The LRU cache is modeled using a combination of a **Doubly Linked List** and a **Hash Map (`std::unordered_map`)**:
- **Doubly Linked List**: Maintains the recency of accessed pages.
  - **Head (`head`)**: Represents the Least Recently Used (LRU) page, which is evicted when a capacity miss occurs.
  - **Tail (`tail`)**: Represents the Most Recently Used (MRU) page.
- **Hash Map (`hashMap`)**: Maps page numbers to their corresponding nodes in the linked list, allowing for rapid $O(1)$ lookups.

Every time a page is accessed:
1. It is looked up in the Hash Map in $O(1)$ time.
2. If found (a Hit), the corresponding node is unlinked from its current position and moved to the `tail` to mark it as the most recently accessed.
3. If not found (a Miss) and the cache is full, the `head` is evicted, the evicted page is removed from the Hash Map, and the new page is appended at the `tail` and added to the Hash Map.

## Time Complexity
Because this implementation utilizes a Hash Map for lookups alongside the Doubly Linked List, the time complexity is highly optimized.
- **Time Complexity per access**: $O(1)$ expected time.
- **Overall Time Complexity**: $O(N)$ where $N$ is the total number of page accesses in the reference string.

## Miss Tracking
The simulation accurately categorizes cache misses:
- **Compulsory Misses (Cold-Start)**: The very first time a page is brought into an empty or partially-filled cache frame.
- **Capacity Misses**: Occur when the cache is completely full, forcing an eviction of the LRU page to bring in the new page.

*Note: Conflict Misses are not possible in a fully-associative cache design like this one. In this context, main memory acts as a cache for virtual memory, which is why we refer to the paging system as a "cache."*

## Running the Simulation

Compile the source files using any standard C++ compiler:

```bash
g++ -std=c++17 main.cpp lru.cpp -o lru_sim
./lru_sim
```

**Files:**
- `lru.h` / `lru.cpp`: Defines the node structure, list operations, and memory cleanup.
- `main.cpp`: The driver file handling console I/O, simulation execution, hash map operations, and hit/miss ratio calculation.
