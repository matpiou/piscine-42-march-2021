/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:50:42 by lpicques          #+#    #+#             */
/*   Updated: 2021/03/26 14:50:43 by lpicques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int		ft_error(char *str)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(str) < 2)
		return (1);
	while (str[i])
	{
		j = 0;
		if (str[i] == '-' || str[i] == '+')
			return (1);
		while (str[j] && j != i)
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			len;
	long int	nb;

	nb = nbr;
	if (ft_error(base))
		return ;
	len = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb / len > 0)
		ft_putnbr_base(nb / len, base);
	ft_putchar(base[nb % len]);
}
