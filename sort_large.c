/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:22:53 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/24 18:41:00 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	check_init(t_list **stack_a, t_list **stack_b, int bits)
{
	t_body	*body_a;
	int		ret;
	int		times;

	times = 0;
	body_a = (t_body *)(*stack_a)->content;
	while (((body_a->i >> bits) & 1) == 0)
	{
		push(stack_a, stack_b, 'b');
		body_a = (t_body *)(*stack_a)->content;
		times++;
	}
	ft_printf("times of push -->> %d\n", times);
	ret = ft_lstsize(*stack_a);
	return (ret);
}

static void	do_the_move(t_list **stack_a,t_list **stack_b, int type)
{
	if (type)
		rotate(stack_a, stack_b, 'a');
	else
		rev_rotate(stack_a, stack_b, 'a');
}	

static int	more_moves(t_list *stack, int bits)
{
	t_list	*ptr;
	t_body	*body;
	int		size;
	int		r;
	int		rr;
	int		i;
	
	ptr = stack;
	size = ft_lstsize(stack);
	i = 0;
	r = 0;
	rr = 0;
	while (ptr)
	{
		i++;
		body = ptr->content;
		if (((body->i >> bits) & 1) == 1 && i <= (size / 2))
			r++;
		else if (((body->i >> bits) & 1) == 1 && i > (size / 2))
			rr++;
		ptr = ptr->next;
	}
	ft_printf("r -->>  %d\nrr -->> %d\n", r, rr);
	if (r >= rr)
		return (1);
	return (0);
}

static int	get_max(t_list *stack)
{
	t_list	*ptr;
	t_body	*body_ptr;
	int		res;

	ptr = stack;
	res = 0;
	while (ptr)
	{
		body_ptr = (t_body *)ptr->content;
		if (body_ptr->i > res)
			res = body_ptr->i;
		ptr = ptr->next;
	}
	return (res);
}

static unsigned int	count_bits(unsigned int n) 
{ 
   unsigned int count = 0;
   
   while (n) 
   { 
		count++; 
		n >>= 1; 
	} 
	return (count); 
}


static void	see_bits(t_list *stack)
{
	t_list	*ptr;
	t_body	*b;
	int		max_nbits;
	int		actual_bits;
	int		buf;

	ptr = stack;
	max_nbits = count_bits(get_max(ptr));
	ft_printf("max nbits-->> %d\n", max_nbits);
	while (ptr)
	{
		b = ptr->content;
		actual_bits = count_bits(b->i);
		buf = actual_bits;
		while (actual_bits++ < max_nbits)
			write(1, "0", 1);
		while (buf--)
			ft_printf("%c", (char)(((b->i >> buf) & 1) + '0'));
		ft_putstr_fd("\n", 1);
		ptr = ptr->next;
	}
}

void	sort_large(t_list **stack_a, t_list **stack_b)
{
	t_body	*body_a;
	int		bits;
	int		fin;
	int		size;
	int		type;
	int		orig_size;
	int		times;

	orig_size = ft_lstsize(*stack_a);
	bits = -1;
	fin = count_bits(get_max(*stack_a));
	ft_printf("max number of bits -->> %d\n", fin);
	times = 0;
	while (++bits < fin)
	{
		see_bits(*stack_a);
		times++;
		size = check_init(stack_a, stack_b, bits);
		type = more_moves(*stack_a, bits);
		ft_printf("remaining size of init - %d\t%d - total size\ntype -->> %d (1r-0rr)\n", size, orig_size, type);
		ft_printf("[BEFORE %d WHILE]]first node -->> %d\n", times, ((t_body *)(*stack_a)->content)->i);
		while (size)
		{
			body_a = (t_body *)(*stack_a)->content;
			if (((body_a->i >> bits) & 1) == 0)
				push(stack_a, stack_b, 'b');
			else
				do_the_move(stack_a, stack_b, type);
			size--;	
		}
		ft_printf("[AFTER %d WHILE]]first node -->> %d\n", times, ((t_body *)(*stack_a)->content)->i);
		while (*stack_b)
			push(stack_a, stack_b, 'a');
		ft_putstr_fd("the list after push from b to a\n", 1);
		see_bits(*stack_a);
	}
}

/*
BITS	1	2	4	8	16	32	64	128		representation
5		1	0	1							101
7		1	1	1							111	
8		0	0	0	1						1000
6		0	1	1							110
4		0	0	1							100
3		1	1								11	
2		0	1								10
9		1	0	0	1						1001
1		1									1

check init (check if the first nodes contains in the bits place 0 to be pushed to b -->> 0)

last bit first time ->	ra 		ra pb pb pb 	ra pb	ra 		ra 		   1000
						111		11				1001	1		101		   0110	
						11		1001			1		101		111		   0100	
						1001	1				101		111		11		   0010
						1		101				111		11		1001	   0101	
						101		111				11		1001	1		   0111
 												                           0011		
																		   1001
																		   0001

last bit second time -> ra	pb	ra	pb	ra	ra	pb	pb						1000				
						10		111		11	110								0100
						111		11		110	10								0101
                        11		110		10	111								1001
						110		10		111	11								0001
																			0110
																			0010
																			0111
																			0011

last bit third time -> pb	ra	ra	pb	pb	ra	pb	ra	pb
*/