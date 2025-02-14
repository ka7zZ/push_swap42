#include "push_swap.h"

/*	INTENT WITH LIBFT LISTS FUNCTIONS


static void	see_stacks(t_list *a, t_list *b)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = a;
	stack_b = b;

	while (stack_a || stack_b)
	{
		if (stack_a && stack_a->content)
		{
			ft_printf("%s\t", stack_a->content);
			stack_a = stack_a->next;
		}
		else
			ft_putstr_fd(" \t", 1);
		if (stack_b && stack_b->content)
		{
			ft_printf("%s\n", stack_b->content);
			stack_b = stack_b->next;
		}
		else
			ft_putstr_fd(" \n", 1);
	}
	ft_printf("_\t_\n");
	ft_printf("\na\tb\n");
}

static void	free_stack(t_list *stack)
{
	t_list	*ptr_a;

	while (stack)
	{
		ptr_a = stack->next;
		free(stack->content);
		free(stack);
		stack = ptr_a;
	}
	free(stack);
}

static void		sort_b(t_list **stack_b)
{
	t_list	*head;
	int		a;
	int		b;
	int		c;

	if (!ft_lstsize(*stack_b) || ft_lstsize(*stack_b) == 1)
		return ;
	head = *stack_b;
	a = ft_atoi((char *)head->content);
	b = ft_atoi((char *)head->next->content);
	c = ft_atoi((char *)ft_lstlast(head)->content);
	if (a < b)
		sb(stack_b);
	if ()
}

static int	digits(t_list **stack_a)
{
	t_list 		*ptr;
	int		digits;
	int		check_digits;

	ptr = *stack_a;
	digits = 0;
	check_digits = 0;
	while (ptr)
	{
		digits = ft_strlen(ptr->content);
		if (ft_strchr(ptr->content, '-'))
			digits--;
		if (digits > check_digits)
			check_digits = digits;
		ptr = ptr->next;
	}
	return (check_digits);
}

static void	optimize_search(t_list **stack_a, t_list **stack_b, int digits, int *moves)
{
	t_list	*ptr;
	int		idx;
	int		size;
	int		len;

	ptr = *stack_a;
	size = ft_lstsize(ptr);
	idx = 0;
	while (ptr)
	{
		len = ft_strlen((char *)ptr->content);
		if (ft_atoi((char *)ptr->content) > 0 && len == digits)
			break;
		idx++;
		ptr = ptr->next;
	}
	if (idx <= size / 2)
	{
		*moves = idx;
		while (idx--)
			rotate(stack_a, stack_b, 'a');
		return ;
	}
	*moves = size - idx;
	while (idx++ < size)
		rev_rotate(stack_a, stack_b, 'a');
}

static int	push_elemets(t_list **stack_a, t_list **stack_b, int check_digits)
{
	t_list	*ptr;
	t_list	*head;
	int		size;
	int		i;

	ptr = *stack_a;
	i = 0;
	while (ptr)
	{
		i++;
		size = ft_strlen((char *)ptr->content);
		if (ft_strchr((char *)ptr->content, '-'))
			size--;
		if (size == check_digits)
			break;
		ptr = ptr->next;
	}
	while (--i)
		rra(stack_a);
	head = *stack_a;
	size = ft_strlen((char *)head->content);
	if (size == check_digits)
		return (pb(stack_a, stack_b), 1);
	return (0);
}


//TESTING INSTRUCTIONS
	
	// ft_putstr_fd("\n\n\nDone.\nNow the tests of instructions:\n\n", 1);
	

	// // Swap first 2 in A 
	// ft_putstr_fd("sa:\n", 1);
	// sa(&stack_a);
	// see_stack(stack_a);
	
	// // Push to B
	// ft_putstr_fd("----------\npb pb pb:\n", 1);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// see_stacks(stack_a, stack_b);

	// // Shift elements from stacks one position up (the first become the last)
	// ft_putstr_fd("----------\nra / rb:\n", 1);
	// rr(&stack_a, &stack_b);
	// see_stacks(stack_a, stack_b);

	// // Shift elements from stacks one position down (the last become the first)
	// ft_putstr_fd("----------\nrra / rrb:\n", 1);
	// rrr(&stack_a, &stack_b);
	// see_stacks(stack_a, stack_b);

	// //
	// ft_putstr_fd("----------\nsa:\n", 1);
	// sa(&stack_a);
	// see_stacks(stack_a, stack_b);

	// //
	// ft_putstr_fd("----------\npa pa pa:\n", 1);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// see_stacks(stack_a, stack_b);

*/

static void	set_index(t_list *stack_a, int length)
{
	t_list	*ptr;
	t_list	*compare;
	t_list	*max;
	t_body	*b_ptr;
	t_body	*b_compare;
	t_body	*b_max;
	int		i;

	i = 0;
	while (length--)
	{
		
		++i;
		ptr = stack_a;
		b_ptr = ptr->content;
		while (b_ptr->idx)
		{
			ptr = ptr->next;
			b_ptr = ptr->content;
		}
		if (!ptr)
			break;
		max = ptr;
		while (ptr)
		{
			compare = ptr->next;
			if (compare)
			{
				b_compare = compare->content;
				if (b_compare->idx == 0 && b_ptr->idx == 0)
				{
					b_max = max->content;
					if (b_ptr->number > b_compare->number && b_max->number > b_compare->number)
						max = compare;
				}
			}
			ptr = ptr->next;	
		}
		if (!b_max->idx)
			b_max->idx = i;	
	}
}

static void	see_stack(t_list *stack)
{
	t_list	*ptr;
	t_body	*b;
	
	ptr = stack;
	ft_putstr_fd("Stack_a:\n", 1);
	while (ptr)
	{
		b = ptr->content;
		ft_printf("%d\n", b->number);
		ptr = ptr->next;
	}
}

static void	see_idx(t_list *stack)
{
	t_list	*ptr;
	t_body	*b;
	
	ptr = stack;
	ft_putstr_fd("Stack_a:\n", 1);
	while (ptr)
	{
		b = ptr->content;
		ft_printf("%d - %d\n", b->number, b->idx);
		ptr = ptr->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (ft_putstr_fd("Error\n", 1), 0);
	stack_a = NULL;
	stack_b = NULL;
	if (!check_av(&stack_a, argv))
		return (ft_lstclear(&stack_a, free), ft_putstr_fd("Error\n", 1), 0);
	ft_putstr_fd("Checked successfully that all parameters are numbers!\n", 1);
	see_stack(stack_a);
	
	ft_putstr_fd("Added successfully all the data to stack_a\n", 1);
	ft_printf("size -->> %d\n", ft_lstsize(stack_a));

	set_index(stack_a, ft_lstsize(stack_a));
	ft_putstr_fd("after setting index: \n", 1);
	see_idx(stack_a);
	// ********************* OJOOOO  ********************************
	// incerc sa pushui elementele cu cel mai mare numar de cifre din a in b in interiorul unei bucle while
	// atat timp cat pushui cate unu, incerc sa le sortez direct prin sort_b;
	//
	//	while (push_elemets(&stack_a, &stack_b, digits(&stack_a)))
	//		sort_b(&stack_b);
	// ***************************************************************** 

	// see_stacks(stack_a, stack_b);
	// if (stack_b)
	// 	free_stack(stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}