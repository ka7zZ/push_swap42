/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:09:25 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/17 17:58:08 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct Body {
	int n;
	int i;
}	t_body;

int		check_av(t_list **stack_a, char **argv);
int		main(int argc, char **argv);
void	push(t_list **a, t_list **b, char type);
void	swap(t_list **a, t_list **b, char type);
void	rotate(t_list **a, t_list **b, char type);
void	rev_rotate(t_list **a, t_list **b, char type);

#endif