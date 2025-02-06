/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:52:02 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/06 19:33:39 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **a, t_list **b)
{    
	t_list *temp;

	if (*b)
	{
		temp = *b;
		*b = temp->next;
		temp->next = NULL;
		ft_lstadd_front(a, temp);
	}
}

void pb(t_list **a, t_list **b)
{
	t_list *temp;

	if (*a)
	{
		temp = *a;
		*a = temp->next;
		temp->next = NULL;
		ft_lstadd_front(b, temp);
	}
}
