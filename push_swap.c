#include "push_swap.h"

void	see_stacks(t_list *a, t_list *b)
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

void	see_stack(t_list *s)
{
	t_list *ptr;

	ptr = s;
	while (ptr)
	{
		ft_printf("%s\n", ptr->content);
		ptr = ptr->next;
	}
	ft_putstr_fd("-\n", 1);
	ft_putstr_fd("a/b\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*ptr_a;
	t_list	*ptr_b;
	t_list	*ptr_sa;
	t_list	*ptr_push;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	i = 0;
	while (argv[++i])
	{
		if (!ft_atoi(argv[i]))
			return (ft_putstr_fd("Error\n", 1), 0);
	}
	ft_putstr_fd("Checked successfully that all parameters are numbers!\n", 1);
	i = 0;
	stack_a = NULL;
	while (argv[i++])
	{
		if (!stack_a)
			stack_a = ft_lstnew(argv[i]);
		else
			ft_lstadd_back(&stack_a, ft_lstnew(argv[i]));
	}
	ft_putstr_fd("Added successfully all the data to stack_a\n", 1);
	ft_putstr_fd("\n\n\nDone.\nNow the tests of instructions:\n\n", 1);
	stack_b = ft_lstnew(NULL);

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

	return (0);
}
