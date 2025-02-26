/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:55:51 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/26 17:15:04 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/checker.h"

static void	ra(t_list **a)
{
	t_list	*ptr;
	t_list	*next;

	if (*a)
	{
		ptr = *a;
		next = ptr->next;
		ptr->next = NULL;
		*a = next;
		ft_lstadd_back(a, ptr);
	}
}

static void	rb(t_list **b)
{
	t_list	*ptr;
	t_list	*next;

	if (*b && (*b)->next)
	{
		ptr = *b;
		next = ptr->next;
		ptr->next = NULL;
		*b = next;
		ft_lstadd_back(b, ptr);
	}
}

static void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}

void	rotate_checker(t_list **a, t_list **b, char type)
{
	if (type == 'a')
		ra(a);
	if (type == 'b')
		rb(b);
	if (type == 'r')
		rr(a, b);
}
