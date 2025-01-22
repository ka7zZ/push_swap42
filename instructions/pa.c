#include "instructions.h"

/*Description:

Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

*/

void	pa(t_list **a, t_list **b)
{    
	t_list *temp;

	if (*b)
	{
		temp = *b;
		*b = temp->next;
		temp->next = NULL;
		ft_lstadd_front(a, temp);
	}
}