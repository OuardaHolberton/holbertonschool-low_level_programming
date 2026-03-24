# AI Memory Visualizer / Valgrind Tracer

## Description

This project explores how memory works in C using stack, heap,
aliasing, and Valgrind.

The goal is to understand:

- memory lifetime
- memory leaks
- segmentation faults
- aliasing
- use-after-free
- stack vs heap behavior

We also use Valgrind to detect memory errors.

---

## Project structure


ai_memory_visualizer_valgrind_tracer/

├── programs/
│ ├── stack_example.c
│ ├── heap_example.c
│ ├── aliasing_example.c
│ └── crash_example.c
│
├── analysis/
│ ├── memory_maps.md
│ └── valgrind_analysis.md
│
└── README.md


---

## Compilation

To compile all programs:


make


This will create:


stack_example
heap_example
aliasing_example
crash_example


---

## Run programs


./stack_example
./heap_example
./aliasing_example
./crash_example


---

## Run with Valgrind

Valgrind is used to detect memory problems.

Examples:


valgrind ./heap_example
valgrind ./aliasing_example
valgrind ./crash_example


Valgrind can detect:

- memory leaks
- invalid read
- invalid write
- use-after-free
- segmentation fault
- uninitialized memory

---

## Concepts learned

### Stack

- automatic memory
- created when function starts
- destroyed when function ends

### Heap

- allocated with malloc
- must be freed with free

### Aliasing

Multiple pointers to the same memory.

Can cause bugs if memory is freed too early.

### Dangling pointer

Pointer that still points to freed memory.

### Memory leak

Memory allocated but never freed.

### Segmentation fault

Invalid memory access.

Example:

- NULL pointer dereference
- use-after-free
- out of bounds

---

## Analysis files

Detailed explanations are in:


analysis/memory_maps.md
analysis/valgrind_analysis.md


These files explain:

- memory layout
- lifetime
- Valgrind errors
- cause of crashes
- AI mistakes

---

## Author

Ouarda