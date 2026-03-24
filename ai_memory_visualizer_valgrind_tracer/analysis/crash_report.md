# Crash Report: crash_example.c

## 1. Description of the Crash

Program: crash_example.c  
Symptom: Segmentation Fault (SIGSEGV)  
The program crashes immediately after printing "requesting n=0".  

Crash line:

nums[0] = 42;

The crash happens because the program tries to write
to an invalid memory address.


## 2. Memory involved

Stack:
- variable `nums` is stored on the stack

Heap:
- no heap allocation occurs when n <= 0

Function:

allocate_numbers(0)

returns NULL instead of allocating memory.

So `nums` contains NULL (address 0x0).


## 3. Root Cause Analysis

The crash is a deterministic NULL pointer dereference.

Execution chain:

1. main sets n = 0
2. allocate_numbers(0) is called
3. allocate_numbers returns NULL
4. nums = NULL
5. program executes nums[0] = 42
6. write to address 0x0
7. CPU detects invalid access
8. OS sends SIGSEGV


## 4. Why the memory access is invalid

Address 0x0 is not part of the stack or heap.

Modern operating systems leave the first page of memory unmapped.

This prevents programs from accessing NULL.

When the CPU tries to write to this address,
the Memory Management Unit detects an invalid access.

The kernel stops the program and sends SIGSEGV.


## 5. Undefined behavior category

This crash is caused by:

NULL pointer dereference

The program uses a pointer that does not refer
to valid allocated memory.

This is undefined behavior.


## 6. AI Explanation Critique

AI hypothesis:

"The crash is caused by a buffer overflow because the array size is 0."

This explanation is incorrect.

A buffer overflow requires a valid allocated buffer.

In this program malloc is never called,
because allocate_numbers returns NULL.

No array exists in memory.

The real error is a NULL pointer dereference,
not an out-of-bounds access.


## 7. Suggested Fix (optional)

The program must check the pointer before using it.

Example:
