/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:29:02 by lpicques          #+#    #+#             */
/*   Updated: 2021/03/16 11:29:11 by lpicques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int chaine;

	chaine = 0;
	while (str[chaine] != '\0')
	{
		ft_putchar(str[chaine]);
		chaine = chaine + 1;
	}
}
