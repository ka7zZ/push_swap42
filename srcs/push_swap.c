/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:20:09 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/24 19:51:22 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 1)
		return (ft_putstr_fd("Error\n", 1), 0);
	stack_a = NULL;
	stack_b = NULL;
	if (!check_av(&stack_a, argv))
		return (ft_lstclear(&stack_a, free), ft_putstr_fd("Error\n", 1), 0);
	if (check_sorted(stack_a))
		return (ft_lstclear(&stack_a, free), 0);
	if (ft_lstsize(stack_a) <= 5)
		return (sort_min(&stack_a, &stack_b), ft_lstclear(&stack_a, free), 0);
	set_index(stack_a, ft_lstsize(stack_a), 0);
	sort_large(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}
