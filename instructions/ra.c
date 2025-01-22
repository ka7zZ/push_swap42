#include "instructions.h"

/*Description:

Shift up all elements of stack a by 1.
The first element becomes the last one

*/

void	ra(t_list **a)
{
	t_list	*ptr;
	t_list	*next;

	if (*a)
	{
		ptr = *a;
		next = ptr->next;
		ptr->next = NULL;
		*a = next;
		ft_lstadd_back(a, ptr);
	}
}
/*
	t_list	*ptr_a;

	ptr_a = a;
	while (ptr_a)
	{
		ft_lstadd_back(&a, ft_lstnew(ptr_a->content));
		free(ptr_a->content);
		free(ptr_a);
		break;
	}
	*/