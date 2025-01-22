#include "instructions.h"

/*Description:

Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements

*/

void    sa(t_list **a)
{
    t_list *ptr_a;
    t_list *ptr_next;

    if (*a && (*a)->next)  // Ensure there are at least two nodes to swap
    {
        ptr_a = *a;
        ptr_next = ptr_a->next;

        // Swap the nodes
        ptr_a->next = ptr_next->next;  // Link first node to third node (or NULL if no third node)
        ptr_next->next = ptr_a;        // Link second node to first node

        // Update the head of the list to point to the second node
        *a = ptr_next;  // This is important to maintain the list head
    }
}