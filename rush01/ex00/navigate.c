/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:46:56 by rcollas           #+#    #+#             */
/*   Updated: 2021/03/21 16:32:00 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		*get_col(int grid[4][4], int indx, int pov)
{
	int *col;
	int i;

	col = malloc(16);
	i = 0;
	if (pov != 0)
		while (pov >= 0)
		{
			col[i] = grid[indx % 4][pov];
			pov--;
			i++;
		}
	else
		while (pov <= 3)
		{
			col[i] = grid[indx][pov];
			i++;
			pov++;
		}
	return (col);
}

int		*get_row(int grid[4][4], int indx, int pov)
{
	int *row;
	int i;

	row = malloc(16);
	i = 0;
	if (pov != 0)
		while (pov >= 0)
		{
			row[i] = grid[pov][indx % 4];
			i++;
			pov--;
		}
	else
		while (pov <= 3)
		{
			row[i] = grid[pov][indx % 4];
			i++;
			pov++;
		}
	return (row);
}

int		*ft_return_tab(int grid[4][4], int indx)
{
	if (indx >= 0 && indx <= 3)
	{
		return (get_col(grid, indx, 0));
	}
	else if (indx >= 4 && indx <= 7)
	{
		return (get_col(grid, indx, 3));
	}
	else if (indx >= 8 && indx <= 11)
	{
		return (get_row(grid, indx, 0));
	}
	else
	{
		return (get_row(grid, indx, 3));
	}
}
