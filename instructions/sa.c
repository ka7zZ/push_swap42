#include "instructions.h"

/*Description:

Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements

*/

void    sa(t_list **a)
{
    t_list *ptr_a;
    t_list *ptr_next;

    if (*a && (*a)->next)
    {
        ptr_a = *a;
        ptr_next = ptr_a->next;
        ptr_a->next = ptr_next->next;
        ptr_next->next = ptr_a;
        *a = ptr_next;
    }
}