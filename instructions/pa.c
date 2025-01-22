#include "instructions.h"

/*Description:

Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

*/

void	pa(t_list **a, t_list **b)
{    
	t_list	*temp;
	t_list	*buf;
	void	*moved;
	int		first;

	first = 0;
	temp = *b;
	if (*b && ft_lstsize(*b) > 1)
    while (temp)
	{
		buf = temp->next;
        if (!first)
        {
            moved = temp->content;
		    ft_lstadd_front(a, ft_lstnew(moved));
		    free(moved);
		    free(temp);
        }
        first++;
		temp = buf;
	}
}