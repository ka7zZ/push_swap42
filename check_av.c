/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:40:05 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/12 12:44:14 by aghergut         ###   ########.fr       */
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

	split_case = ft_split(argv, ' ');
	temp = split_case;
	while (*split_case)
	{
		if (ft_atoi(*split_case) || ft_isdigit((*split_case)[0]))
			ft_lstadd_back(stack_a, ft_lstnew(ft_itoa(ft_atoi(*split_case))));
		else
			ft_lstadd_back(stack_a, ft_lstnew(ft_strdup("err")));
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
	int		j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		if (ft_strchr(argv[i], ' '))
			split_case(stack_a, argv[i]);
		else
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			while (ft_isdigit(argv[i][j]))
				j++;
			if (argv[i][j] != '\0')
				return (0);
			if (!stack_a)
				*stack_a = ft_lstnew(ft_itoa(ft_atoi(argv[i])));
			else
				ft_lstadd_back(stack_a, ft_lstnew(ft_itoa(ft_atoi(argv[i]))));
		}
	}
	return (check_error(*stack_a));
}
