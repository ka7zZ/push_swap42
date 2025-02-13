/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:40:05 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/13 17:22:30 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_error(t_list *stack_a)
{
	t_list	*ptr;
	t_list	*ptr2;
	int		n;
	int		cmp;

	ptr = stack_a;
	while (ptr)
	{
		ptr2 = ptr->next;
		if (!ft_strncmp((char *)ptr->content, "err", 3))
			return (0);
		n = ft_atoi((const char *)ptr->content);
		while (ptr2)
		{
			cmp = ft_atoi((const char *)ptr2->content);
			if (n == cmp)
				return (0);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
	return (1);
}

static int	split_case(t_list **stack_a, char *argv)
{
	char	**split_case;
	char	**temp;
	char	*buf;

	split_case = ft_split(argv, ' ');
	temp = split_case;
	while (*split_case)
	{
		buf = ft_itoa(ft_atoi(*split_case));
		if (buf != NULL)
			ft_lstadd_back(stack_a, ft_lstnew(buf));
		else
			ft_lstadd_back(stack_a, ft_lstnew(ft_strdup(NULL)));
		free(*split_case);
		split_case++;
	}
	free(temp);
	split_case = NULL;
	return (1);
}

int	check_av(t_stack **stack_a, char **argv)
{
	char	*buf;
	int		check_arg;
	int		i;
	
	i = 0;
	check_arg = 0;
	while (argv[++i])
	{
		if (i == 1 && ft_strchr(argv[i], ' '))
			split_case(stack_a, argv[i]);
		else if (i > 1 && ft_strchr(argv[i], ' '))
			return (0);
		else
		{
			buf = ft_itoa(ft_atoi(argv[i]));
			ft_lstadd_back(stack_a, ft_lstnew(buf));
		}
	}
	return (check_error(*stack_a));
}
