# Hash Tables in C

## Description
Implementation of hash tables in C using chaining for collision handling.

## Data Structures
- `hash_node_t` - Node of a hash table (key, value, next)
- `hash_table_t` - Hash table (size, array of nodes)

## Files

| File | Description |
|------|-------------|
| `hash_tables.h` | Header file with structures and prototypes |
| `0-hash_table_create.c` | Creates a hash table |

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hash_tables
```

