/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 09:50:33 by lpicques          #+#    #+#             */
/*   Updated: 2021/03/24 16:15:06 by lpicques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int result;

	result = 1;
	if ((power == 0) || (nb == 1))
		return (1);
	if (power < 0)
		return (0);
	while (power > 0)
	{
		result = nb * result;
		power--;
	}
	return (result);
}
