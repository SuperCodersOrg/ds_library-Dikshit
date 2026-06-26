# Build Log

## Entry 1

**Date:** June 26, 2026

**Duration:** 40 Minutes

**Goal:**
Implement and verify the Rule of Three for the LinkedList class.

**Problem Encountered:**
Ensure copied lists own independent memory while handling self-assignment safely.

**What I Tried:**

Implemented the default constructor, destructor, copy constructor, and copy assignment operator.
Created a test program to verify object creation, copying, assignment, and automatic destruction.

**Outcome:**
Successfully implemented the Rule of Three. All tests passed, and copied lists maintain independent ownership without memory leaks or double deletion

---

## Entry 2

**Date:** June 26, 2026

**Duration:** 30 Minutes

**Goal:**
Implement and verify insertion operations for the doubly linked list.

**Problem Encountered:**
Handle insertions correctly for the front, back, middle, and empty list while maintaining both head_ and tail_ pointers.

**What I Tried:**
Implemented insertFront(), insertBack(), and insert(index, value). Reused insertion methods for boundary cases and optimized middle insertion by traversing from the head or tail depending on the index.

**Outcome:**
Successfully implemented all insertion methods. Verified correct pointer updates, list size maintenance, and exception handling for invalid indices through testing.

---
## Entry 3

**Date:** June 26, 2026

**Duration:** 45 Minutes

**Goal:**
Implement and test deletion operations for the doubly linked list.

**Problem Encountered:**
Correctly update head_, tail_, and neighboring node pointers while handling deletion from the front, back, middle, and single-node lists.

**What I Tried:**
Implemented deleteFront(), deleteBack(), and remove(index). Reused front and back deletion methods for boundary cases and optimized middle deletion by traversing from the nearest end of the list.

**Outcome:**
Successfully implemented all deletion methods. Verified pointer updates, memory deallocation, size maintenance, and exception handling for invalid indices through testing.