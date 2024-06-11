/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:57:39 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/06 17:49:35 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	is_death(t_data *data)
{
	bool	res;

	pthread_mutex_lock(&data->checking);
	res = data->death;
	pthread_mutex_unlock(&data->checking);
	return (res);
}

bool	check_end(t_data *data)
{
	bool	res;

	pthread_mutex_lock(&data->m_ends);
	if (data->ends == data->nbr)
		res = true;
	else
		res = false;
	pthread_mutex_unlock(&data->m_ends);
	return (res);
}

void	set_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_ends);
	philo->data->ends++;
	philo->end = 1;
	pthread_mutex_unlock(&philo->data->m_ends);
}

void	set_death(t_data *data)
{
	pthread_mutex_lock(&data->checking);
	data->death = true;
	pthread_mutex_unlock(&data->checking);
}

bool	is_end_simulation(t_philo *ph, int *i, int *eatnbr)
{
	if (*eatnbr != -1)
		(*i)++;
	else
		return (false);
	if (*i == *eatnbr)
		return (set_end(ph), true);
	return (false);
}
