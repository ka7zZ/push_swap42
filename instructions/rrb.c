#include "instructions.h"

/*Description:

Shift down all elements of stack b by 1.
The last element becomes the first one

*/

void	rrb(t_list **b)
{
    t_list	*ptr_a;
	t_list	*ptr_buf;

    ptr_a = *b;
    while (ptr_a->next != NULL)
    {
        ptr_buf = ptr_a;
        ptr_a = ptr_a->next;
    }
    ptr_buf->next = NULL;
    ft_lstadd_front(b, ptr_a);
}
