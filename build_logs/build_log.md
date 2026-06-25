# Build Log

## Entry 1

**Date:** June 18, 2026

**Duration:**  4 Hours

**Goal:**
Complete the Phase 0 design proposal and plan the implementation of DynamicArray, LinkedList, HashMap, and Redis Lite.

**Problem Encountered:**
how to explain object lifetime and copying decisions.

**What I Tried:**
Reviewed the required sections of the design proposal. Created memory diagrams for dynamic allocation, linked nodes, and HashMap buckets. Compared deep copy and shallow copy behavior.

**Outcome:**
Completed the design decisions, API planning, and memory management explanation. Prepared the proposal structure before starting implementation.

---


## Entry 2

**Date:** June 20, 2026

**Duration:** 2.5 Hours

**Goal:**
Refactor the design proposal documentation and create separate design proposal files for DynamicArray, LinkedList, and HashMap.

**Problem Encountered:**
The original proposal contained all three data structures in a single document, making it difficult to organize design decisions, complexity analysis, and memory management details for each structure independently.

**What I Tried:**

* Reviewed the existing combined design proposal.
* Split the documentation into three separate files:

  * DynamicArray Design Proposal
  * LinkedList Design Proposal
  * HashMap Design Proposal
* Expanded the design decision sections for each data structure.
* Added explanations for deep copy versus shallow copy.
* Documented Rule of Three requirements.
* Added complexity analysis tables.
* Created memory diagrams and internal representation explanations.
* Compared alternative designs before selecting the final implementations.
* Documented HashMap collision handling, rehashing strategy, and bucket storage design.

**Outcome:**
Successfully reorganized the project documentation into three independent design proposals. Each proposal now contains its own public API, internal representation, complexity estimates, memory management strategy, and design rationale. The documentation is more structured, easier to review, and better reflects the engineering decisions behind each data structure.

---



## Entry 3

**Date:** June 24, 2026

**Duration:** 1 Hours

**Goal:**
Implement the core memory management functionality of the DynamicArray, including object construction, destruction, copying, and assignment.

**Problem Encountered:**
Managing memory manually was more complex than expected. Since the implementation uses dynamic memory allocation, I needed to ensure that copied DynamicArray objects do not share the same memory. I also had to understand how object lifetime is handled when allocating raw memory.

**What I Tried:**

* Implemented the default constructor to initialize size, capacity, and allocate memory.
* Implemented the destructor to properly release allocated memory and prevent memory leaks.
* Implemented the copy constructor to create a deep copy of another DynamicArray.
* Implemented the copy assignment operator and added a self-assignment check.
* Studied the difference between shallow copy and deep copy.
* Explored how STL containers manage object lifetime internally.
* Investigated manual memory management using `malloc()`, `free()`, and placement new.
* Tested copying arrays containing primitive types and strings.

**Outcome:**
Successfully implemented the Rule of Three for DynamicArray:

* Constructor
* Destructor
* Copy Constructor
* Copy Assignment Operator

The DynamicArray now supports independent copies of objects without shared ownership issues. Memory is released correctly, and copied arrays maintain their own storage, preventing double deletion and dangling pointer problems.

---


## Entry 4

**Date:** June 24, 2026

**Duration:** 1 Hours

**Goal:**
Implement the core DynamicArray operations including append, insert, remove, and automatic resizing.

**Problem Encountered:**
Managing element movement during insertion and deletion required careful handling to avoid overwriting existing values. Resizing the array also required copying existing elements into a larger memory block while preserving data integrity.

**What I Tried:**

* Implemented the `append()` method to add elements to the end of the array.
* Added automatic capacity checking before insertion.
* Implemented the `resize()` function using a capacity doubling strategy.
* Copied existing elements into the new memory block during resizing.
* Implemented the `insert()` method by shifting elements to the right before placing the new value.
* Implemented the `remove()` method by shifting elements to the left after deletion.
* Added index validation to prevent out-of-range access during insertion and removal.
* Tested operations with integers, characters, floating-point values, and strings.
* Verified that resizing preserved all existing elements correctly.

**Outcome:**
Successfully implemented the primary DynamicArray modification operations:

* `append()`
* `insert()`
* `remove()`
* `resize()`

The DynamicArray now supports dynamic growth, insertion at arbitrary positions, element removal, and automatic capacity expansion. The resizing strategy doubles the capacity when the array becomes full, providing amortized O(1) append performance while maintaining contiguous memory storage.

---
