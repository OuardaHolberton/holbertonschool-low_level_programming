# Valgrind Analysis

## heap_example.c

### Command used


valgrind ./heap_example


### Program output


alice=0x4a8c480 name=0x4a8c4d0 age=30
bob=0x4a8c520 name=0x4a8c570 age=41


### Valgrind output


HEAP SUMMARY:
in use at exit: 6 bytes in 1 blocks
total heap usage: 5 allocs, 4 frees

LEAK SUMMARY:
definitely lost: 6 bytes in 1 blocks


---

## Type of error

Memory leak (`definitely lost`)

---

## Memory involved

The leaked memory corresponds to the `name` buffer allocated with `malloc`
inside the `Person` structure.

Each `Person` contains:

- struct allocated on heap
- name allocated separately on heap

---

## Cause of the error

Each person is allocated:


alice = malloc(sizeof(Person))
bob = malloc(sizeof(Person))


Each structure also allocates memory for the name:


p->name = malloc(...)


The function `person_free_partial` only frees the struct:


free(p);


but does NOT free:


p->name


After `free(p)`, the pointer to `name` is lost,
so the allocated memory cannot be freed anymore.

Valgrind reports this as:


definitely lost


---

## Lifetime violation

Heap memory must remain reachable until it is freed.

Here, the `name` buffer is allocated but the pointer is lost
when the struct is freed.

This breaks the ownership rule:

> Every malloc must have exactly one matching free.

---

## AI mistake example

The AI initially suggested that the leak happens
because one `Person` structure is not freed.

This is incorrect.

Both structures are freed, but the internal field
`p->name` is not freed.

The leak comes from the nested allocation,
not from the struct itself.

This mistake happened because the AI did not
track memory ownership inside the structure.