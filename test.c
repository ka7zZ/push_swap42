#include "libft/libft.h"
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

// function to get the biggest digits numbers
static int	digits(t_list **stack_a)
{
	t_list 		*ptr;
	int		digits;
	int check_digits;

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

// function to stop applying the algorythm to the stack_b
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
			if (a < b)
				check = 0;
		}
		ptr = buf;
	}
	return (check);
}

//function to push elements from stack_a to stack_b with the digits number
static int	push_elements(t_list **stack_a, t_list **stack_b, int check_digits, int *moves)
{
	t_list	*ptr;
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
	while (--i && size == check_digits)
	{
		*moves += 1;
		ra(stack_a);
	}
	if (size == check_digits)
	{
		pb(stack_a, stack_b);
		*moves += 1;
		return (1);
	}
	return (0);
}

// function to push to stack_a arranged elements from stack_b
static void arrange_b(t_list **stack_a, t_list **head_b, int *moves)
{
	int	first;
	int second;
	int	last;
	int	size;

	if (head_b && *head_b && !check_stop(*head_b))
	{
		first = ft_atoi((char *)(*head_b)->content);
		second = ft_atoi((char *)(*head_b)->next->content);
		last = ft_atoi((char *)ft_lstlast(*head_b)->content);
		if (first < second)
			sb(head_b);
		else if (first > second && first > last && second < last )
			rrb(head_b);
		else
			rb(head_b);
		*moves += 1;
	}
	else if (head_b && *head_b)
	{
		size = ft_lstsize(*head_b);
		*moves += size;
		while (size--)
			pa(stack_a, head_b);
	}
}


int main(int ac, char **av)
{
	t_list  *stack_a;
	t_list  *stack_b;
	int		loop;
	int		round;
	int		check_digits;
	int		moves;

	if (ac < 2)
		return (ft_putstr_fd("Error\n", 1), 0);
	stack_a = NULL;
	stack_b = NULL;
	if (!check_av(&stack_a, av))
		return (free_stack(stack_a), ft_putstr_fd("Error\n", 1), 0);
	moves = 0;
	round = 0;
	see_stack(stack_a);
	check_digits = digits(&stack_a);
	ft_printf("moves before while(check_digits)--->> %d\n", moves);
	while (check_digits)
	{
		round++;
		while (push_elements(&stack_a, &stack_b, check_digits, &moves));
		ft_printf("moves after while(push)[%d round] --->> %d\n", round, moves);
		while (stack_b)
			arrange_b(&stack_a, &stack_b, &moves);
		ft_printf("moves after while(stack)[%d round] --->> %d\n", round, moves);
		check_digits -= 1;
	}
	see_stack(stack_a);
	ft_printf("stack size ---->> %d\nmoves end of main ----->> %d\n", ft_lstsize(stack_a), moves);
	return (0);
}
