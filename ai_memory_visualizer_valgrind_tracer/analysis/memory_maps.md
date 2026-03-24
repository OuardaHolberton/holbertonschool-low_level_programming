### Memory type

All variables are stored in the stack.

No heap allocation occurs because `malloc` is never used.


### Lifetime

Each stack frame exists until the function returns.

When recursion finishes, frames are removed in reverse order:

enter depth 0  
enter depth 1  
enter depth 2  
enter depth 3  

exit depth 3  
exit depth 2  
exit depth 1  
exit depth 0  


### AI mistake example

AI initially suggested that `local_int` could be stored in heap memory.

This is incorrect.

`local_int` is a local variable declared inside a function,
so it is stored in the stack frame.

Heap memory is only used when `malloc` is called,
which does not happen in this program.

This mistake happened because the AI confused
local variables with dynamically allocated memory.



--------------------------------------------------
## aliasing_example.c
--------------------------------------------------

This program demonstrates pointer aliasing and use-after-free.

Memory is allocated on the heap using malloc.


### Allocation

int *a  
int *b  

a = malloc(5 * sizeof(int))  
b = a  


Memory map after allocation:

```
Stack

a -> 0x1000
b -> 0x1000

Heap

0x1000 -> [0][11][22][33][44]
```

Both pointers refer to the same heap block.

This is called pointer aliasing.


### Ownership

Only one free should be done for the allocated memory.

free(a)


Memory map after free:

```
Stack

a -> 0x1000
b -> 0x1000

Heap

0x1000 -> freed memory (invalid)
```

Pointer `b` still contains the old address.

This pointer is now a dangling pointer.


### Use-after-free

The program still accesses memory using `b`.

b[2]  
b[3] = 1234  

This is use-after-free.

Behavior is undefined.

Possible results:

- program works
- program crashes
- memory corruption
- Valgrind error


### Lifetime

Heap memory exists from `malloc` until `free`.

After free, memory must not be accessed.


### AI mistake example

AI initially suggested that pointer `b` becomes NULL after `free(a)`.

This is incorrect.

`free()` only releases the heap memory.

It does NOT change other pointers.

`b` still contains the old address,
so it becomes a dangling pointer.



--------------------------------------------------
## heap_example.c
--------------------------------------------------

This program demonstrates heap allocation and a memory leak.

The program allocates memory using malloc
to create structures on the heap.


### Allocation

alice = malloc(sizeof(Person))  
bob = malloc(sizeof(Person))  


Each structure contains:

- name (allocated with malloc)
- age (stored in struct)


Memory map:

```
Stack

alice -> 0x2000
bob -> 0x3000

Heap

0x2000 -> Person (alice)
0x2100 -> name buffer (alice)

0x3000 -> Person (bob)
0x3100 -> name buffer (bob)
```


### Ownership

Each malloc must be paired with free.

Correct free order:

free(alice->name)  
free(alice)  

free(bob->name)  
free(bob)  


### Memory leak

In this program, the function `person_free_partial`
does not free all allocated memory.

```
static void person_free_partial(Person *p)
{
    free(p);
}
```

The struct is freed, but `p->name` is not freed.

Memory map:

```
Heap

Person (alice) -> freed
name (alice) -> NOT freed  ← memory leak
```

This causes a memory leak because the name buffer
allocated with malloc is never released.


### Lifetime

Heap memory exists from malloc until free.

If free is not called,
memory remains allocated until program ends.

Valgrind will report this as:

- definitely lost
- still reachable


### AI mistake example

AI initially suggested that the memory leak happens
because one structure is not freed.

This is not fully correct.

The real problem is that `person_free_partial`
frees the struct but does not free `p->name`.

The leak comes from the name buffer,
not from the struct itself.

This mistake happened because the AI did not check
what the free function actually releases.

### Additional AI analysis critique

The AI analysis of the stack behavior was globally correct,
but some explanations were simplified or incomplete.

1. Stack frame destruction

The AI stated that the stack frame is destroyed when the function returns.

This is not strictly accurate.

In reality, the memory is not erased.
The CPU only moves the Stack Pointer (SP) to the previous position.

The data of the previous frame may still remain in memory
until it is overwritten by another function call.

This explains why accessing a pointer to a local variable
after the function returns leads to undefined behavior.


2. Missing arguments in the stack frame

The AI description only mentioned local variables,
but function parameters are also stored in the stack frame.

For example, in walk_stack we have:

- depth
- max_depth
- marker

Each recursive call creates a new frame containing
both parameters and local variables.

This explains why recursion increases stack usage quickly.


3. Frame reuse and addresses

The AI suggested that the same addresses are reused
because the same function is called again.

This is not always guaranteed.

When a function returns, its frame is removed,
and a new frame may be allocated at the same location,
but this depends on the compiler and optimization level.

A correct interpretation is:

The frame is freed,
then a new frame is allocated at the same stack level.


Conclusion

The AI provided a good visualization of the stack,
but its explanation simplified how memory is actually managed
by the CPU and the compiler.

Understanding these details is important to correctly
analyze stack lifetime and undefined behavior.
