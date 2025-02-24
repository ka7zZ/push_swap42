/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:29:22 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/24 19:39:44 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list *stack_a, int length, int idx)
{
	t_list	*ptr;
	t_list	*buf;
	t_body	*bcompare;
	t_body	*bbuf;

	while (length--)
	{
		ptr = stack_a;
		while (ptr && ((t_body *)ptr->content)->i)
			ptr = ptr->next;
		buf = ptr;
		if (buf)
			bbuf = buf->content;
		while (ptr->next)
		{
			bcompare = ptr->next->content;
			if (!bcompare->i && bbuf->n > bcompare->n)
			{
				buf = ptr->next;
				bbuf = buf->content;
			}
			ptr = ptr->next;
		}
		bbuf->i = ++idx;
	}
}

int	check_sorted(t_list *stack_a)
{
	t_list	*ptr;
	t_list	*temp;
	t_body	*body_ptr;
	t_body	*body_temp;
	int		check;

	check = 1;
	ptr = stack_a;
	while (ptr->next)
	{
		if (ptr->content)
			body_ptr = (t_body *)ptr->content;
		temp = ptr->next;
		if (temp && temp->content)
			body_temp = (t_body *)temp->content;
		if (body_ptr && body_temp && body_ptr->n > body_temp->n)
			check = 0;
		ptr = ptr->next;
	}
	return (check);
}

int	check_bit(t_list **stack, int bits, int bit)
{
	t_list	*ptr;
	t_body	*body_ptr;
	int		check;

	check = 0;
	ptr = *stack;
	while (ptr)
	{
		body_ptr = (t_body *)ptr->content;
		if (((body_ptr->i >> bits) & 1) == bit)
			check = 1;
		ptr = ptr->next;
	}
	return (check);
}

int	idx_pos(t_list **stack, int idx)
{
	t_list	*ptr;
	t_body	*body_ptr;
	int		pos;
	int		check;

	pos = 0;
	ptr = *stack;
	check = 0;
	while (ptr)
	{
		++pos;
		body_ptr = ptr->content;
		if (body_ptr->i == idx)
			check = pos;
		ptr = ptr->next;
	}
	return (check);
}
