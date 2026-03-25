# 🔍 Valgrind Analysis Report

> **Tool:** Valgrind 3.x — Memcheck  
> **Compiled with:** `-Wall -Wextra -Werror -pedantic -std=gnu89 -g`

---

## 📋 Table of Contents

| # | Program | Error Type | Valgrind Status |
|---|---------|------------|-----------------|
| 1 | [heap_example.c](#heap_examplec) | Memory leak | ❌ `definitely lost` |
| 2 | [aliasing_example.c](#aliasing_examplec) | Use-after-free | ❌ `invalid read/write` |
| 3 | [stack_example.c](#stack_examplec) | None | ✅ `0 errors` |
| 4 | [crash_example.c](#crash_examplec) | NULL dereference | 💥 `SIGSEGV` |

---

## heap_example.c

### Command used

```
valgrind ./heap_example
```

### Program output

```
alice=0x4a8c480 name=0x4a8c4d0 age=30 bob=0x4a8c520 name=0x4a8c570 age=41
```

### Valgrind output

```
HEAP SUMMARY: in use at exit: 6 bytes in 1 blocks
              total heap usage: 5 allocs, 4 frees

LEAK SUMMARY: definitely lost: 6 bytes in 1 blocks
```

### Type of error

Memory leak (definitely lost)

### Memory involved

The leaked memory corresponds to the name buffer allocated with `malloc` inside the Person structure.

Each Person contains:

- struct allocated on heap
- name allocated separately on heap

### Cause of the error

Each person is allocated:

```c
alice = malloc(sizeof(Person));
bob   = malloc(sizeof(Person));
```

Each structure also allocates memory for the name:

```c
p->name = malloc(...);
```

The function `person_free_partial` only frees the struct:

```c
free(p);
```

but does NOT free:

```c
p->name
```

After `free(p)`, the pointer to name is lost, so the allocated memory cannot be freed anymore.

Valgrind reports this as:

```
definitely lost
```

### Lifetime violation

Heap memory must remain reachable until it is freed.

Here, the name buffer is allocated but the pointer is lost when the struct is freed.

This breaks the ownership rule:

> Every malloc must have exactly one matching free.

### AI mistake example

**AI claimed:** the leak happens because one Person structure is not freed.

**Why this is wrong:**  
Both structures are freed, but the internal field `p->name` is not freed.  
The leak comes from the nested allocation, not from the struct itself.  
This mistake happened because the AI did not track memory ownership inside the structure.

---

## aliasing_example.c

### Command used

```
valgrind ./aliasing_example
```

### Program output

```
Program prints values, then continues after free.
```

### Valgrind output

```
Invalid read of size 4
Invalid write of size 4

ERROR SUMMARY: 2 errors
```

### Type of error

Use-after-free (dangling pointer)

### Memory involved

Memory is allocated on the heap.

Two pointers refer to the same block:

```
a -> heap
b -> same heap
```

This is aliasing.

After this:

```c
free(a);
```

the memory is released, but pointer `b` still points to the same address.

`b` becomes a dangling pointer.

### Cause of the error

```c
free(a);
b[2];        /* read after free  */
b[3] = 1234; /* write after free */
```

The lifetime of the memory ended at `free(a)`, but `b` still uses the address.

### Lifetime violation

Heap memory must not be used after free.

Here the lifetime ended at `free(a)`, but `b` still uses the address.

This is a use-after-free error.

### AI mistake example

**AI claimed:** aliasing is safe because the memory is freed once.

**Why this is wrong:**  
Aliasing becomes dangerous when one pointer frees the memory while another pointer still uses it.  
The error is not double free, but use-after-free.

---

## stack_example.c

### Command used

```
valgrind ./stack_example
```

### Program output

```
Program runs normally.
```

### Valgrind output

```
HEAP SUMMARY: in use at exit: 0 bytes in 0 blocks

All heap blocks were freed -- no leaks are possible

ERROR SUMMARY: 0 errors
```

### Type of behavior

No error

### Memory involved

This program only uses stack memory.

Variables are local to the function and automatically destroyed when the function returns.

No `malloc` is used.

### Lifetime

Stack memory lifetime is automatic.

Each function call creates a stack frame.  
When the function returns, its stack frame is destroyed.  
All local variables disappear automatically.

Valgrind does not report errors here because no heap memory is used.

### AI mistake example

**AI claimed:** the program might leak memory.

**Why this is wrong:**  
No heap allocation occurs, so no memory leak is possible.  
The AI confused stack allocation with heap allocation.

---

## crash_example.c

### Command used

```
valgrind ./crash_example
```

### Program output

```
Segmentation fault
```

### Valgrind output

```
Invalid write of size 4
Address 0x0 is not stack'd, malloc'd or free'd

ERROR SUMMARY: 1 errors
```

### Type of error

Segmentation fault (NULL pointer dereference)

### Memory involved

The pointer returned by `allocate_numbers` is NULL when `n <= 0`.

The program then writes:

```c
nums[0] = 42;
```

This tries to write at address `0x0`.

### Cause of the error

| Step | Action |
|------|--------|
| 1 | `allocate_numbers(0)` returns NULL |
| 2 | `nums` becomes NULL |
| 3 | `nums[0]` tries to access memory |
| 4 | Invalid write occurs |
| 5 | Program crashes |

### Lifetime violation

Memory must be allocated before being used.

Here no memory exists, but the program tries to write to it.

### AI mistake example

**AI claimed:** this is an out-of-bounds error.

**Why this is wrong:**  
Out-of-bounds requires a valid array.  
Here the pointer is NULL, so the array does not exist.  
The real error is NULL pointer dereference.
