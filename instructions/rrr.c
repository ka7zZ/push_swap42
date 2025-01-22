#include "instructions.h"

/*Description:

rra and rrb at the same time.

*/

void	rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
}