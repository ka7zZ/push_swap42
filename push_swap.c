/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:20:09 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/19 17:44:49 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

static void	see_stack(t_list *stack)
{
	t_list	*ptr;
	t_body	*b;
	
	ptr = stack;
	while (ptr)
	{
		b = ptr->content;
		ft_printf("%d\n", b->n);
		ptr = ptr->next;
	}
}

static void	see_idx(t_list *stack)
{
	t_list	*ptr;
	t_body	*b;
	
	ptr = stack;
	ft_putstr_fd("Stack:\n", 1);
	while (ptr)
	{
		b = ptr->content;
		ft_printf("%d - %d\n", b->n, b->i);
		ptr = ptr->next;
	}
}

static int	get_max(t_list **stack)
{
	t_list	*ptr;
	t_body	*body_ptr;
	int		res;

	ptr = *stack;
	res = 0;
	while (ptr)
	{
		body_ptr = (t_body *)ptr->content;
		if (body_ptr->i > res)
			res = body_ptr->i;
		ptr = ptr->next;
	}
	return (res);
}

unsigned int count_bits(unsigned int n) 
{ 
   unsigned int count = 0;
   
   while (n) 
   { 
        count++; 
        n >>= 1; 
    } 
    return (count); 
}

// for rotate or rev_rotate in a for searching item to push to b;
static int smart_move(t_list **stack_a, t_list **stack_b, int bits)
{
	t_list	*ptr;
	t_body	*body_ptr;
	int		ra;
	int		rra;
	int		size;
	
	ptr = *stack_a;
	ra = 0;
	rra = 0;
	size = ft_lstsize(ptr);
	while (ptr)
	{
		body_ptr = (t_body *)ptr->content;
		if (!((body_ptr->i >> bits) & 1))
		{
			if (!ra)
				ra = ft_lstsize(*stack_a) - size;
			rra = size;
		}
		size--;
		ptr = ptr->next;
	}
	if (ra <= rra)
		return (1);
	return (0);
}

// push to a from b: logic
static void push_to_a(t_list **stack_a, t_list **stack_b, int bits)
{
	t_list	*ptr;
	t_list	*buf;
	t_body	*body_sb;
	int		size;
	
	ptr = *stack_b;
	while (check_bit(stack_b, bits + 1, 1))
	{
		buf = ptr->next;
		body_sb = ptr->content;
		if (((body_sb->i >> (bits + 1)) & 1) == 0)
			rotate(stack_a, stack_b, 'b');
		else
			push(stack_a, stack_b, 'a');
		if (buf)
			ptr = buf;
	}
}

// sort a stack larger than 5
static void	sort_large(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	t_list	*buf;
	t_body	*body_a;
	int		bits;
	int		fin;
	int		size;

	bits = -1;
	fin = count_bits(get_max(stack_a));
	while (++bits < fin)
	{
		size = ft_lstsize(*stack_a);		
		while (size-- && !check_sorted(*stack_a))
		{
			ptr = *stack_a;
			body_a = (t_body *)ptr->content;
			if (((body_a->i >> bits) & 1) == 0)
				push(stack_a, stack_b, 'b');
			else
				rotate(stack_a, stack_b, 'a');				
		}
		while (*stack_b)
			push(stack_a, stack_b, 'a');
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 1)
		return (ft_putstr_fd("Error\n", 1), 0);
	stack_a = NULL;
	stack_b = NULL;
	if (!check_av(&stack_a, argv))
		return (ft_lstclear(&stack_a, free), ft_putstr_fd("Error\n", 1), 0);
	if (check_sorted(stack_a))
		return (ft_lstclear(&stack_a, free), 0);
	if (ft_lstsize(stack_a) <= 5)
		return (sort_min(&stack_a, &stack_b), ft_lstclear(&stack_a, free), 0);
	set_index(stack_a, ft_lstsize(stack_a), 0);
	sort_large(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}

