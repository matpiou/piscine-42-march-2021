/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:10:18 by tihertel          #+#    #+#             */
/*   Updated: 2021/03/14 11:13:43 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_row_col(int row, int col, int x, int y)
{
	if (row == 0 || row == (y - 1))
	{
		if (col == 0 || col == (x - 1))
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else
	{
		if (col == 0 || col == x - 1)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int row;
	int col;

	if (x <= 0 || y <= 0)
		return ;
	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			ft_row_col(row, col, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
