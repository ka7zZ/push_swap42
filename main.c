
#include <unistd.h>
#include <stdio.h>

static void	printing_bits(int a)
{
	int	bits;

	bits = 8;
	while (bits--)
	{
		if (a & (1 << bits))
			printf("1");
		else
			printf("0");
	}
}

int	main(void)
{
	int arr[5] = {1, 5, 2, 4, 3};
	int i;
	int bites;

	i = 5;
	bites = 8;
	while (i--)
	{
		printf("%d --> ", arr[i]);
		printing_bits(arr[i]);
		printf("\n");
	}
	while (i++ < 5)
	{
		printf("first bit of %d is -->> %d\n", arr[i], arr[i] & 1);
	}
	return (0);
}