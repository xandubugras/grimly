/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:45:02 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/09 16:39:45 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H
# include "../libft/libft.h"

typedef struct	s_input
{
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

char	**read_map(char *filename, t_input **inp);

char	**set_grid(int fd, t_input *input);

int		check_line(char *line, t_input *input, int h);

t_input	*set_input(char *input);

int		test_input(t_input *input);

t_input	*create_input();

void	print_grid(char **grid, int height);

void	free_grid(char **grid, int height);

void	print_input(t_input *input);
#endif
