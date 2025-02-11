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
}

// binary get last

// function to get the biggest digits numbers
static int	digits(t_list **stack_a)
{
	t_list 		*ptr;
	int		digits;
	int check_digits;

	ptr = *stack_a;
	check_digits = 0;
	while (ptr)
	{
		digits = 0;
		if (!ft_strchr((char *)ptr->content, '-'))
		{	
			if (ptr->content)
				digits = ft_strlen(ptr->content);
			if (digits > check_digits)
				check_digits = digits;
		}
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
			if (a > b)
				check = 0;
		}
		ptr = buf;
	}
	return (check);
}

static int	find_digits(t_list *stack, int digits)
{
	t_list	*ptr;
	int		size;
	int		check;

	check = 0;
	size = 0;
	ptr = stack;
	while (ptr)
	{
		if (!ft_strchr((char *)ptr->content, '-'))
			size = ft_strlen((char *)ptr->content);
		if (size && size >= digits)
			check = 1;
		ptr = ptr->next;
	}
	return (check);
}

static void	arrange(t_list **stack_a, t_list **stack_b, char type, int *moves)
{
	t_list	*ptr;
	int		first;
	int		sec;
	int		last;

	if (type == 'a')
		ptr = *stack_a;
	if (type == 'b')
		ptr = *stack_b;
	first = ft_atoi((char *)ptr->content);
	sec = ft_atoi((char *)ptr->next->content);
	last = ft_atoi((char *)ft_lstlast(ptr)->content);
	if (first > sec)
		swap(stack_a, stack_b, type);
	else if (first < sec && first < last && sec > last)
		rev_rotate(stack_a, stack_b, type);
	else
		rotate(stack_a, stack_b, type);
	*moves += 1;
}

//function to push elements from stack_a to stack_b with the digits number
static int	push_b(t_list **stack_a, t_list **stack_b, int check_digits, int *moves)
{
	t_list	*buf;
	int		size;
	int		res;

	res = 0;
	size = 0;
	while (find_digits(*stack_a, check_digits))
	{
		buf = *stack_a;
		if (!ft_strchr((char *)buf->content, '-'))
			size = ft_strlen((char *)buf->content);
		if (size >= check_digits)
		{
			push(stack_a, stack_b, 'b');
			res = 1;
		}	
		else
			rotate(stack_a, stack_b, 'a');
		*moves += 1;
	}
	return (res);
}

static void	push_a(t_list **a, t_list **b, int *moves)
{
	t_list *ptr;

	while (*b)
	{
		ptr = (*b)->next;
		push(a, b, 'a');
		rotate(a, b, 'a');
		*moves += 2;
		*b = ptr;
	}
}

int main(int ac, char **av)
{
	t_list  *stack_a;
	t_list  *stack_b;
	int		check_digits;
	int		bz;
	int		moves;

	if (ac < 2)
		return (ft_putstr_fd("Error\n", 1), 0);
	stack_a = NULL;
	stack_b = NULL;
	if (!check_av(&stack_a, av))
		return (free_stack(stack_a), ft_putstr_fd("Error\n", 1), 0);
	check_digits = digits(&stack_a);
	bz = check_digits / 2;
	moves = 0;
	while (check_digits > bz)
	{
		while (push_b(&stack_a, &stack_b, check_digits, &moves));
		check_digits--;
	}
	while (!check_stop(stack_a))
		arrange(&stack_a, &stack_b, 'a', &moves);		
	while (!check_stop(stack_b))
		arrange(&stack_a, &stack_b, 'b', &moves);
	push_a(&stack_a, &stack_b, &moves);
	see_stack(stack_a);
	ft_printf("moves -->> %d\n", moves);
	return (0);
}

