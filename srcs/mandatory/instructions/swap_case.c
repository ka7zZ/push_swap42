/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:59:52 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/26 17:15:34 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static void	sa(t_list **a)
{
	t_list	*ptr_a;
	t_list	*ptr_next;

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

static void	sb(t_list **b)
{
	t_list	*ptr_b;
	t_list	*ptr_next;

	if (*b && (*b)->next)
	{
		ptr_b = *b;
		ptr_next = ptr_b->next;
		ptr_b->next = ptr_next->next;
		ptr_next->next = ptr_b;
		*b = ptr_next;
		write(1, "sb\n", 3);
	}
}

static void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	swap(t_list **a, t_list **b, char type)
{
	if (type == 'a')
		sa(a);
	if (type == 'b')
		sb(b);
	if (type == 's')
		ss(a, b);
}
