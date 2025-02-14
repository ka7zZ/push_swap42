/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:40:05 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/14 12:26:43 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_body(t_list **stack_a, char *nbr)
{
	t_body  *b;
	long	check;

	check = ft_atoi(nbr);
	if (check >= INT_MIN && check <= INT_MAX)
	{
		b = (t_body *)malloc(sizeof(t_body));
		b->number = check;
		b->idx = 0;
		ft_lstadd_back(stack_a, ft_lstnew(b));
		return (1);
	}
	return (0);
}

static int	check_error(t_list *stack_a)
{
	t_list	*ptr1;
	t_list	*ptr2;
	t_body	*b1;
	t_body	*b2;

	ptr1 = stack_a;
	while (ptr1)
	{
		ptr2 = ptr1->next;
		b1 = ptr1->content;
		while (ptr2)
		{
			b2 = ptr2->content;
			if (b1->number == b2->number)
				return (0);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return (1);
}

static int	split_case(t_list **stack_a, char *argv)
{
	char	**split_case;
	char	**temp;

	split_case = ft_split(argv, ' ');
	temp = split_case;
	while (*split_case)
	{
		if (!add_body(stack_a, *split_case))
			return (0);
		free(*split_case);
		split_case++;
	}
	free(temp);
	split_case = NULL;
	return (1);
}

int	check_av(t_list **stack_a, char **argv)
{
	int		i;
	
	i = 0;
	while (argv[++i])
	{
		if (i == 1 && ft_strchr(argv[i], ' '))
		{
			if (argv[2] || !split_case(stack_a, argv[i]))
				return (0);
			return (check_error(*stack_a));
		}
		if (!add_body(stack_a, argv[i]))
			return (0);
	}
	return (check_error(*stack_a));
}
