# Naive LRU Implementation

This directory contains a C++ implementation of the **Least Recently Used (LRU)** Page Replacement algorithm.

## Architecture & Data Structures
The LRU cache is modeled using a **Doubly Linked List** to maintain the recency of accessed pages:
- **Head of the List (`head`)**: Represents the Least Recently Used (LRU) page. It is always the prime candidate for eviction when a capacity miss occurs.
- **Tail of the List (`tail`)**: Represents the Most Recently Used (MRU) page.

Every time a page is accessed:
1. It is searched for in the list.
2. If found (a Hit), it is unlinked from its current position and moved to the `tail` to mark it as the most recently accessed.
3. If not found (a Miss) and the cache is full, the `head` is evicted, and the new page is appended at the `tail`.

## Time Complexity
This specific implementation is naive because it solely relies on the doubly linked list and lacks a hash map (or lookup table) for $O(1)$ page searches. 

As a result, searching for a page requires a linear scan of the linked list. 
- **Time Complexity per access**: $O(K)$ where $K$ is the number of allotted page frames.
- **Overall Time Complexity**: $O(N \times K)$ or roughly **$O(N^2)$** where $N$ is the total number of page accesses in the reference string, since locating nodes scales linearly.

Note: For a fully optimized LRU (which runs in $O(N)$), a Hash Map is typically paired with the Doubly Linked List.

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
- `main.cpp`: The driver file handling console I/O, simulation execution, and hit/miss ratio calculation.
