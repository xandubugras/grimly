/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:23:28 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/11 19:45:33 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/grimly.h"
#define EMPTY(x) x == input->empty
#define EXIT(x) x == input->exit
#define UP -1
#define RIGHT -2
#define LEFT -3
#define DOWN -4

void	draw_back(char **map, t_elem *el, t_input *input)
{
	char	dir;

	while (map[el->y][el->x] != input->entrance)
	{
		dir = map[el->y][el->x];
		input->steps++;
		map[el->y][el->x] = input->path;
		if (dir == DOWN)
			el->y--;
		else if (dir == UP)
			el->y++;
		else if (dir == LEFT)
			el->x++;
		else if (dir == RIGHT)
			el->x--;
	}
}

void	clean_map(char **map, t_input *input)
{
	int i;
	int j;

	i = 0;
	while (i < input->height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == DOWN || map[i][j] == UP ||
				map[i][j] == LEFT || map[i][j] == RIGHT)
				map[i][j] = input->empty;
			j++;
		}
		i++;
	}
}

int		solve_map(char **map, t_input *input)
{
	t_queue *q;
	t_elem	*curr;

	q = create_queue();
	enqueue(&q, input->ent_cord[1], input->ent_cord[0]);
	while (q->front)
	{
		curr = q->front;
		if (check_exit(map, curr, input))
		{
			draw_back(map, curr, input);
			clean_map(map, input);
			while (q->front)
				dequeue(&q);
			free(q);
			return (1);
		}
		handle_free(map, curr, &q, input);
		dequeue(&q);
	}
	free(q);
	return (0);
}

void	handle_free(char **map, t_elem *curr, t_queue **q, t_input *input)
{
	if (curr->y > 0 && (EMPTY(map[curr->y - 1][curr->x])))
	{
		map[curr->y - 1][curr->x] = UP;
		enqueue(q, curr->x, curr->y - 1);
	}
	if (curr->x > 0 && EMPTY(map[curr->y][curr->x - 1]))
	{
		map[curr->y][curr->x - 1] = LEFT;
		enqueue(q, curr->x - 1, curr->y);
	}
	if (curr->x < input->width - 1 && EMPTY(map[curr->y][curr->x + 1]))
	{
		map[curr->y][curr->x + 1] = RIGHT;
		enqueue(q, curr->x + 1, curr->y);
	}
	if (curr->y < input->height - 1 && EMPTY(map[curr->y + 1][curr->x]))
	{
		map[curr->y + 1][curr->x] = DOWN;
		enqueue(q, curr->x, curr->y + 1);
	}
}

int		check_exit(char **map, t_elem *s, t_input *input)
{
	if ((s->y > 0 && EXIT(map[s->y - 1][s->x])) ||
	(s->x > 0 && EXIT(map[s->y][s->x - 1])) ||
	(s->y < input->height - 1 && EXIT(map[s->y + 1][s->x])) ||
	(s->x < input->height - 1 && EXIT(map[s->y][s->x + 1])))
		return (1);
	return (0);
}
