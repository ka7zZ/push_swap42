#include <stdio.h>

static unsigned int	count_bits(unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (n)
	{
		count++;
		n >>= 1;
	}
	return (count);
}

static void	print_bits(int n)
{
	int	max;

	printf("\nnumber --->> \t\t\t\t%d\n", n);
	max = count_bits(n);
	printf("number of bites contained --->> \t%d\nbit -->> ", max);
	while (max--)
		printf("%d", (n >> max) & 1);
	printf("\n");
}

int	main(void)
{
	int	arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int	idx;

	idx = -1;
	while (++idx < 15)
		print_bits(arr[idx]);
	return (0);	
}