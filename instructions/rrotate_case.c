/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:58:21 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/08 19:40:46 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **a)
{
	t_list	*ptr_a;
	t_list	*ptr_buf;

	ptr_a = *a;
	while (ptr_a->next != NULL)
	{
		ptr_buf = ptr_a;
		ptr_a = ptr_a->next;
	}
	ptr_buf->next = NULL;
	ft_lstadd_front(a, ptr_a);
}

void	rrb(t_list **b)
{
	t_list	*ptr_a;
	t_list	*ptr_buf;

	ptr_a = *b;
	while (ptr_a->next != NULL)
	{
		ptr_buf = ptr_a;
		ptr_a = ptr_a->next;
	}
	ptr_buf->next = NULL;
	ft_lstadd_front(b, ptr_a);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}

