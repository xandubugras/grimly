/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:45:02 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/11 19:28:09 by adubugra         ###   ########.fr       */
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
	char	**map;
	int		steps;
}				t_input;

typedef struct	s_elem
{
	struct s_elem	*next;
	struct s_elem	*prev;
	int				x;
	int				y;
}				t_elem;

typedef struct	s_queue
{
	struct s_elem	*rear;
	struct s_elem	*front;
}				t_queue;
/*
**-------------------------READ----------------------
*/
char			**read_map(char *filename, t_input **inp);

char			**set_grid(int fd, t_input *input);

int				check_line(char *line, t_input *input, int h);

t_input			*set_input(t_input *input);

void			set_characters(t_input *input);
/*
**-------------------------INPUT----------------------
*/
int				test_input(t_input *input);

t_input			*create_input();

void			print_input(t_input *input);
/*
**-------------------------DISPLAYING(main.c)-----------
*/
void			print_grid(char **grid, int height);

void			free_grid(char **grid, int height);
/*
**-------------------------SOVLING----------------------
*/
int				solve_map(char **map, t_input *input);

int				check_exit(char **map, t_elem *s, t_input *input);

void			handle_free(char **map, t_elem *curr, t_queue **q,
							t_input *input);

void			clean_map(char **map, t_input *input);

void			draw_back(char **map, t_elem *el, t_input *input);
/*
**-------------------------QUEUES----------------------
*/
t_elem			*create_elem(int x, int y);

t_queue			*create_queue(void);

void			print_queue(t_queue *queue, char order);

t_elem			*dequeue(t_queue **queue);

t_elem			*enqueue(t_queue **queue, int x, int y);
#endif
