/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:16:50 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/26 19:10:19 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/checker.h"

static void	action(t_list **stack_a, t_list **stack_b, char *instruction)
{
	if (!ft_strncmp(instruction, "sa", 2))
		push_checker(stack_a, stack_b, 'a');
	if (!ft_strncmp(instruction, "sb", 2))
		push_checker(stack_a, stack_b, 'b');
	if (!ft_strncmp(instruction, "pa", 2))
		push_checker(stack_a, stack_b, 'a');
	if (!ft_strncmp(instruction, "pb", 2))
		push_checker(stack_a, stack_b, 'b');
	if (!ft_strncmp(instruction, "ra", 2))
		rotate_checker(stack_a, stack_b, 'a');
	if (!ft_strncmp(instruction, "rb", 2))
		rotate_checker(stack_a, stack_b, 'b');
	if (!ft_strncmp(instruction, "rra", 3))
		rrotate_checker(stack_a, stack_b, 'a');
	if (!ft_strncmp(instruction, "rrb", 3))
		rrotate_checker(stack_a, stack_b, 'b');
}

static int	check_sorted(t_list **stack_a)
{
	t_list	*ptr;
	int		x;
	int		y;
	
	ptr = *stack_a;
	while (ptr->next)
	{
		x = ft_atoi((char *)ptr->content);
		y = ft_atoi((char *)ptr->next->content);
		if (x > y)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*res;
	if (ac > 2 || !(*av))
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!create_list(&stack_a, av))
		return (ft_lstclear(&stack_a, free), ft_putstr_fd("Error\n", 1), 0);
	res = get_next_line(0);
	if (!res)
		return (0);
	while (res)
	{
		action(&stack_a, &stack_b, res);
		free(res);
		res = get_next_line(0);
	}
	if (res)
		free(res);
	if (check_sorted(&stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
