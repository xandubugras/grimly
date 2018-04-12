/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:58:51 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/11 19:27:05 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/grimly.h"

t_elem	*create_elem(int x, int y)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	new->x = x;
	new->y = y;
	new->next = 0;
	new->prev = 0;
	return (new);
}

t_queue	*create_queue(void)
{
	t_queue	*new;

	new = malloc(sizeof(t_queue));
	new->rear = 0;
	new->front = 0;
	return (new);
}

t_elem	*enqueue(t_queue **queue, int x, int y)
{
	t_elem	*new;

	if (!queue || !(*queue))
		return (0);
	new = create_elem(x, y);
	if (!((*queue)->front))
		(*queue)->front = new;
	if (!((*queue)->rear))
		(*queue)->rear = new;
	else
	{
		(*queue)->rear->prev = new;
		new->next = (*queue)->rear;
		(*queue)->rear = new;
	}
	return (new);
}

t_elem	*dequeue(t_queue **queue)
{
	t_elem	*tmp;

	if (!queue || !(*queue))
		return (0);
	if ((*queue)->front->prev)
	{
		(*queue)->front->prev->next = 0;
		tmp = (*queue)->front;
		(*queue)->front = (*queue)->front->prev;
		if ((*queue)->front->prev == 0)
			(*queue)->rear = (*queue)->front;
		free(tmp);
	}
	else
	{
		free((*queue)->front);
		(*queue)->front = 0;
		(*queue)->rear = 0;
	}
	return ((*queue)->front);
}

void	print_queue(t_queue *queue, char order)
{
	t_elem	*buf;

	ft_printf("queue in order %c:\n", order);
	if (!queue || !(queue->rear))
	{
		ft_printf("empty queue\n", order);
		return ;
	}
	buf = order == 'R' ? queue->front : queue->rear;
	while (buf)
	{
		ft_printf("x: %d y: %d\n", buf->x, buf->y);
		buf = order == 'R' ? buf->prev : buf->next;
	}
}
