#include "instructions.h"

/*Description:

Shift up all elements of stack b by 1.
The first element becomes the last one.

*/

void	rb(t_list **b)
{
	t_list	*ptr;
	t_list	*next;

	if (*b && (*b)->next)
	{
		ptr = *b;
		next = ptr->next;
        ptr->next = NULL;
		*b = next;
        ft_lstadd_back(b, ptr);
	}
}
