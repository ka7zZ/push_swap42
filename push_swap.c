#include "push_swap.h"

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

static void	see_stack(t_list *stack)
{
	t_list *ptr;

	ptr = stack;
	while (ptr)
	{
		ft_printf("%s\n", ptr->content);
		ptr = ptr->next;
	}
	ft_putstr_fd("-\n", 1);
	ft_putstr_fd("a/b\n", 1);
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

static void		push_and_sort(t_list **stack_a, t_list **stack_b, int check_digits)
{
	t_list	*buf;
	int		digits;

	buf = *(stack_a)->next;
	digits = ft_strlen(*(stack_a)->content);
	if (ft_strchr(*(stack_a)->content, '-'))
		digits--;
	if (digits != check_digits)
		ra(stack_a);
}

static void	digits(t_list **stack_a, t_list **stack_b)
{
	t_list 		*ptr;
	size_t		digits;
	size_t		check_digits;

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
	push_and_sort(stack_a, stack_b, check_digits);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (ft_putstr_fd("Error\n", 1), 0);
	stack_a = NULL;
	stack_b = ft_lstnew(NULL);
	if (!check_av(&stack_a, argv))
		return (free_stack(stack_a), ft_putstr_fd("Error\n", 1), 0);
	see_stack(stack_a);
	ft_putstr_fd("Checked successfully that all parameters are numbers!\n", 1);
	ft_putstr_fd("Added successfully all the data to stack_a\n", 1);
	digits(&stack_a, &stack_b);
	see_stacks(stack_a, stack_b);
	if (stack_b)
		free_stack(stack_b);
	free_stack(stack_a);
	return (0);
}

/* TESTING INSTRUCTIONS
	
	ft_putstr_fd("\n\n\nDone.\nNow the tests of instructions:\n\n", 1);
	

	// Swap first 2 in A 
	ft_putstr_fd("sa:\n", 1);
	sa(&stack_a);
	see_stack(stack_a);
	
	// Push to B
	ft_putstr_fd("----------\npb pb pb:\n", 1);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	see_stacks(stack_a, stack_b);

	// Shift elements from stacks one position up (the first become the last)
	ft_putstr_fd("----------\nra / rb:\n", 1);
	rr(&stack_a, &stack_b);
	see_stacks(stack_a, stack_b);

	// Shift elements from stacks one position down (the last become the first)
	ft_putstr_fd("----------\nrra / rrb:\n", 1);
	rrr(&stack_a, &stack_b);
	see_stacks(stack_a, stack_b);

	//
	ft_putstr_fd("----------\nsa:\n", 1);
	sa(&stack_a);
	see_stacks(stack_a, stack_b);

	//
	ft_putstr_fd("----------\npa pa pa:\n", 1);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	see_stacks(stack_a, stack_b);
	
	*/
