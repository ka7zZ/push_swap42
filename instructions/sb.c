#include "instructions.h"

/*Description:

Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

*/

void	sb(t_list **b)
{
    t_list *ptr_b;
    t_list *ptr_next;

    if (*b && (*b)->next)  // Ensure there are at least two nodes to swap
    {
        ptr_b = *b;
        ptr_next = ptr_b->next;

        // Swap the nodes
        ptr_b->next = ptr_next->next;  // Link first node to third node (or NULL if no third node)
        ptr_next->next = ptr_b;        // Link second node to first node

        // Update the head of the list to point to the second node
        *b = ptr_next;  // This is important to maintain the list head
    }
}