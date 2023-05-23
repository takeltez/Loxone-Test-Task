#include "loxone.h"

int main()
{
	/* task 1 */

	printf("Task 1\n");

	int v[] = { 5, 9, 7, 11 };

	printf ("Array: ");

	for (int i = 0; i < sizeof(v) / sizeof(int); i++)
	{
		printf("%d ", *(v + i));
	}

	printf("\nMaximal sum of two elements: %d\n", find_max_sum(v, 4));

	/* task 2 */

	printf("\nTask 2\n");

	CropRatio cropRatio;

	cropRatio.add("Wheat", 4);
	cropRatio.add("Wheat", 5);
	cropRatio.add("Rice", 1);

	std::cout << "Amount of wheat: 9\nOverall amount of crop: 10" << std::endl;
	std::cout << "Proportion of wheat: " << cropRatio.proportion("Wheat") << '\n';

	/* task 3 */

	printf("\nTask 3\n");

	printf("Number of items: %d\nNumbers of large packages:%d\nNumber of small packages: %d\n", 16, 2, 10);
	printf("Minimal number of packages: %d\n", minimal_number_of_packages(16, 2, 10));

	/* task 4 */

	printf("\nTask 4\n");

	Battery battery = {0};

	printf("Charge battery at 1.0 volt\n");

	charge(&battery, 1.0f);

	printf("Battery charge: %f volt\n", battery.charge);

	/* task 5 */

	printf("\nTask 5\n");

	printf("Source number: %d\nDestenation number: %d\nPosition of swaped bit: %d\n", 15, 9, 3);
	printf("Destenation number with swaped bit: %d\n", copy_bit(7, 12, 3));

	/* task 6*/

	printf("\nTask 6\n");

	char *string_arr[] = {"Hello", "Jacqueline!"};

	int res = count_letters(string_arr, 2, 'e');

	printf("Strings: %s, %s\nTarget letter: %c\n", *string_arr, *(string_arr + 1), 'e');
	printf("Number of letter: %d\n", res);

	/* task 7 */

	printf("\nTask 7\n");

	printf("Fill descriptor with id: 2 and name: File\n");

	Descriptor *descriptor = allocate_and_initialize_descriptor(2, "File");

	printf("Descriptor fields: Id: %d, name length: %d, name: %s\n", descriptor->id, descriptor->name_length, descriptor->name);

	deallocate_descriptor(descriptor);
}

