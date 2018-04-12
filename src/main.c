/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:43:46 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/11 13:15:02 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/grimly.h"

void	solve(char **grid, t_input *input)
{
	t_solver	*solver;

	solver = create_solver(input);
	solve_map(grid, solver, input);
	free_grid(grid, input->height);
	if ((grid = solver->winning_map) == 0)
		ft_putstr_fd("MAP ERROR\n", 2);
	else
	{
		ft_printf("%s\n", input->full_input);
		print_grid(grid, input->height);
		ft_printf("RESULT IN %d STEPS!\n", solver->curr_steps);
	}
	free_grid(grid, input->height);
	free(solver);
	free(input->full_input);
	free(input);
}

int		main(int argc, char **argv)
{
	int			i;
	char		**grid;
	t_input		*input;

	if (argc == 1)
	{
		if ((grid = read_map(0, &input)) == 0)
			ft_putstr_fd("MAP ERROR\n", 2);
		else
			solve(grid, input);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if ((grid = read_map(argv[i], &input)) == 0)
				ft_putstr_fd("MAP ERROR\n", 2);
			else
				solve(grid, input);
			i++;
		}
	}
}

void	free_grid(char **grid, int height)
{
	int i;

	i = 0;
	if (!grid)
		return ;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
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
