/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:16:50 by aghergut          #+#    #+#             */
/*   Updated: 2026/02/19 11:57:29 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static void	action(t_list **stack_a, t_list **stack_b, char *instruction)
{
	if (!ft_strncmp(instruction, "rrr\n", 4))
		rrotate_checker(stack_a, stack_b, 'r');
	else if (!ft_strncmp(instruction, "rra\n", 4))
		rrotate_checker(stack_a, stack_b, 'a');
	else if (!ft_strncmp(instruction, "rrb\n", 4))
		rrotate_checker(stack_a, stack_b, 'b');
	else if (!ft_strncmp(instruction, "ss\n", 3))
		swap_checker(stack_a, stack_b, 's');
	else if (!ft_strncmp(instruction, "sa\n", 3))
		swap_checker(stack_a, stack_b, 'a');
	else if (!ft_strncmp(instruction, "sb\n", 3))
		swap_checker(stack_a, stack_b, 'b');
	else if (!ft_strncmp(instruction, "rr\n", 3))
		rotate_checker(stack_a, stack_b, 'r');
	else if (!ft_strncmp(instruction, "ra\n", 3))
		rotate_checker(stack_a, stack_b, 'a');
	else if (!ft_strncmp(instruction, "rb\n", 3))
		rotate_checker(stack_a, stack_b, 'b');
	else if (!ft_strncmp(instruction, "pa\n", 3))
		push_checker(stack_a, stack_b, 'a');
	else if (!ft_strncmp(instruction, "pb\n", 3))
		push_checker(stack_a, stack_b, 'b');
}

static int	check_sorted(t_list **stack_a)
{
	t_list	*ptr;
	t_list	*buf;
	int		x;
	int		y;

	ptr = *stack_a;
	while (ptr->next)
	{
		buf = ptr->next;
		x = ft_atoi((char *)ptr->content);
		y = ft_atoi((char *)buf->content);
		if (x > y)
			return (0);
		ptr = buf;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*res;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!create_list(&stack_a, av))
		return (ft_lstclear(&stack_a, free), ft_putstr_fd("Error\n", 1), 0);
	res = get_next_line(0);
	while (res)
	{
		action(&stack_a, &stack_b, res);
		free(res);
		res = get_next_line(0);
	}
	if (stack_b || !check_sorted(&stack_a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
