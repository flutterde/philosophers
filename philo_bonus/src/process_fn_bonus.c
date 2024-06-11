/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fn_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:44:20 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/10 18:08:48 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	set_last_meal(t_philo *ph)
{
	sem_wait(ph->data->check);
	ph->last_meal = ft_time();
	sem_post(ph->data->check);
}

void	_begin_sim(pthread_t *thread, t_philo *philo)
{
	sem_wait(philo->data->start_sim);
	set_last_meal(philo);
	pthread_create(thread, NULL, thread_routine, philo);
	if (philo->id % 2 == 0)
	{
		print_status(philo->data, philo->id, "is sleeping", 0);
		ft_sleep(philo->data->time2sleep);
	}
}

void	__routine(t_philo *philo)
{
	pthread_t	thread;

	_begin_sim(&thread, philo);
	while (1)
	{
		print_status(philo->data, philo->id, "is thinking", 0);
		sem_wait(philo->data->forks);
		print_status(philo->data, philo->id, "has taken a fork", 0);
		sem_wait(philo->data->forks);
		print_status(philo->data, philo->id, "has taken a fork", 0);
		set_last_meal(philo);
		print_status(philo->data, philo->id, "is eating", 0);
		ft_sleep(philo->data->time2eat);
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		print_status(philo->data, philo->id, "is sleeping", 0);
		ft_sleep(philo->data->time2sleep);
		if (philo->data->eattimes > 0)
			philo->data->eattimes -= 1;
		if (!philo->data->eattimes)
			exit(0);
	}
	pthread_join(thread, NULL);
	exit(0);
}
