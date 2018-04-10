/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:23:28 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/09 21:13:42 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/grimly.h"
#define EMPTY(x) x == input->empty
#define EXIT(x) x == input->exit

/*
**tries to move up>right>left>down. If there is a vacancy, fills the map and 
**recursively calls to that spot. 
**if it finds a exit, checks if it is better
**than the current and if true,  saves it. keeps going looking for
**better solutions until it exhausts all possibilities.
**stops if curr number of steps is greater than the solution already found.
*/

void	solve_map(char **map, t_solver *s, t_input *input)
{
	if (s->curr_steps > 0 && s->steps > s->curr_steps)
		return ;
	check_exit(map, s, input);
	if (s->y > 0 && (EMPTY(map[s->y - 1][s->x])))
	{
		s->y--;
		map[s->y][s->x] = input->path;
		s->steps++;
		solve_map(map, s, input);
		s->steps--;
		map[s->y][s->x] = input->empty;
		s->y++;
	}
	if (s->x > 0 && EMPTY(map[s->y][s->x - 1]))
	{
		s->x--;
		map[s->y][s->x] = input->path;
		s->steps++;
		solve_map(map, s, input);
		map[s->y][s->x] = input->empty;
		s->steps--;
		s->x++;
	}
	if (s->x < input->width - 1 && EMPTY(map[s->y][s->x + 1]))
	{
		s->x++;
		map[s->y][s->x] = input->path;
		s->steps++;
		solve_map(map, s, input);
		s->steps--;
		map[s->y][s->x] = input->empty;
		s->x--;
	}
	if (s->y < input->height - 1 && EMPTY(map[s->y + 1][s->x]))
	{
		s->y++;
		map[s->y][s->x] = input->path;
		s->steps++;
		solve_map(map, s, input);
		s->steps--;
		map[s->y][s->x] = input->empty;
		s->y--;
	}
}

void	check_exit(char **map, t_solver *s, t_input *input)
{
	if ((s->y > 0 && EXIT(map[s->y - 1][s->x])) ||
	(s->x > 0 && EXIT(map[s->y][s->x - 1])) ||
	(s->y < input->height - 1 && EXIT(map[s->y +1][s->x])) ||
	(s->x < input->height - 1 && EXIT(map[s->y][s->x + 1])))
	{
		if (s->steps < s->curr_steps || s->curr_steps == 0)
		{
			s->curr_steps = s->steps;
			if (s->winning_map)
				free_grid(s->winning_map, input->height);
			s->winning_map = copy_grid(map, input);
		}
	}
}


char	**copy_grid(char **map, t_input *input)
{
	char	**grid;
	int		i;

	grid = malloc(sizeof(char *) * input->height);
	i = 0;
	while (i < input->height)
	{
		grid[i] = ft_strdup(map[i]);
		i++;
	}
	return (grid);
}
	

























