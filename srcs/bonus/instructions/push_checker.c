/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:52:02 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/26 17:14:55 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/checker.h"

static void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*b)
	{
		temp = *b;
		*b = temp->next;
		temp->next = NULL;
		ft_lstadd_front(a, temp);
	}
}

static void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*a)
	{
		temp = *a;
		*a = temp->next;
		temp->next = NULL;
		ft_lstadd_front(b, temp);
	}
}

void	push_checker(t_list **a, t_list **b, char type)
{
	if (type == 'a')
		pa(a, b);
	if (type == 'b')
		pb(a, b);
}
