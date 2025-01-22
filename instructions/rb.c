#include "instructions.h"

/*Description:

Shift up all elements of stack b by 1.
The first element becomes the last one.

*/

void	rb(t_list **b)
{
    t_list	*ptr_b;

	ptr_b = *b;
	while (ptr_b)
	{
		ft_lstadd_back(b, ft_lstnew(ptr_b->content));
		free(ptr_b->content);
		free(ptr_b);
		break;
	}
}
