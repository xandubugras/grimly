/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:59:30 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/11 13:08:14 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/grimly.h"
#include "../libft/libft.h"

/*take root
check if any 4 adjacent are exits, if it is, edit map backtracking and break
add the 4 adjacent to the root
mark them as proper numbers 
add their coords to the queue
make current equal to next one on the queue*/

void	print_queue(t_elem *root, char order);

t_elem	*remove_queue(t_elem *el);

t_elem	*create_elem(int x, int y)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	new->x = x;
	new->y = y;
	new->next = 0;
	new->prev = 0;
	new->first = 0;
	new->last = 0;
	return (new);
}

t_elem	*enqueue(t_elem **last, t_elem *new)
{
	t_elem	*tmp;

	if (!last || !new || new->first)
		return (0);
	if (*last && (*last)->last)
	{
		ft_swap(&((*last)->x), &(new->x));
		ft_swap(&((*last)->y), &(new->y));
		tmp = (*last)->next;
		if (tmp)
			tmp->prev = new;
		(*last)->next = new;
		new->next = tmp;
		new->prev = *last;
		new->first = (*last)->first;
		new->last = (*last);
		if (*last == (*last)->first)
		{
			(*last)->first = new;
			new->first = new;
		}
	}
	else
	{
		*last = new;
		(*last)->first = new;
		new->last = new;
		new->first = new;
	}
	return (*last);
}

t_elem	*dequeue(t_elem **root)
{
	t_elem	*tmp;
	t_elem	*first;

	if (!root || !(*root))
		return (0);
	first = (*root) ? (*root)->first : 0;
	if (first && first->prev && first->prev != first->last)
	{
		ft_swap(&(first->x), &(first->prev->x));
		ft_swap(&(first->y), &(first->prev->y));
		tmp = first->prev;
		first->prev->prev->next = first;
		first->prev = first->prev->prev;
		free(tmp);
	}
	else if (first && first->prev && first->prev == first->last) //case it is the last one
	{
		(*root)->first = first->last;
		(*root)->next = 0;
		free(first);
	}
	else if (first)
		*root = 0;
	return (first);
}

t_elem	*remove_queue(t_elem *el)
{
	if (!el)
		return (0);
	if (el == el->first)
	{
		enqueue(&(el->last), create_elem(el->x, el->y));
		dequeue(&el);
		return (0);
	}
	if (el == el->last)
		return (0);
	if (el->prev)
		el->prev->next = el->next;
	if (el->next)
		el->next->prev = el->prev;
	el->next = 0;
	el->prev = 0;
	el->first = 0;
	el->last = 0;
	return (el);
}

void	print_queue(t_elem *root, char order)
{
	t_elem *buf;

	ft_printf("queue in order %c:\n", order);
	if (!root)
	{
		ft_printf("empty queue\n", order);
		return ;
	}
	buf = order == 'R' ? root->first : root->last;
	while (buf)
	{
		ft_printf("x: %d y: %d\n", buf->x, buf->y);
		buf = order == 'R' ? buf->prev : buf->next;
	}
}
