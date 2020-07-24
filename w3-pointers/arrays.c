#include <stdio.h>
int main()
{
	int i; // general purpose counter

	// create array and initalise it
	// alternative: int a[10] = {10,14,0,8,22,6,201,1,-7,42};
	int a[10]  = {10,14,0,8,22,6,201,1,-7,42};

	// Print array using array notation
	for(i = 0; i < 10; i++)
	{
		printf("a[%d] = %d \n",i,a[i]);
	}

	printf("--------------------------\n");

	// Print array using pointer notation
	for(i = 0; i < 10 ; i++)
	{
		printf("*(a+%d) = %d\n",i,*(a+i));
	}
	return 0;
}