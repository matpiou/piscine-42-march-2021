/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:02:22 by rcollas           #+#    #+#             */
/*   Updated: 2021/03/21 18:02:58 by lpicques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapper.h"
#include <unistd.h>

void	char_to_int(char *str, int tab[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 32)
	{
		tab[j] = str[i] - 48;
		i += 2;
		j++;
	}
}

void	putdigit(int digit)
{
	digit += 48;
	write(1, &digit, 1);
}

void	print_tab(int tab[4][4])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			putdigit(tab[i][j]);
			ft_putstr(" ");
			j++;
		}
		j = 0;
		ft_putstr("\n");
		i++;
	}
}

void	init_grid(int tab[4][4])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

int		main(int argc, char **argv)
{
	int input_values[16];
	int grid[4][4];
	int *ptr;

	if (argc != 2 || ft_input_check(argv[1]))
	{
		ft_putstr("Error\n");
		return (1);
	}
	ptr = ft_return_tab(grid, 2);
	init_grid(grid);
	char_to_int(argv[1], input_values);
	easy_solve(input_values, grid);
	print_tab(grid);
}
