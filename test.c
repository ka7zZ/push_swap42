#include "libft/libft.h"

int main(int ac, char **av)
{
	/*content of main of test-c
	// t_list  *stack_a;
	// t_list  *stack_b;
	// int		check_digits;
	// int		bz;
	// int		moves;

	// if (ac < 2)
	// 	return (ft_putstr_fd("Error\n", 1), 0);
	// stack_a = NULL;
	// stack_b = NULL;
	// if (!check_av(&stack_a, av))
	// 	return (free_stack(stack_a), ft_putstr_fd("Error\n", 1), 0);
	
	// bz = ft_lstsize(stack_a);
	// moves = 0;
	// if (bz > 20)
	// {
	// 	check_digits = digits(&stack_a);
	// 	while (check_digits)
	// 	{
	// 		while (push_b(&stack_a, &stack_b, check_digits, &moves));
	// 		check_digits--;
	// 	}
	// 	while (!check_stop(stack_a))
	// 		arrange(&stack_a, &stack_b, 'a', &moves);		
	// 	while (!check_stop(stack_b))
	// 		arrange(&stack_a, &stack_b, 'b', &moves);
	// 	push_a(&stack_a, &stack_b, check_digits, &moves);
	// }
	// while (!check_stop(stack_a))
	// 	arrange(&stack_a, &stack_b, 'a', &moves);
	// see_stack(stack_a);
	// ft_printf("moves -->> %d\n", moves);
	// moves = 0;
	// while (!check_stop(stack_a))
	// 	arrange_stack(&stack_a, &stack_b, 'a', &moves);
	// ft_printf("moves -->> %d\n", moves);	
	// see_stack(stack_a);
	*/
	printf("Converted: %ld\n", ft_atoi("-2147483648"));
	printf("Converted: %ld\n", ft_atoi("2147483647"));
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

/* another functions of test
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

// function to get number of digits
static int	get_digits(long num)
{
	int		digits;

	digits = 0;
	while (num > 0)
	{
		digits += 1;
		num /= 10;
	}
	return (digits);
}

// fct to give max digit number
static int	max_digits(t_list **stack_a)
{
	t_list 		*ptr;
	int		digits;
	int		check_digits;

	ptr = *stack_a;
	digits = 0;
	check_digits = 0;
	while (ptr)
	{
		digits = get_digits(ft_atoi((char *)ptr->content));
		if (digits > check_digits)
			check_digits = digits;
		ptr = ptr->next;
	}
	return (check_digits);
}
*/

/*
- arrange stack by the positive digits and negative digits
pseudocode 1: 

positive numbers arrange:
max_d = max_digit;
while (max_d--)
	push to stackb numbers of max_d
	arrange and push to the end of stacka

same story for the negative but with min_d digit numbers;


ex:
stack a stack_b
	
45		10 -> rra rra rra rra rra pb if n == 1 -> pa
34		21 -> rra pb if n == 1 -> pa
67	    32 -> rra pb if n == 1 -> pa
87	68  43 -> rra pb if n == 1 -> pa
58	43	34 -> rra ra ra ra pb if n == 1 -> pa 
43  32  45 -> ra pb		|if lstsize(stackb) <= 3 -->>> apply 3 case sort
32  21  5 -> ra ra pb   |else if <= 5 --->> apply 5 case sort
21  10  				|else if apply big sort
10  99     				| in this case only sb pa pa
99  46  46 -> ra pb n == 1 -> pa
46  5	67 -> cost pb (5 movements): ra ra ra ra ra pb |apply 3 case sort| sa pb pb 
5   45  87 -> cost pb (6 movements): pb
9   34	68 -> ra ra pb if n == 1 -> pa
	87    9 -> rra rra 
	67
	
	174 moves
notes = check cost -->> check how many movevs it would take to bring them into the push mode

pseudocode 2:

put negative into stack b
let positive into stack a
arrange stack_a
arrange_stack_b from the greatest numbers to the smallest
push stack b into stack a

*/

/* functions of test.c

typedef struct test
{
	int	number;
	int	index;
}	t_test;

static void init(t_list *head)
{
	t_list *ptr;
	t_test	*ptr_content;

	ptr = head;
	while (ptr)
	{
		ptr_content = ptr->content;
		ptr_content->index = 0;
		ptr = ptr->next;	
	}

static int	push_a(t_list **a, t_list **b, int check_digits, int *moves)
{
	t_list *ptr;
	int		check;
	
	check = 0;
	while (*b)
	{
		check = 1;
		ptr = (*b)->next;
		push(a, b, 'a');
		if (!check_digits)
			rotate(a, b, 'a');
		*moves += 2;
		*b = ptr;
	}
	return (check);
}

}

// function to stop applying the algorythm to the stack_b
static int	check_stop(t_list *stack)
{
	t_list	*ptr;
	t_list	*buf;
	long	a;
	long	b;
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

static int	check_digits(t_list *stack, int digits)
{
	t_list	*ptr;
	long	num;
	int		size;
	int		check;

	check = 0;
	size = 0;
	ptr = stack;
	while (ptr)
	{
		num = ft_atoi((char *)ptr->content);
		if (num >= 0)
			size = get_digits(num);
		if (size && size == digits)
			check = 1;
		ptr = ptr->next;
	}
	return (check);
}

static void	arrange_stack(t_list **stack_a, t_list **stack_b, char type, int *moves)
{
	t_list	*ptr;
	long	first;
	long	sec;
	long	last;

	if (type == 'a')
		ptr = *stack_a;
	else
		ptr = *stack_b;
	first = ft_atoi((char *)ptr->content);
	sec = ft_atoi((char *)ptr->next->content);
	last = ft_atoi((char *)ft_lstlast(ptr)->content);
	if (first > sec)
		swap(stack_a, stack_b, 'a');
	else if ( first < last && sec > last)
		rev_rotate(stack_a, stack_b, 'a');
	else
		rotate(stack_a, stack_b, 'a');
	*moves += 1;
}

// optimizing stack_a for pushing to B when finding the digits number, reduces 50k moves;
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

*/

/* push_b func 
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
		optimize_search(stack_a, stack_b, check_digits, moves);
		push(stack_a, stack_b, 'b');
		*moves += 1;
	}
	return (res);
}
*/

/*ideas for optimizing code

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