/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:45:02 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/11 17:23:31 by adubugra         ###   ########.fr       */
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
	int		steps;
	int		curr_steps;
	char	*loc;
	char	**winning_map;
}				t_solver;

typedef struct	s_elem
{
	struct s_elem	*next;
	struct s_elem	*prev;
	struct s_elem	*first;
	struct s_elem	*last;
	int				x;
	int				y;
}				t_elem;

typedef struct	s_queue
{
	struct s_elem	*rear;
	struct s_elem	*front;
}

char			**read_map(char *filename, t_input **inp);

char			**set_grid(int fd, t_input *input);

int				check_line(char *line, t_input *input, int h);

t_solver		*create_solver(t_input *input);

t_input			*set_input(t_input *input);

void			set_characters(t_input *input);

int				test_input(t_input *input);

t_input			*create_input();

void			print_grid(char **grid, int height);

void			free_grid(char **grid, int height);

void			print_input(t_input *input);

char			**copy_grid(char **map, t_input *input);

int				check_exit(char **map, t_solver *s, t_input *input);

void			solve_map(char **map, t_solver *s, t_input *input);

void			print_queue(t_elem *root, char order);

t_elem			*remove_queue(t_elem *el);

t_elem			*dequeue(t_elem **root);

t_elem			*enqueue(t_elem **last, t_elem *new);

t_elem			*create_elem(int x, int y);
#endif
