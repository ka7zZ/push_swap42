/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:20:09 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/18 11:28:06 by aghergut         ###   ########.fr       */
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
	ft_putstr_fd("Stack_a:\n", 1);
	while (ptr)
	{
		b = ptr->content;
		ft_printf("%d - %d\n", b->n, b->i);
		ptr = ptr->next;
	}
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
	if (ra < rra)
		return (1);
	return (0);
}

// push to a from b: logic
static void push_to_a(t_list **stack_a, t_list **stack_b, int bits)
{
	t_list	*ptr;
	t_list	*buf;
	t_body	*body_sb;

	ptr = *stack_b;
	while (ptr)
	{
		buf = ptr->next;
		body_sb = ptr->content;
		if ((body_sb->i >> (bits + 1)) & 1)
			rotate(stack_a, stack_b, 'b');
		else
			push(stack_a, stack_b, 'a');
		if (buf)
			ptr = buf;
	}
}

// setting the indexes for all the numbers
static void	set_index(t_list *stack_a, int length, int idx)
{
	t_list	*ptr;
	t_list	*buf;
	t_body	*bcompare;
	t_body	*bbuf;

	while (length--)
	{
		ptr = stack_a;
		while (ptr && ((t_body *)ptr->content)->i)
			ptr = ptr->next;
		buf = ptr;
		if (buf)
			bbuf = buf->content;
		while (ptr->next)
		{
			bcompare = ptr->next->content;
			if (!bcompare->i && bbuf->n > bcompare->n)
			{
				buf = ptr->next;
				bbuf = buf->content;
			}
			ptr = ptr->next;	
		}
		bbuf->i = ++idx;	
	}
}

// checking if its sorted
static int	check_sorted(t_list *stack_a)
{
	t_list	*ptr;
	t_list	*temp;
	t_body	*body_ptr;
	t_body	*body_temp;
	int		check;

	check = 1;
	ptr = stack_a;
	while (ptr->next)
	{
		if (ptr->content)
			body_ptr = (t_body *)ptr->content;
		temp = ptr->next;
		if (temp->content)
			body_temp = (t_body *)temp->content;
		if (body_ptr && body_temp && body_ptr->n > body_temp->n)
			check = 0;
		ptr = ptr->next;
	}
	return (check);
}

// sort a stack of three
static void sort_three(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	second;
	int	third;

	first = ((t_body *)(*stack_a)->content)->n;
	second = ((t_body *)(*stack_a)->next->content)->n;
	third = ((t_body *)ft_lstlast(*stack_a)->content)->n;
	if (first > second && second > third)
	{
		swap(stack_a, stack_b, 'a');
		rev_rotate(stack_a, stack_b, 'a');	
	}
	if (first > third && second > first)
		rev_rotate(stack_a, stack_b, 'a');
	if (first > second && second < third && first > third)
		rotate(stack_a, stack_b, 'a');
	if (first < second && second > third && first < third)
	{
		rev_rotate(stack_a, stack_b, 'a');
		swap(stack_a, stack_b, 'a');
	}
	if (first > third && second > first)
		rev_rotate(stack_a, stack_b, 'a');
	if (first > second && second < third && first > third)
		rotate(stack_a, stack_b, 'a');
}

static void sort_five (t_list **stack_a, t_list **stack_b)
{
	
}
// sort a stack larger than 5
static void	sort_large(t_list **stack_a, t_list **stack_b, int *moves)
{
	t_list	*ptr;
	t_body	*body_a;
	int		bits;
	int		idx;
	int		size;

	bits = -1;
	while (++bits < 9)
	{
		ptr = *stack_a;
		size = ft_lstsize(ptr);
		while (size-- && !check_sorted(*stack_a))
		{
			body_a = ptr->content;
			ptr = ptr->next;
			idx = body_a->i;
			if (((idx >> bits) & 1) == 0)
				push(stack_a, stack_b, 'b');
			if (smart_move(stack_a, stack_b, bits))
				rotate(stack_a, stack_b, 'a');
			else
				rev_rotate(stack_a, stack_b, 'a');
		}
		push_to_a(stack_a, stack_b, bits);
	}	
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		moves;

	if (argc < 1)
		return (ft_putstr_fd("Error\n", 1), 0);
	stack_a = NULL;
	stack_b = NULL;
	moves = 0;
	if (!check_av(&stack_a, argv))
		return (ft_lstclear(&stack_a, free), ft_putstr_fd("Error\n", 1), 0);
	if 	(ft_lstsize(stack_a) < 2)
		return (ft_lstclear(&stack_a, free), 0);
	if (ft_lstsize(stack_a) == 2 && !check_sorted(stack_a))
		return (swap(&stack_a, &stack_b, 'a'), ft_lstclear(&stack_a, free), 0);
	if (ft_lstsize(stack_a) == 3)
		return (sort_three(&stack_a, &stack_b), ft_lstclear(&stack_a, free), 0);
	set_index(stack_a, ft_lstsize(stack_a), 0);
	sort_large(&stack_a, &stack_b, &moves);
	ft_lstclear(&stack_a, free);
	return (0);
}


/*
static void	send_bits(t_list **stack_a, t_list **stack_b, int bits)
{
	t_body	*ba;
	int		bit;
	int		n;
	
	ba = (*stack_a)->content;
	n = ba->n;
	bit = ;
	if (bit == 0)
		push(stack_a, stack_b, 'b');
	else
		rotate(stack_a, stack_b, 'a');
}
*/

