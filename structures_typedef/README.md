# Structures and Typedef

## Description
Ce projet porte sur l'utilisation des structures et typedef en C.

## Learning Objectives
- Comprendre ce qu'est une structure et comment l'utiliser
- Savoir utiliser typedef

## Requirements
- Compilé avec : `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Betty style obligatoire
- Pas de variables globales
- Maximum 5 fonctions par fichier

## Exercices

![Poppy](./poppy.jpg)

### 0. Poppy
Définition de la structure `struct dog` avec `name`, `age` et `owner`

### 1. A dog is the only thing on earth...
Fonction `init_dog` qui initialise une variable de type `struct dog`
![Poppy2](./poppy2.jpg)


### 2. A dog will teach you unconditional love
Fonction `print_dog` qui affiche les infos d'une variable de type `struct dog`
![Poppy3](./poppy3.jpg)

### 3. Outside of a dog, a book is a man's best friend
Définition de `dog_t` comme nouveau nom pour `struct dog` avec `typedef`
![Poppy4](./poppy4.jpg)

### 4. A door is what a dog is perpetually on the wrong side of
Fonction `new_dog` qui crée un nouveau chien avec allocation mémoire
![Poppy5](./poppy5.jpg)

### 5. How many legs does a dog have if you call his tail a leg?
Fonction `free_dog` qui libère la mémoire d'un chien

![Poppy6](./poppy6.jpg)


