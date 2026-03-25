# Memory Analysis Report

**Project:** AI Memory Visualizer  

---

## Table of Contents

| Section | Description |
|---------|-------------|
| [stack_example.c](#stack_examplec) | Stack frames and recursion |
| [aliasing_example.c](#aliasing_examplec) | Pointer aliasing and use-after-free |
| [heap_example.c](#heap_examplec) | Heap allocation and memory leak |
| [crash_example.c](#crash_examplec) | NULL dereference and segfault |

---

## stack_example.c

This program demonstrates how stack frames behave during recursion.

The function `walk_stack` calls itself recursively until `depth = 3`.
At each level, it calls `dump_frame` twice (on entry and on exit).

### Memory type

| Type   | Used | Reason        |
|--------|------|---------------|
| Stack  | yes  | local variables |
| Heap   | no   | no malloc     |
| Global | no   | none          |

All variables are stored on the stack.
No heap allocation occurs because `malloc` is never called.

### Stack frame contents

Each call to `walk_stack` creates a frame containing:

| Variable    | Type  | Value          |
|-------------|-------|----------------|
| `depth`     | int   | current depth  |
| `max_depth` | int   | 3              |
| `marker`    | int   | depth * 10     |

Each call to `dump_frame` creates a frame containing:

| Variable     | Type      | Value           |
|--------------|-----------|-----------------|
| `local_int`  | int       | 100 + depth     |
| `local_buf`  | char[16]  | "A" + depth     |
| `p_local`    | int *     | address of local_int |

### Stack diagram at maximum depth

```
HIGH ADDR
┌──────────────────────┐
│       main()         │
├──────────────────────┤
│  walk_stack(0, 3)    │  marker = 0
├──────────────────────┤
│  walk_stack(1, 3)    │  marker = 10
├──────────────────────┤
│  walk_stack(2, 3)    │  marker = 20
├──────────────────────┤
│  walk_stack(3, 3)    │  marker = 30
├──────────────────────┤
│  dump_frame("enter", 3)  │  local_int = 103, local_buf = "D"
└──────────────────────┘
LOW ADDR
```

### Lifetime

Frames are created during recursion and destroyed in reverse order:

```
enter depth 0
  enter depth 1
    enter depth 2
      enter depth 3
      exit depth 3
    exit depth 2
  exit depth 1
exit depth 0
```

Each frame exists only until its function returns.
When `walk_stack(3)` returns, its frame is destroyed first.

### Address behavior

On x86/x86_64, the stack grows toward lower addresses.

```
walk_stack(0) : &marker = 0x7ffe...f0   (highest)
walk_stack(1) : &marker = 0x7ffe...c0
walk_stack(2) : &marker = 0x7ffe...90
walk_stack(3) : &marker = 0x7ffe...60   (lowest)
```

### p_local aliasing

```c
int *p_local = &local_int;
```

`p_local` and `&local_int` print the same address.
They are aliases: two names for the same memory location.

### AI mistake

**AI claimed:** `local_int` might be stored in heap memory.

**Why this is wrong:**  
`local_int` is declared as a local variable inside `dump_frame`.  
Local variables are always stored on the stack.  
Heap memory is only used when `malloc` is explicitly called,  
which never happens in this program.

---

## aliasing_example.c

This program demonstrates pointer aliasing and use-after-free.

### Allocation

```c
a = make_numbers(5);
b = a;
```

`make_numbers` allocates an array of 5 integers and fills them with `i * 11`.

### Memory map after allocation

```
STACK
┌─────────────┐
│  a = 0x1000 │──┐
│  b = 0x1000 │──┤
│  n = 5      │  │
└─────────────┘  │
                 ▼
HEAP
┌────────────────────────────────┐
│ 0x1000: [0][11][22][33][44]    │
└────────────────────────────────┘
```

Both `a` and `b` point to the same heap block.
This is called **pointer aliasing**.

### Ownership

Only one pointer owns the memory.
Only one `free` should be called.

```c
free(a);
```

### Memory map after free

```
STACK
┌─────────────┐
│  a = 0x1000 │──┐
│  b = 0x1000 │──┤
└─────────────┘  │
                 ▼
HEAP
┌────────────────────────────────┐
│ 0x1000: freed (invalid)        │
└────────────────────────────────┘
```

`b` still contains the old address.
`b` is now a **dangling pointer**.

### Use-after-free

```c
printf("  reading b[2]=%d\n", b[2]);
b[3] = 1234;
```

This is use-after-free. Behavior is undefined.

| Result          | Possible |
|-----------------|----------|
| works normally  | yes      |
| crash           | yes      |
| memory corruption | yes    |
| Valgrind error  | yes      |

### AI mistake

**AI claimed:** `b` becomes NULL after `free(a)`.

**Why this is wrong:**  
`free()` releases the heap memory block but does not modify any pointer.  
After `free(a)`, both `a` and `b` still hold the value `0x1000`.  
`b` is not NULL — it is a dangling pointer pointing to freed memory.  
Accessing it is undefined behavior.

---

## heap_example.c

This program demonstrates heap allocation and a deliberate memory leak.

### Allocation

```c
alice = person_new("Alice", 30);
bob   = person_new("Bob",   41);
```

`person_new` performs two allocations per person:
1. `malloc(sizeof(Person))` for the struct
2. `malloc(len + 1)` for the name string

### Memory map after allocation

```
STACK
┌──────────────┐
│ alice = 0x2000 │
│ bob   = 0x3000 │
└──────────────┘

HEAP
┌───────────────────────────┐
│ 0x2000 → Person (alice)   │
│   age  = 30               │
│   name → 0x2100           │
├───────────────────────────┤
│ 0x2100 → "Alice\0"        │
├───────────────────────────┤
│ 0x3000 → Person (bob)     │
│   age  = 41               │
│   name → 0x3100           │
├───────────────────────────┤
│ 0x3100 → "Bob\0"          │
└───────────────────────────┘
```

### Correct free order

| Step | Code              |
|------|-------------------|
| 1    | `free(bob->name)` |
| 2    | `free(bob)`       |
| 3    | `free(alice->name)` |
| 4    | `free(alice)`     |

### Memory leak

The program calls `person_free_partial(alice)`:

```c
static void person_free_partial(Person *p)
{
    if (!p)
        return;
    free(p);   /* frees the struct only */
               /* p->name is NEVER freed */
}
```

`alice->name` is never freed.

### Leak diagram

```
HEAP after program ends

Person alice  → freed     ✅
alice->name   → NOT freed ❌  (memory leak)

Person bob    → freed     ✅
bob->name     → freed     ✅
```

Valgrind will report:

```
definitely lost: N bytes in 1 block
```

### AI mistake

**AI claimed:** the struct `alice` is not freed.

**Why this is wrong:**  
`person_free_partial` does call `free(p)`, so the struct itself is freed.  
The leak is specifically `alice->name`, the internal name buffer,  
which is never passed to `free()`.  
The struct and the name are two separate heap allocations.

---

## crash_example.c

This program demonstrates a deterministic NULL pointer dereference.

### Execution

```c
int n = 0;
nums = allocate_numbers(n);
nums[0] = 42;
```

`allocate_numbers(0)` returns NULL because `n <= 0`.

### Memory map at crash

```
STACK
┌──────────────┐
│ nums = NULL  │
│ n    = 0     │
└──────────────┘

HEAP
(nothing allocated)
```

### Crash chain

| Step | Action                          |
|------|---------------------------------|
| 1    | `main` calls `allocate_numbers(0)` |
| 2    | `n <= 0` → returns NULL         |
| 3    | `nums = NULL`                   |
| 4    | `nums[0] = 42` → write to address 0x0 |
| 5    | OS rejects access → SIGSEGV     |
| 6    | Program crashes                 |

### Why it crashes

`nums[0]` is equivalent to `*(nums + 0)` = `*(NULL)` = writing to address `0x0`.

Address `0x0` is not mapped in the process address space.
The OS sends SIGSEGV and the program terminates immediately.

### AI mistake

**AI claimed:** this is an out-of-bounds access.

**Why this is wrong:**  
Out-of-bounds means accessing memory past the end of a valid array.  
Here, no array was ever allocated.  
`nums` is NULL, so this is a NULL pointer dereference, not out-of-bounds.  
These are two different types of memory errors with different causes.
