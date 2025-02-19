/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:09:25 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/19 12:38:36 by aghergut         ###   ########.fr       */
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

// CHECK ARGUMENTS
int		check_av(t_list **stack_a, char **argv);
// INSTRUCTIONS
void	push(t_list **a, t_list **b, char type);
void	swap(t_list **a, t_list **b, char type);
void	rotate(t_list **a, t_list **b, char type);
void	rev_rotate(t_list **a, t_list **b, char type);
// UTILS
void	set_index(t_list *stack_a, int length, int idx);
int		check_sorted(t_list *stack_a);
int		check_bit(t_list **stack, int bits, int bit);
int		idx_pos(t_list **stack, int idx);
// SORT MIN
void	sort_min(t_list **stack_a, t_list **stack_b);
// MAIN PROGRAM
int		main(int argc, char **argv);
#endif