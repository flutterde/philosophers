/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:08:30 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/07 15:49:49 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	_unlock_forks(pthread_mutex_t *left, pthread_mutex_t *right)
{
	pthread_mutex_unlock(left);
	pthread_mutex_unlock(right);
}

static void	update_lock(t_philo *philo)
{
	pthread_mutex_lock(&philo->right->mutex);
	pthread_mutex_lock(&philo->stime);
	philo->last_meal = ft_time();
	pthread_mutex_unlock(&philo->stime);
}

static void	*__handler(t_philo *philo, int *i)
{
	while (!is_death(philo->data))
	{
		if (print_status(philo, 'T'))
			return (NULL);
		pthread_mutex_lock(&philo->left->mutex);
		if (print_status(philo, 'F'))
			return (pthread_mutex_unlock(&philo->stime), NULL);
		update_lock(philo);
		if (print_status(philo, 'F'))
			return (_unlock_forks(&philo->left->mutex, &philo->right->mutex),
				NULL);
		if (print_status(philo, 'E'))
			return (_unlock_forks(&philo->left->mutex, &philo->right->mutex),
				NULL);
		if (!ft_sleep(philo->data->time2eat, philo->data))
			return (_unlock_forks(&philo->left->mutex, &philo->right->mutex),
				NULL);
		_unlock_forks(&philo->left->mutex, &philo->right->mutex);
		if (print_status(philo, 'S'))
			return (0);
		ft_sleep(philo->data->time2sleep, philo->data);
		if (is_end_simulation(philo, i, &philo->eat))
			break ;
	}
	return (NULL);
}

void	*_routine(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		if (print_status(philo, 'S'))
			return (NULL);
		if (!ft_sleep(philo->data->time2sleep, philo->data))
			return (NULL);
	}
	__handler(philo, &i);
	return (NULL);
}
