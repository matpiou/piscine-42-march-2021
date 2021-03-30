/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:10:26 by lpicques          #+#    #+#             */
/*   Updated: 2021/03/23 10:17:48 by lpicques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if ((power == 0 && nb == 0) || (power == 0))
		return (1);
	if (power < 0)
		return (0);
	return (ft_recursive_power(nb, power - 1) * nb);
}
