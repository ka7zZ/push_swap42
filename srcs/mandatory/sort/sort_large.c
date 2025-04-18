/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:22:53 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/27 17:04:43 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static int	check_next(t_list *stack_b, int bits)
{
	t_list	*ptr;
	t_body	*body;
	int		check;

	ptr = stack_b;
	check = 0;
	while (ptr)
	{
		body = ptr->content;
		if (((body->i >> bits) & 1) == 1)
			check = 1;
		ptr = ptr->next;
	}
	return (check);
}

static void	push_from_b(t_list **stack_a, t_list **stack_b, int bits)
{
	t_body	*buf;
	int		size;

	bits += 1;
	size = ft_lstsize(*stack_b);
	while (size--)
	{
		buf = (t_body *)(*stack_b)->content;
		if (((buf->i >> bits) & 1) == 0)
			rotate(stack_a, stack_b, 'b');
		else
			push(stack_a, stack_b, 'a');
	}
}

static int	get_max(t_list *stack)
{
	t_list	*ptr;
	t_body	*body_ptr;
	int		res;

	ptr = stack;
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

static unsigned int	count_bits(unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (n)
	{
		count++;
		n >>= 1;
	}
	return (count);
}

void	sort_large(t_list **stack_a, t_list **stack_b)
{
	t_body	*body_a;
	int		bits;
	int		fin;
	int		size;

	bits = -1;
	fin = count_bits(get_max(*stack_a));
	while (++bits < fin)
	{
		size = ft_lstsize(*stack_a);
		while (size-- && !check_sorted(*stack_a))
		{
			body_a = (t_body *)(*stack_a)->content;
			if (((body_a->i >> bits) & 1) == 0)
				push(stack_a, stack_b, 'b');
			else
				rotate(stack_a, stack_b, 'a');
		}
		while (!check_next(*stack_a, bits + 1) && *stack_b)
			push(stack_a, stack_b, 'a');
		if (check_next(*stack_b, bits + 1))
			push_from_b(stack_a, stack_b, bits);
	}
}
