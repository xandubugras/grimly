/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:17:28 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/09 20:57:08 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/grimly.h"

t_input		*create_input()
{
	t_input *input;

	if ((input = malloc(sizeof(t_input))) == 0)
		return (0);
	input->full_input = 0;
	input->height = 0;
	input->width = 0;
	input->full = 0;
	input->empty = 0;
	input->path = 0;
	input->entrance = 0;
	input->exit = 0;
	input->ent_cord[0] = -1;
	input->ent_cord[1] = -1;
	input->num_exits = 0;
	return (input);
}

t_solver	*create_solver(t_input *input)
{
	t_solver	*solver;

	if ((solver = malloc(sizeof(t_solver))) == 0)
		return (0);
	solver->y = input->ent_cord[0];
	solver->x = input->ent_cord[1];
	solver->steps = 0;
	solver->curr_steps = 0;
	solver->loc = 0;
	solver->winning_map = 0;
	return (solver);
}
void	print_input(t_input *input)
{
	ft_printf("height: %d\n", input->height);
	ft_printf("width: %d\n", input->width);
	ft_printf("full: %c\n", input->full);
	ft_printf("empty: %c\n", input->empty);
	ft_printf("path: %c\n", input->path);
	ft_printf("entrance: %c\n", input->entrance);
	ft_printf("exit: %c\n", input->exit);
}

int		test_input(t_input *input)
{
	if (input->full == input->empty || input->full == input->path ||
			input->full == input->entrance || input->full == input->exit)
		return (1);
	if (input->empty == input->path ||
			input->empty == input->entrance || input->empty == input->exit)
		return (1);
	if (input->path == input->entrance || input->path == input->exit)
		return (1);
	if (input->entrance == input->exit)
		return (1);
	return (0);
}
