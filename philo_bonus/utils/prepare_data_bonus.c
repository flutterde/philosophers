/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:05:33 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/10 16:32:30 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	set_data(t_data *data, char **av)
{
	memset(data, 0, sizeof(t_data));
	data->nbr = ft_atoi(av[1]);
	data->time2die = ft_atoi(av[2]);
	data->time2eat = ft_atoi(av[3]);
	data->time2sleep = ft_atoi(av[4]);
	if (!av[5])
		data->eattimes = -1;
	else
		data->eattimes = ft_atoi(av[5]);
	data->start = ft_time();
}

t_philo	philo_data(t_data *dt, int i)
{
	t_philo	ph;

	ph.id = i + 1;
	ph.data = dt;
	ph.last_meal = dt->start;
	return (ph);
}

int	_alloc2philos(t_philo **philos, t_data *dt, int **childs)
{
	int	i;

	i = 0;
	*philos = malloc(sizeof(t_philo) * dt->nbr);
	if (!*philos)
	{
		printf("Error While trying to alloc.\n");
		exit(1);
	}
	*childs = malloc(sizeof(int) * dt->nbr);
	if (!*childs)
		return (printf("Error in Allocation.\n"), free(*philos), exit(1), 0);
	while (i < dt->nbr)
	{
		(*philos)[i] = philo_data(dt, i);
		i++;
	}
	return (1);
}

void	_unlink_sems(void)
{
	sem_unlink(WRITING);
	sem_unlink(FORKS);
	sem_unlink(START_SIMULATION);
	sem_unlink(SEM_CHECK);
}

void	_free_resources(int *children, t_philo *philos)
{
	free(children);
	free(philos);
}
