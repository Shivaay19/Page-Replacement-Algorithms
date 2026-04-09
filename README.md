# Page Replacement Algorithms

This repository contains implementations and simulations of various Page Replacement Algorithms used in operating systems for Virtual Memory management. 

Page replacement algorithms decide which memory pages to page out (swap out, write to disk) when a page of memory needs to be allocated. Different algorithms have different trade-offs in terms of performance and overhead.

## Current Implementations

* **[Naive LRU](./Naive%20LRU/)** - A simple approach to the Least Recently Used (LRU) algorithm.

## Getting Started

Each algorithm is contained within its own subdirectory alongside its respective documentation and source files. To run a specific simulation, navigate into its folder and compile the C++ source files.

```bash
# Example for Naive LRU
cd "Naive LRU"
g++ -std=c++17 main.cpp lru.cpp -o lru_sim
./lru_sim
```
