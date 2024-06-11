/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:12:18 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/06 22:14:42 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	destro_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr)
	{
		pthread_mutex_destroy(&philos[i].stime);
		i++;
	}
}

void	_free_data(t_philo *philos, t_fork *forks, pthread_t *threads)
{
	free(philos);
	free(forks);
	free(threads);
}
