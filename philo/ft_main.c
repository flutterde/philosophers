/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:27:35 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/10 18:34:23 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	_alloc(t_data *data, pthread_t **threads, t_philo **philos,
		t_fork **forks)
{
	*threads = malloc(sizeof(pthread_t) * data->nbr);
	if (!*threads)
		return (false);
	*philos = malloc(sizeof(t_philo) * data->nbr);
	if (!*philos)
		return (free(*threads), false);
	*forks = malloc(sizeof(t_fork) * data->nbr);
	if (!*forks)
		return (free(*threads), free(*philos), false);
	_init_mutexes(*forks, data);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->checking, NULL);
	pthread_mutex_init(&data->m_ends, NULL);
	setphilo_data(*philos, *forks, data);
	_create_tr(*threads, *philos);
	return (true);
}

static void	_checkingloop(int *i, t_data *data, t_philo *philos)
{
	while (*i < data->nbr)
	{
		if (!_ckeckphilo_end(&philos[*i]))
		{
			pthread_mutex_lock(&philos[*i].stime);
			if ((ft_time() - philos[*i].last_meal) >= (uint64_t)data->time2die)
			{
				pthread_mutex_lock(&data->print);
				set_death(data);
				printf("\033[0;91m%zu %d died\033[0m\n",
					ft_time_passed(philos[*i].start), philos[*i].id);
				pthread_mutex_unlock(&philos[*i].stime);
				pthread_mutex_unlock(&data->print);
				data->x = 1;
				break ;
			}
			pthread_mutex_unlock(&philos[*i].stime);
		}
		(*i)++;
	}
}

static void	_cleanup(t_data *data, t_philo *philos, t_fork *forks,
		pthread_t *threads)
{
	int	i;

	i = 0;
	_wait_threads(threads, data);
	while (i < data->nbr)
		pthread_mutex_destroy(&forks[i++].mutex);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->checking);
	pthread_mutex_destroy(&data->m_ends);
	destro_philos(philos, data);
	_free_data(philos, forks, threads);
}

void	_handler(t_data *data)
{
	pthread_t	*threads;
	t_philo		*philos;
	t_fork		*forks;
	int			i;

	if (!_alloc(data, &threads, &philos, &forks))
		return ;
	while (!data->x && !check_end(data))
	{
		i = 0;
		_checkingloop(&i, data, philos);
	}
	_cleanup(data, philos, forks, threads);
}

int	main(int ac, char **av)
{
	t_data	dt;

	if (ac != 5 && ac != 6)
		return (printf("Error: Arguments are Wrong\n"), 1);
	if (!_validate_args(ac, av, &dt))
		return (1);
	if (dt.nbr == 1)
		return (one_handler(&dt), 0);
	return (_handler(&dt), 0);
}
