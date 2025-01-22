#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*ptr_a;
	t_list	*ptr_b;
	t_list	*ptr_sa;

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
	ptr_a = stack_a;
	i = 0;
	while (ptr_a)
	{
		ft_printf("[%d element] --->> %s\n", ++i, ptr_a->content);
		ptr_a = ptr_a->next;
	}
	ft_putstr_fd("\n\n\nDone.\nNow the tests of instructions:\n\n", 1);
	stack_b = (t_list *)malloc(sizeof(t_list));
	ft_putstr_fd("sa:\n", 1);
	sa(&stack_a);
	ptr_sa = stack_a;
	while (ptr_sa)
	{
		ft_printf("[1 element] --->> %s\n", ptr_sa->content);
		ptr_sa = ptr_sa->next;
	}
	ft_putstr_fd("pb pb pb:\n", 1);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	ptr_b = stack_b;
	while(ptr_b)
	{
		ft_printf("[1 element] --->> %s\n", ptr_b->content);
		ptr_b = ptr_b->next;
	}
	ft_putstr_fd("ra / rb:\n", 1);
	ft_putstr_fd("rra / rrb:\n", 1);
	ft_putstr_fd("sa:\n", 1);
	ft_putstr_fd("pa pa pa:\n", 1);
	

	return (0);
}
