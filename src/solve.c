/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:23:28 by adubugra          #+#    #+#             */
/*   Updated: 2018/04/09 17:13:47 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/grimly.h"

char	**solve_map(char **map, t_input *input, int steps)
{
	char	*loc;
	int		i;
	int		j;

	i = input->ent_cord[0];
	j = input->ent_cord[1];
	loc = &map[i][j];
	  
