/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamin <raamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:25:39 by raamin            #+#    #+#             */
/*   Updated: 2021/03/28 22:06:01 by raamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

char	*ft_strdup(char *src);
int		lookup(int size, char *dictionary[99][2], char *key);
int		ft_strcmp(char *s1, char *s2);
int		unites(char *key, int size, char *dictionary[99][2], int level);
int		dizaines(char *key, int size, char *dictionary[99][2], int level);
int		cents(char *key, int size, char *dictionary[99][2], int level);
int		ft_atoi(char *str);
char	*build(int q);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		getdictionary(char *filename, int *size, char *dictionary[99][2]);
int		freedictionary(int size, char *dictionary[99][2]);

#endif
