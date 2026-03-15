#ifndef DOG_H
#define DOG_H

/**
 * struct dog - structure d un chien
 * @name: le nom du chien
 * @age: l age du chien
 * @owner: le proprietaire du chien
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
