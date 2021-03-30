/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 07:40:48 by rcollas           #+#    #+#             */
/*   Updated: 2021/03/21 16:31:47 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		where_am_i(int indx)
{
	if (indx >= 0 && indx <= 3)
		return (0);
	if (indx >= 4 && indx <= 7)
		return (3);
	if (indx >= 8 && indx <= 11)
		return (0);
	if (indx >= 12 && indx <= 15)
		return (3);
	return (1);
}

void	solve_4(int grid[4][4], int indx)
{
	int i;
	int pov;

	i = 0;
	pov = where_am_i(indx);
	if (pov == 3)
	{
		while (i++ < 4)
		{
			if (indx < 8)
				grid[pov--][indx % 4] = i;
			else
				grid[indx % 4][pov--] = i;
		}
	}
	if (pov == 0)
	{
		while (i++ < 4)
		{
			if (indx < 8)
				grid[pov++][indx % 4] = i;
			else
				grid[indx % 4][pov++] = i;
		}
	}
}

void	solve_1(int grid[4][4], int indx)
{
	int pov;

	pov = where_am_i(indx);
	if (pov == 3)
	{
		if (indx < 8)
			grid[pov][indx % 4] = 4;
		else
			grid[indx % 4][pov] = 4;
	}
	if (pov == 0)
	{
		if (indx < 8)
			grid[pov][indx % 4] = 4;
		else
			grid[indx % 4][pov] = 4;
	}
}

void	easy_solve(int input[16], int grid[4][4])
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (input[i] == 4)
			solve_4(grid, i);
		if (input[i] == 1)
			solve_1(grid, i);
		i++;
	}
}
