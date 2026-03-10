# Malloc and Free

This project covers dynamic memory allocation in C using `malloc` and `free`.

## Functions

### 0-create_array.c
Creates an array of chars and initializes it with a specific character.
- Returns NULL if size is 0
- Returns NULL if malloc fails
- Returns a pointer to the array on success

### 1-strdup.c
Duplicates a string using malloc.
- Returns NULL if str is NULL
- Returns NULL if malloc fails
- Returns a pointer to the duplicated string on success

### 2-str_concat.c
Concatenates two strings using malloc.
- Treats NULL as an empty string
- Returns NULL on failure

### 3-alloc_grid.c
Returns a pointer to a 2D array of integers initialized to 0.
- Returns NULL if width or height is 0 or negative
- Returns NULL if malloc fails

### 4-free_grid.c
Frees a 2D grid previously created by alloc_grid.
- Frees each row then the grid pointer

## Requirements
- Compiled with gcc -Wall -Werror -Wextra -pedantic -std=gnu89
- Betty style
- No global variables
- Only malloc and free allowed from standard library
