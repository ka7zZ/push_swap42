#include "instructions.h"

/*Description:

Shift down all elements of stack a by 1.
The last element becomes the first one

*/

void	rra(t_list **a)
{
	t_list	*ptr_next;
	t_list	*ptr_a;
	size_t	a_size;
	size_t	i;

	ptr_a = *a;
	i = 1;
	while (ptr_a)
	{
		ptr_next = ptr_a->next;
		if (i == a_size)
		{
			ft_lstadd_front(a, ft_lstnew(ptr_a->content));
			free(ptr_a->content);
			free(ptr_a);
		}
		i++;
		ptr_a = ptr_next;
	}
}