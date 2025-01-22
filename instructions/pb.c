#include "instructions.h"

/*Description:

Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty

*/

void	pb(t_list **a, t_list **b)
{
    t_list	*temp;
	t_list	*buf;
	void	*moved;
	int		first;

	first = 0;
	temp = *a;
	while (temp)
	{
		buf = temp->next;
        if (!first)
        {
            moved = temp->content;
		    ft_lstadd_front(b, ft_lstnew(moved));
		    free(moved);
		    free(temp);
        }
        first++;
		temp = buf;
	}
}
