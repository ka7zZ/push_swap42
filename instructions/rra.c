#include "instructions.h"

/*Description:

Shift down all elements of stack a by 1.
The last element becomes the first one

*/

void	rra(t_list **a)
{
    t_list	*ptr_a;
	t_list	*ptr_buf;

    ptr_a = *a;
    while (ptr_a->next != NULL)
    {
        ptr_buf = ptr_a;
        ptr_a = ptr_a->next;
    }
    ptr_buf->next = NULL;
    ft_lstadd_front(a, ptr_a);
}