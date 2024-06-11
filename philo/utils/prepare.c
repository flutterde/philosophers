/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:25:35 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/07 19:48:14 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	_validate_args(int ac, char **av, t_data *dt)
{
	dt->nbr = ft_atoi(av[1]);
	dt->time2die = ft_atoi(av[2]);
	dt->time2eat = ft_atoi(av[3]);
	dt->time2sleep = ft_atoi(av[4]);
	dt->death = false;
	dt->start = ft_time();
	dt->ends = 0;
	dt->x = 0;
	if (ac == 6)
		dt->nbr2eat = ft_atoi(av[5]);
	else
		dt->nbr2eat = -1;
	if (dt->nbr <= 0 || dt->nbr2eat == 0 || dt->nbr > 200 || dt->time2die < 60
		|| dt->time2eat < 60 || dt->time2sleep < 60)
		return (printf("Error: wrong arguments\n"), 0);
	return (1);
}

void	setphilo_data(t_philo *philo, t_fork *forks, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr)
	{
		philo[i].id = i + 1;
		philo[i].left = &forks[i];
		if (i == (data->nbr - 1))
			philo[i].right = &forks[0];
		else
			philo[i].right = &forks[(i + 1) % data->nbr];
		philo[i].data = data;
		pthread_mutex_init(&philo[i].stime, NULL);
		philo[i].last_meal = ft_time();
		philo[i].start = data->start;
		philo[i].eat = data->nbr2eat;
		philo[i].end = 0;
		i++;
	}
}

int	_create_tr(pthread_t *threads, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr)
	{
		if (pthread_create(&threads[i], NULL, _routine, &philo[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	_init_mutexes(t_fork *forks, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr)
	{
		forks[i].id = i;
		if (pthread_mutex_init(&forks[i].mutex, NULL) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	_wait_threads(pthread_t *threads, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr)
		pthread_join(threads[i++], NULL);
	return (1);
}
