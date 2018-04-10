/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:05:19 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/09 21:10:44 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/grimly.h"

char	**read_map(char *filename, t_input **inp)
{
	int		fd;
	char	*input;
	char	**grid;
	t_input	*info;

	if (!filename)
		fd = 0;
	else if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	get_next_line(fd, &input);
	ft_printf("input: %s\n", input);
	if ((info = set_input(input)) == 0)
		return (0);
	free(input);
	if (!(grid = set_grid(fd, info)))
		return (0);
	*inp = info;
	return (grid);
}

char	**set_grid(int fd, t_input *input)
{
	char	*line;
	char	**grid;
	int		i;

	grid = malloc(sizeof(char *) * input->height);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i >= input->height)
			return (0);
		if (ft_strlen(line) != (size_t)input->width)
			return (0);
		if (check_line(line, input, i))
			return (0);
		grid[i] = line;
		i++;
	}
	if (input->ent_cord[0] == -1 || !input->num_exits)
		return (0);
	if (ft_strchr(grid[0], input->empty) ||
		ft_strchr(grid[input->height - 1], input->empty))
		return (0);
	return (grid);
}

int		check_line(char *line, t_input *input, int h)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != input->full && line[i] != input->empty &&
				line[i] != input->entrance && line[i] != input->exit)
			return (1);
		if (line[i] == input->entrance)
		{
			if (input->ent_cord[0] != -1)
				return (1);
			input->ent_cord[0] = h;
			input->ent_cord[1] = i;
			if (h != 0 && i != 0 && h != input->height - 1 && i != input->width - 1)
				return (1);
		}
		if (line[i] == input->exit)
			input->num_exits++;
		i++;
	}
	if (line[0] == input->empty || line[input->width - 1] == input->empty)
		return (1);
	return (0);
}

t_input	*set_input(char *input)
{
	t_input	*info;

	if (!(info = create_input()))
		return (0);
	if ((info->height = ft_atoi(input)) == 0)
		return (0);
	if ((input = ft_strchr(input, 'x')) == 0)
		return (0);
	input++;
	if ((info->width = ft_atoi(input)) == 0)
		return (0);
	while (ft_isdigit(*input))
		input++;
	if (ft_strlen(input) != 5)
		return (0);
	info->full = *input;
	input++;
	info->empty = *input;
	input++;
	info->path = *input;
	input++;
	info->entrance = *input;
	input++;
	info->exit = *input;
	if (test_input(info))
		return (0);
	return (info);
}

void	print_grid(char **grid, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		ft_printf("%s\n", grid[i]);
		i++;
	}
}