/* divide stack
static void	divide_stack(t_list **stack_a, t_list **stack_b)
{
	int	biggest;
	int	size;

	biggest = digits(stack_a)
	if (*stack_a)
		size = ft_lstsize(*stack_a);
	while (*stack_a && (*stack_a)->next && ft_lstsize(*stack_a) != size / 2)
	{
		ptr = (*stack_a)->next;
		first_a = ft_atoi((char *)(*stack_a)->content);
		second_a = ft_atoi((char *)(*stack_a)->next->content);
		if (first_a > second_a)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		*stack_a = ptr;
	}
	while (!check_stop(*stack_a, 'a'))
		arrange(stack_a, 'a');
	while(!check_stop(*stack_b, 'b'))
		arrange(stack_b, 'b');
}
*/

/* ex arrange
// function to push to stack_a arranged elements from stack_b
static void arrange(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int second;
	int	last;
	int	size;

	if (*stack_b && (*stack_b)->next && !check_stop(*stack_b))
	{
		first = ft_atoi((char *)(*stack_b)->content);
		second = ft_atoi((char *)(*stack_b)->next->content);
		last = ft_atoi((char *)ft_lstlast(*stack_b)->content);
		if (first < second)
			sb(stack_b);
		else if (first > second && first > last && second < last )
			rrb(stack_b);
		else
			rb(stack_b);
	}
}
*/

/* send_bucket intent
// send arranged buckets to stack_a
static void	ft_send_bucket(t_list **stack_a, t_list **stack_b, int *moves)
{
	t_list	*head_a;
	t_list	*head_b;
	int		first;
	int		second;
	int		last;

	pa(stack_a, stack_b);
	while (ft_atoi((*stack_a)->content) > ft_atoi((*stack_a)->next->content))
	{
		
	}
}
*/

/* arrangeby_digit intent
static void	arrangeby_digits(t_list **stack_a)
{
	t_list	*ptr;
	int		max_digits;
	int		i;

	ptr = *stack_a;
	max_digits = digits(stack_a);
	i = 0;

}
*/

/*ideas for optimizing code

using an index for rev_rotate or rotate: if its close to the first half, rotate
										 else rev_rotate;
using integer functions
using median pivot sorting

as much as I want, i have to change the structure for a int, index and what do I need more. the one from the libft isn't enough;

    Inefficient push_b logic
        The function scans stack_a for elements based on their string length. This is not an effective sorting criterion and likely leads to unnecessary rotations.
        Optimization: Use Radix Sort or a Median Pivot Sorting strategy instead of relying on string length.

    Unnecessary Rotations in arrange
        The arrange function sometimes rotates when it isn't strictly needed.
        Optimization: Implement smarter pivot selection to reduce rotations.

    Inefficient push_a
        push_a does a push followed by a rotate for every element, leading to an unnecessary extra move.
        Optimization: Use simpler push logic and avoid rotating unless necessary.

    General Sorting Strategy
        Currently, push_b works in a brute-force manner, pushing values based on digits rather than sorting efficiently.
        Optimization: Implement a better chunking method, such as:
            Radix Sort (binary-based, used in push_swap optimizations).
            Quick Sort-inspired approach (push numbers above/below a median).
            Group-based chunk sorting (splitting the list into smaller sorted subsections).

Proposed Optimized Approach

    Use Radix Sort Instead of Current Push Mechanism
        Instead of checking digit length, sort numbers using bitwise sorting (Radix Sort).
        This allows moving elements in a structured way, reducing unnecessary operations.

    Use a Smarter Pivot Selection (Median)
        Instead of a naive approach to moving elements to stack_b, find the median of stack_a and push elements smaller than the median first.

    Improve Push & Rotation Strategy
        Instead of rotating on every push, keep a window of sorted elements.
        Push elements back in a more controlled way.

How to Implement These Changes?

    Modify push_b to use a more efficient sorting method
    Reduce unnecessary rotations in arrange
    Optimize push_a to avoid redundant moves
    Change the sorting approach from digit-based to value-based

Would you like me to rewrite the relevant functions with these optimizations?

to loearn more about algorithms and developing solutions!!!!

*/