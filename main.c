#include "libft/libft.h"

static void	sa(t_list **a)
{
	t_list *ptr_a;
	t_list *ptr_next;

	if (*a && (*a)->next)
	{
		ptr_a = *a;
		ptr_next = ptr_a->next;
		ptr_a->next = ptr_next->next;
		ptr_next->next = ptr_a;
		*a = ptr_next;
		write(1, "sa\n", 3);
	}
}

static void	ra(t_list **a)
{
	t_list	*ptr;
	t_list	*next;

	if (*a)
	{
		ptr = *a;
		next = ptr->next;
		ptr->next = NULL;
		*a = next;
		ft_lstadd_back(a, ptr);
		write(1, "ra\n", 3);
	}
}

static void	rra(t_list **a)
{
	t_list	*ptr_a;
	t_list	*ptr_buf;

	if (a && *a)
	{
		ptr_a = *a;
		while (ptr_a->next != NULL)
		{
			ptr_buf = ptr_a;
			ptr_a = ptr_a->next;
		}
		ptr_buf->next = NULL;
		ft_lstadd_front(a, ptr_a);
		write(1, "rra\n", 4);    
	}
	
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
}

static void	arrange_stack(t_list **stack, int *moves)
{
	t_list	*ptr;
	int	first;
	int	sec;
	int	last;

	ptr = *stack;
	first = ft_atoi((char *)ptr->content);
	sec = ft_atoi((char *)ptr->next->content);
	last = ft_atoi((char *)ft_lstlast(ptr)->content);
	if (first > sec)
		sa(stack);
	else if (first < sec && first < last && sec > last)
		rra(stack);
	else
		ra(stack);
	*moves += 1;
}

static int	check_stop(t_list *stack)
{
	t_list	*ptr;
	t_list	*buf;
	int		a;
	int		b;
	int		check;

	check = 1;
	ptr = stack;
	while (ptr)
	{
		buf = ptr->next;
		if (buf)
		{
			a = ft_atoi((char *)ptr->content);
			b = ft_atoi((char *)buf->content);
			if (a > b)
				check = 0;
		}
		ptr = buf;
	}
	return (check);
}

static void	printing_bits(int a)
{
	int	bits;

	bits = sizeof(a) * 8;
	while (bits--)
	{
		if (a & (1 << bits))
			ft_putchar_fd('1', 1);
		else
			ft_putchar_fd('0', 1);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack1;
	int		moves;
	int		i;
	int		n;

	stack1 = NULL;
	i = 0;
	while (av[++i])
	{
		if (!stack1)
			stack1 = ft_lstnew(ft_itoa(ft_atoi(av[i])));
		else
			ft_lstadd_back(&stack1, ft_lstnew(ft_itoa(ft_atoi(av[i]))));
	}
	moves = 0;
	see_stack(stack1);
	while (stack1)
	{
		n = ft_atoi((char *)stack1->content);
		ft_printf("Number: \t%d\n", n);
		printing_bits(n);
		ft_putstr_fd("\n\n", 1);
		stack1 = stack1->next;
	}
	//see_stack(stack1);
	return (0);
}