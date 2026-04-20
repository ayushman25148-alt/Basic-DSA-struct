# Basic-DSA-struct

A beginner-friendly collection of basic **Data Structures and Algorithms** implemented in C++.

## Contents

### Data Structures

| Structure | File | Description |
|-----------|------|-------------|
| Singly Linked List | `LinkedList/linked_list.cpp` | Insert, delete, search, reverse, display |
| Stack (Array & Linked List) | `Stack/stack.cpp` | Push, pop, peek, isEmpty |
| Queue (Circular Array & Linked List) | `Queue/queue.cpp` | Enqueue, dequeue, front, isEmpty |
| Binary Search Tree | `Tree/binary_search_tree.cpp` | Insert, delete, search, traversals, height |

### Sorting Algorithms

| Algorithm | File | Time Complexity |
|-----------|------|-----------------|
| Bubble Sort | `Sorting/sorting_algorithms.cpp` | O(n²) |
| Selection Sort | `Sorting/sorting_algorithms.cpp` | O(n²) |
| Insertion Sort | `Sorting/sorting_algorithms.cpp` | O(n²) |
| Merge Sort | `Sorting/sorting_algorithms.cpp` | O(n log n) |
| Quick Sort | `Sorting/sorting_algorithms.cpp` | O(n log n) avg |

## How to Compile and Run

Each file is self-contained with a `main()` function demonstrating usage.

```bash
# Example: compile and run linked list
g++ LinkedList/linked_list.cpp -o linked_list && ./linked_list

# Example: compile and run sorting algorithms
g++ Sorting/sorting_algorithms.cpp -o sorting && ./sorting
```
