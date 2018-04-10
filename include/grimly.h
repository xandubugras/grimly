/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:45:02 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/09 20:54:59 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H
# include "../libft/libft.h"

typedef struct	s_input
{
	char	*full_input;
	int		height;
	int		width;
	char	full;
	char	empty;
	char	path;
	char	entrance;
	int		ent_cord[2];
	char	exit;
	char	num_exits;
}				t_input;

typedef struct	s_solver
{
	int		x;
	int		y;
	int 	steps;
	int		curr_steps;
	char	*loc;
	char	**winning_map;
}				t_solver;

char	**read_map(char *filename, t_input **inp);

char	**set_grid(int fd, t_input *input);

int		check_line(char *line, t_input *input, int h);

t_solver    *create_solver(t_input *input);

t_input	*set_input(char *input);

int		test_input(t_input *input);

t_input	*create_input();

void	print_grid(char **grid, int height);

void	free_grid(char **grid, int height);

void	print_input(t_input *input);

char	**copy_grid(char **map, t_input *input);

void	check_exit(char **map, t_solver *s, t_input *input);

void	solve_map(char **map, t_solver *s, t_input *input);
#endif
