# Singly Linked Lists

## Description
This project implements singly linked lists in C.
A linked list is a data structure where each node contains a value
and a pointer to the next node.

## Data Structure
```c
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;
```

## Files
| File | Description |
|------|-------------|
| lists.h | Header file with prototypes |
| 0-print_list.c | Prints all elements of a list |

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89
```
