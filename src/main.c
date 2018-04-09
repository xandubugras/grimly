/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:43:46 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/09 16:00:59 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/grimly.h"

int		main(int argc, char **argv)
{
	int		i;
	char	**grid;
	t_input	*input;

	if (argc == 1)
	{
		if ((grid = read_map(0, &input)) == 0)
			ft_printf("MAP ERROR\n");
		else
			ft_printf("HI\n");
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if ((grid = read_map(argv[i], &input)) == 0)
				ft_printf("MAP ERROR\n");
			else
			{
			//	grid = solve_map(grid);
				print_grid(grid, input->height);
				free_grid(grid, input->height);
				free(input);
			}
			i++;
		}
	}
	return (0);
}

void	free_grid(char **grid, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
}
