#include "instructions.h"

/*Description:

Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty

*/

void pb(t_list **a, t_list **b)
{
	t_list *temp;

	if (*a)
	{
		temp = *a;
		*a = temp->next;
		temp->next = NULL;
		ft_lstadd_front(b, temp);  // Add temp to the front of b
	}
}
