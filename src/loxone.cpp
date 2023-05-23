#include "loxone.h"

/* task 1 */

int find_max_sum(int *numbers, int size)
{
	int max1 = numbers[0];
	int max2 = numbers[1];

	for (int i = 2; i < size; i++)
	{
		if (numbers[i] > max1 || numbers[i] > max2)
		{
			if (max1 > max2)
				max2 = numbers[i];
			else
				max1 = numbers[i];
		}
	}

	return max1 + max2;
}

/* task 2 */

void CropRatio::add(std::string name, int cropWeight)
{
	std::map<std::string, int>::iterator search = crops.find(name);

	if (search == crops.end())
	{
		crops[name] = cropWeight;
	}
	else
	{
		crops[name] += cropWeight;
	}

	totalWeight += cropWeight;
}

double CropRatio::proportion(std::string name)
{
	if (totalWeight == 0)
		return 0;

	return (double)crops.at(name) / (double)totalWeight;
}

/* task 3 */

int minimal_number_of_packages(int items, int available_large_packages, int available_small_packages)
{
	int intems_left = items;
	int packages_num = 0;

	packages_num = (items / 5 <= available_large_packages) ? items / 5 : available_large_packages;

	intems_left = items - packages_num * 5;

	if (intems_left > available_small_packages)
		return -1;

	packages_num += intems_left;

	return packages_num;
}

/* task 4 */

void charge(Battery* battery, float charge)
{
	battery->charge += charge;
}

/* task 5 */

int copy_bit(int src, int dst, int pos)
{
	int mask = 1 << pos;

	dst = dst ^ ((dst ^ src) & mask);

	return dst;
}

/* task 6 */

int count_letters(char **strings, int string_count, char target)
{
	char *ptr = NULL;
	int counter = 0;

	for (int i = 0; i < string_count; i++)
	{
		ptr = strings[i];

		for (int j = 0; j < strlen(ptr); j++)
		{
			if (ptr[j] == target)
				counter++;
		}
	}

	return counter;
}

/* task 7 */

Descriptor *allocate_and_initialize_descriptor(int id, const char *name)
{
	Descriptor *desc = (Descriptor*)malloc(sizeof(Descriptor));

	char copy_name[strlen(name)];

	strcpy(copy_name, name);

	desc->id = id;
	desc->name_length = strlen(name);
	desc->name = copy_name;

	return desc;
}

void deallocate_descriptor(Descriptor *descriptor)
{
	free(descriptor);
}
