/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:59:52 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/06 16:54:33 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    sa(t_list **a)
{
	t_list *ptr_a;
	t_list *ptr_next;

	if (*a && (*a)->next)
	{
		ptr_a = *a;
		ptr_next = ptr_a->next;
		ptr_a->next = ptr_next->next;
		ptr_next->next = ptr_a;
		*a = ptr_next;
	}
}

void	sb(t_list **b)
{
    t_list *ptr_b;
    t_list *ptr_next;

    if (*b && (*b)->next)
    {
        ptr_b = *b;
        ptr_next = ptr_b->next;
        ptr_b->next = ptr_next->next;
        ptr_next->next = ptr_b;
        *b = ptr_next;
    }
}

void	ss(t_list **a, t_list **b)
{
    sa(a);
    sb(b);
}

