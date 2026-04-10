# FIFO Page Replacement Algorithm

This directory contains a **First‑In First‑Out (FIFO)** page replacement algorithm implementation.

## Overview

FIFO evicts the page that has been in memory the longest when a new page needs to be loaded and the cache is full. It is simple to implement and serves as a baseline for comparing more sophisticated algorithms like LRU.

## Files
- `fifo.h` – Definition of the `pageNode` structure and function prototypes.
- `fifo.cpp` – Implementation of the linked‑list based FIFO queue and helper functions.
- `main.cpp` – Driver program that reads a reference string, runs the simulation, and reports hit/miss statistics.

## Building and Running
```bash
cd FIFO
# Compile all source files (requires C++17 support)
g++ -std=c++17 *.cpp -o fifo_sim
# Run the simulation (it will prompt for the reference string and cache size)
./fifo_sim
```

## Expected Output
The program prints the reference list, the state of the queue after each page reference, and a summary of **hits**, **compulsory misses**, and **capacity misses**.

## Extending
Feel free to modify the simulation parameters, add command‑line arguments, or integrate this implementation into a larger memory‑management project.
