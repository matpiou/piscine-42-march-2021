/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:48:20 by lpicques          #+#    #+#             */
/*   Updated: 2021/03/25 09:47:36 by lpicques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int result;

	i = 1;
	result = 1;
	if (nb == 0 || nb == 1)
		return (1);
	if ((nb < 0) || (nb > 12))
		return (0);
	while (i <= nb)
	{
		result = result * i;
		i++;
	}
	return (result);
}
