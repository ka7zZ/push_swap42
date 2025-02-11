/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:52:02 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/11 17:12:12 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	pa(t_list **a, t_list **b)
{    
	t_list *temp;

	if (*b)
	{
		temp = *b;
		*b = temp->next;
		temp->next = NULL;
		ft_lstadd_front(a, temp);
		write(1, "pa\n", 3);
	}
}

static void	pb(t_list **a, t_list **b)
{
	t_list *temp;

	if (*a)
	{
		temp = *a;
		*a = temp->next;
		temp->next = NULL;
		ft_lstadd_front(b, temp);
		write(1, "pb\n", 3);
	}
}

void push(t_list **a, t_list **b, char type)
{
	if (type == 'a')
		pa(a, b);
	if (type == 'b')
		pb(a, b);
}