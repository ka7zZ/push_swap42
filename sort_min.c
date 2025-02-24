/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:24:18 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/24 15:24:04 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (third > first && second > third)
	{
		swap(stack_a, stack_b, 'a');
		rotate(stack_a, stack_b, 'a');
	}
	if (first > second && third > first)
		swap(stack_a, stack_b, 'a');
	if (third > second && first > third)
		rotate(stack_a, stack_b, 'a');
}

static void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	t_body	*body_a;
	size_t	pos;

	while (ft_lstsize(*stack_a) > 3)
	{
		body_a = (t_body *)(*stack_a)->content;
		if (body_a->i == 1 || body_a->i == 2)
			push(stack_a, stack_b, 'b');
		pos = idx_pos(stack_a, 1);
		if (!pos)
			pos = idx_pos(stack_a, 2);
		if (pos && pos <= ft_lstsize(*stack_a) / 2)
			rotate(stack_a, stack_b, 'a');
		else if (pos)
			rev_rotate(stack_a, stack_b, 'a');	
	}
}

static void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		first_b;
	int		second_b;

	set_index(*stack_a, ft_lstsize(*stack_a), 0);
	push_to_b(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	first_b = ((t_body *)(*stack_b)->content)->i;
	second_b = ((t_body *)(*stack_b)->next->content)->i;
	if (first_b < second_b)
		swap(stack_a, stack_b, 'b');
	if (ft_lstsize(*stack_b) == 2)
		push(stack_a, stack_b, 'a');
	push(stack_a, stack_b, 'a');
}

void	sort_min(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2 && !check_sorted(*stack_a))
		swap(stack_a, stack_b, 'a');
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) <= 5)
		sort_five(stack_a, stack_b);
	ft_lstclear(stack_a, free);
}
