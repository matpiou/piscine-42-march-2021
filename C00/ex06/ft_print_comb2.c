/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:39:51 by lpicques          #+#    #+#             */
/*   Updated: 2021/03/15 09:25:00 by lpicques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int premier;
	int second;

	premier = 0;
	while (premier <= 98)
	{
		second = premier + 1;
		while (second <= 99)
		{
			ft_putchar('0' + (premier / 10));
			ft_putchar('0' + (premier % 10));
			ft_putchar(' ');
			ft_putchar('0' + (second / 10));
			ft_putchar('0' + (second % 10));
			if (!(premier == 98 && second == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			second = second + 1;
		}
		premier = premier + 1;
	}
}
