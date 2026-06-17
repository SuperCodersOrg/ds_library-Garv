# Project 01 – Design Proposal
## Project Objective

The objective of this project is to design a reusable and memory-safe Data Structure Library consisting of DynamicArray, LinkedList, and HashMap implementations.

The proposed design supports explicit memory ownership, predictable performance, and maintainability. For the Design choices i evaluated multiple alternatives for each data structure and selected the one with best tradeoff keeping in mind that later on we will be using these data structures in our upcoming projects like redis lite and ensuring that the selected approach best satisfies the upcoming project requirements.


# Section 1 – Public API
The proposed design extends the suggested interface with several modifications and utility operations 

### 1. DynamicArray 
Methods - 
```cpp
DynamicArray() //construct empty array
void append(int value) //append element
void insert(int index, int value) //insert at position
void remove(int index) //remove element
bool get(int index, int& value) const //returns value
void set(int index, int value) // modify value at given index
void reserve(int newCapacity) //preallocate storage 
void popBack() //remove last element
void clear() //remove all elements
int size() const //return element count
int capacity() const //return allocated capacity
bool isEmpty() const //check whether empty 
~DynamicArray() //destructor
DynamicArray(const DynamicArray&) //copy constructor
DynamicArray& operator=(const DynamicArray&) //assignment operator
```
- The get() method returns the requested element through a reference parameter and uses a boolean return value to indicate success, avoiding ambiguous sentinel values for invalid indices.  
- The reserve() method enables preallocation of storage when the expected number of elements is known, reducing the number of reallocations during repeated insertions.  
- A dedicated set() method separates modification from insertion operations.  
- Utility functions such as `popBack()`,` clear()`,` capacity()`, and `isEmpty()` improve the usability and completeness of the Data Structure.

---

### 2. LinkedList 
The LinkedList is implemented as a singly linked structure while maintaining both head and tail pointers along with the current node count. This allows constant time insertion at both ends while minimizing per node memory overhead .
Methods - 

```cpp
LinkedList() //construct empty linkedlist
void insertFront(int value) //insert at front
void insertBack(int value) //insert at end 
void insert(int index, int value) //insert at position
void removeFront() //remove first node
void remove(int index) //remove node from a specific position
int search(int value) const //search element
void clear() //delete all nodes
void print() const //display all contents
int size() const //return node count
bool isEmpty() const //check whether empty
~LinkedList() //destructor
LinkedList(const LinkedList&) //copy constructor
LinkedList& operator=(const LinkedList&) //assignment operator
```
- The insertBack() method uses the tail pointer to achieve O(1) insertion at the end of the list, improving time complexity for common use cases.
- The search() method returns the index of the found element or -1 if not found, providing more useful information than a simple boolean result.
- Utility functions such as `remove()`,` clear()`, and `isEmpty()` improve the usability and completeness of the Data Structure.

---

