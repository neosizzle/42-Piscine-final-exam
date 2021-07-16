#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;
	t_list	*curr;

	while (*begin_list && !cmp((*begin_list)->data, data_ref))
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp);
	}
	curr = *begin_list;
	while (curr && curr->next)
	{
		if (!cmp(curr->next->data, data_ref))
		{
			temp = curr->next;
			curr->next = temp->next;
			free(temp);
		}
		curr = curr->next;
	}
}
