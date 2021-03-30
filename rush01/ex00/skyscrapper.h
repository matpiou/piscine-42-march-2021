/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:32:11 by lpicques          #+#    #+#             */
/*   Updated: 2021/03/21 18:04:09 by lpicques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPPER_H
# define SKYSCRAPPER_H

int		*get_col(int grid[4][4], int indx, int pov);
int		*get_row(int grid[4][4], int indx, int pov);
int		*ft_return_tab(int grid[4][4], int indx);
void	easy_solve(int input[16], int grid[4][4]);
void	ft_putstr(char *str);
int		ft_input_check(char *str);

#endif
