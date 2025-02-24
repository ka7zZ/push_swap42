/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:58:21 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/24 19:53:00 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

static void	rrb(t_list **b)
{
	t_list	*ptr_a;
	t_list	*ptr_buf;

	if (b && *b)
	{
		ptr_a = *b;
		while (ptr_a->next != NULL)
		{
			ptr_buf = ptr_a;
			ptr_a = ptr_a->next;
		}
		ptr_buf->next = NULL;
		ft_lstadd_front(b, ptr_a);
		write(1, "rrb\n", 4);
	}
}

static void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}

void	rev_rotate(t_list **a, t_list **b, char type)
{
	if (type == 'a')
		rra(a);
	if (type == 'b')
		rrb(b);
	if (type == 'r')
		rrr(a, b);
}
