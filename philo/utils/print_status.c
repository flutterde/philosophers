/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:53:19 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/07 16:50:32 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	_ckeckphilo_end(t_philo *ph)
{
	bool	res;

	pthread_mutex_lock(&ph->data->m_ends);
	if (ph->end == 1)
		res = true;
	else
		res = false;
	pthread_mutex_unlock(&ph->data->m_ends);
	return (res);
}

bool	print_status(t_philo *philo, char c)
{
	pthread_mutex_lock(&philo->data->print);
	if (!is_death(philo->data))
	{
		if (c == 'T')
			printf("%zu %d is thinking\n", ft_time_passed(philo->start),
				philo->id);
		else if (c == 'F')
			printf("%zu %d has taken a fork\n",
				ft_time_passed(philo->start), philo->id);
		else if (c == 'E')
			printf("%zu %d is eating\n",
				ft_time_passed(philo->start), philo->id);
		else if (c == 'S')
			printf("%zu %d is sleeping\n",
				ft_time_passed(philo->start), philo->id);
		pthread_mutex_unlock(&philo->data->print);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->print);
	return (true);
}
