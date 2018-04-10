/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:43:46 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/09 21:04:46 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/grimly.h"

int		main(int argc, char **argv)
{
	int		i;
	char	**grid;
	t_input	*input;
	t_solver *solver;

	if (argc == 1)
	{
		if ((grid = read_map(0, &input)) == 0)
			ft_printf("MAP ERROR\n");
		else
		{
			solver = create_solver(input);
			solve_map(grid, solver, input);
			free_grid(grid, input->height);
			if ((grid = solver->winning_map) == 0)
				ft_printf("MAP ERROR\n");
			else
			{
				ft_printf("%s\n", input->full_input);
				print_grid(grid, input->height);
				ft_printf("RESULT IN %d STEPS!\n", solver->curr_steps);
				free_grid(grid, input->height);
			}
			free(solver);
			free(input);
		}
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if ((grid = read_map(argv[i], &input)) == 0)
			{
				ft_printf("MAP ERROR\n");
			}
			else
			{
				solver = create_solver(input);
				solve_map(grid, solver, input);
				free_grid(grid, input->height);
				if ((grid = solver->winning_map) == 0)
					ft_printf("MAP ERROR\n");
				else
				{
					ft_printf("%s\n", input->full_input);
					print_grid(grid, input->height);
					ft_printf("RESULT IN %d STEPS!\n", solver->curr_steps);
					free_grid(grid, input->height);
				}
				free(solver);
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
