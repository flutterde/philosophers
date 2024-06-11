/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:11:47 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/10 18:46:35 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	ft_isdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

bool	_validate(t_data *dt, int ac)
{
	if (dt->nbr > 200 || dt->time2die < 60 || dt->time2eat < 60
		|| dt->time2sleep < 60 || dt->nbr <= 0)
		return (false);
	if (ac == 6 && dt->eattimes <= 0)
		return (false);
	return (true);
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i] && ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - 48);
	if (str[i])
		return (0);
	return (res);
}
