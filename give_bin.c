#include <stdio.h>
#include <unistd.h>


/* functions of the sort 2.0


static void	list_details(t_list *stack)
{
	t_list	*ptr;
	int		index;
	int		number;

	ptr = stack;
	while (ptr)
	{
		index = ((t_body *)ptr->content)->i;
		number = ((t_body *)ptr->content)->n;
		ft_printf("number %d\tindex\t%d\n", number, index);
		ptr = ptr->next;		
	}
	
}


static int reset_index(t_list **stack)
{
	t_list	*ptr;
	int		*index;

	ptr = *stack;
	if (!ptr)
		return (0);
	while (ptr)
	{
		index = &(((t_body *)ptr->content)->i);
		if (index)
			*index = 0;
		ptr = ptr->next;
	}
	return (1);
}

static void reload_stack(t_list **a, t_list **b, int shift_right, int pushed)
{
	int	index_fin;
	int buf;

	buf = pushed;
	index_fin = 1;
	ft_printf("stack_b in reload stack: \n");
	list_details(*b);
	while (!check_next(*b, shift_right + 1, buf) && buf)
	{
		index_fin = ((t_body *)(*b)->content)->i;
		if (!index_fin)
			break ;
		push(a, b, 'a');
		buf--;	
	}
	if (check_next(*b, shift_right + 1, buf))
		push_aux(a, b, shift_right + 1,  ft_lstsize(*b));	
}

static void	custom_radix(t_list **stack_a, t_list **stack_b, int length)
{
	int		shift_right;
	int		pushed;
	int		buf;

	shift_right = -1;
	pushed = 0;
	while (++shift_right > (int)count_bits(get_max(*stack_a)))
	{
		buf = length;
		while (buf-- && !check_sorted(*stack_a))
		{
			if (!((((t_body *)(*stack_a)->content)->i >> shift_right) & 1))
			{
				pushed++;
				push(stack_a, stack_b, 'b');
			}
			else
				rotate(stack_a, stack_b, 'a');	
		}
		buf = length - pushed;
		while (buf--)
			rev_rotate(stack_a, stack_b, 'a');
		reload_stack(stack_a, stack_b, shift_right, pushed);
	}
}

static void	bigger_group(t_list **stack_a, t_list **stack_b)
{
	int shift_right;
	int	size;
	int	actual_index;
	int pushed;

	shift_right = -1;
	size = ft_lstsize(*stack_a);
	pushed = 0;
	reset_index(stack_b);
	while (++shift_right < (int)count_bits(get_max(*stack_a)))
	{
		size = ft_lstsize(*stack_a);
		ft_printf("size of A -->> %d\n", size);
		while (size-- && !check_sorted(*stack_a))
		{
			actual_index = ((t_body *)(*stack_a)->content)->i;
			if (((actual_index >> shift_right) & 1) == 0)
			{
				pushed++;
				push(stack_a, stack_b, 'b');
			}
			else
				rotate(stack_a, stack_b, 'a');
		}
		reload_stack(stack_a, stack_b, shift_right, pushed);
	}
}

- go in stack a
- send all the first bit == 0 to b
- sort remaining (bigger group of A)
- after sorting bigger group, send next final bit == 0 from b to A
- sort the numbers in stack_a
- so on...

*/

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


int	main(void)
{
	int	bits;
	int	orig_nbits;
	int	number;
	int	zero;
	int	buf;
	int	iterator;

	number = 101;
	orig_nbits = count_bits(number);
	iterator = 0;
	zero = 0;
	while (++iterator < number)
	{
		bits = count_bits(iterator);
		buf = bits;
		printf("%d\t", iterator);
		while (buf++ < orig_nbits)
			printf("0");
		while (bits--)
			printf("%d", (iterator >> bits) & 1);
		printf("\n");
	}
	return (0);
}