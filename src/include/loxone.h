#ifndef LOXONE_H
#define LOXONE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <map>

typedef struct Battery
{
	float charge;
}Battery;

typedef struct Descriptor
{
	int id;
	int name_length;
	char *name;
}descriptor;

class CropRatio
{
public:
	void add(std::string name, int cropWeight);
	double proportion(std::string name);

private:
	int totalWeight = 0;
	std::map<std::string, int> crops;
};

int copy_bit(int src, int dst, int pos);
int find_max_sum(int *numbers, int size);
int count_letters(char **strings, int string_count, char target);
int minimal_number_of_packages(int items, int available_large_packages, int available_small_packages);

void charge(Battery* battery, float charge);
void deallocate_descriptor(Descriptor *descriptor);

Descriptor *allocate_and_initialize_descriptor(int id, const char *name);

#endif
