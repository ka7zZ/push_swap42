/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:40:39 by aghergut          #+#    #+#             */
/*   Updated: 2026/02/19 12:07:09 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static int	initial_check(char *nbr)
{
	char	*ptr;

	if (!(*nbr))
		return (0);
	ptr = nbr;
	if (ptr && *ptr == '-')
		ptr++;
	while (*ptr)
	{
		if (!ft_isdigit(*ptr))
			return (0);
		ptr++;
	}
	return (1);
}

static int	add(t_list **stack_a, char *nbr)
{
	long	check;

	check = 0;
	if (initial_check(nbr))
		check = ft_atoi(nbr);
	else
		return (0);
	if (check >= INT_MIN && check <= INT_MAX)
		ft_lstadd_back(stack_a, ft_lstnew(ft_strdup(nbr)));
	else
		return (0);
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
		if (!add(stack_a, *split_case))
			return (0);
		free(*split_case);
		split_case++;
	}
	free(temp);
	split_case = NULL;
	return (1);
}

int	create_list(t_list **stack, char **args)
{
	int	i;

	i = 0;
	while (args[++i])
	{
		if (i == 1 && ft_strchr(args[i], ' '))
		{
			if (args[2] || !split_case(stack, args[i]))
				return (0);
			return (1);
		}
		if (!add(stack, args[i]))
			return (0);
	}
	return (1);
}
