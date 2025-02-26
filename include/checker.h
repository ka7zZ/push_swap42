/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:52:22 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/26 19:03:29 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

void	swap_checker(t_list **a, t_list **b, char type);
void	rrotate_checker(t_list **a, t_list **b, char type);
void	rotate_checker(t_list **a, t_list **b, char type);
void	push_checker(t_list **a, t_list **b, char type);
int		create_list(t_list **stack, char **args);
int		main(int ac, char **av);

#endif