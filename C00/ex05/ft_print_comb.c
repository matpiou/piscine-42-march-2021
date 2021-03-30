/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:57:56 by lpicques          #+#    #+#             */
/*   Updated: 2021/03/15 08:51:26 by lpicques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char centaine, char dizaine, char unite)
{
	write(1, &centaine, 1);
	write(1, &dizaine, 1);
	write(1, &unite, 1);
}

void	ft_putchar2(char c)
{
	write(1, &c, 1);
}

void	pluscourt(char centaine, char dizaine, char unite)
{
	ft_putchar(centaine, dizaine, unite);
	if (!(centaine == '7' && dizaine == '8' && unite == '9'))
	{
		ft_putchar2(',');
		ft_putchar2(' ');
	}
}

void	ft_print_comb(void)
{
	char centaine;
	char dizaine;
	char unite;

	centaine = '0';
	dizaine = '1';
	unite = '2';
	while (centaine <= '7')
	{
		while (dizaine <= '8')
		{
			while (unite <= '9')
			{
				pluscourt(centaine, dizaine, unite);
				unite = unite + 1;
			}
			dizaine = dizaine + 1;
			unite = dizaine + 1;
		}
		centaine = centaine + 1;
		dizaine = centaine + 1;
		unite = dizaine + 1;
	}
}
