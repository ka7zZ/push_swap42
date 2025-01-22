#include "instructions.h"

/*Description:

Shift down all elements of stack b by 1.
The last element becomes the first one

*/

void	rrb(t_list **b)
{
	t_list	*ptr_next;
	t_list	*ptr_b;
	size_t	b_size;
	size_t	i;

	ptr_b = *b;
	i = 1;
	while (ptr_b)
	{
		ptr_next = ptr_b->next;
		if (i == b_size)
		{
			ft_lstadd_front(b, ft_lstnew(ptr_b->content));
			free(ptr_b->content);
			free(ptr_b);
		}
		i++;
		ptr_b = ptr_next;
	}
}
