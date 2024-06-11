/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:11:27 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/10 18:16:04 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	print_status(t_data *data, int id, char *msg, char c)
{
	sem_wait(data->printing);
	if (c == 'd')
	{
		printf("\033[0;91m%zu  %d died\033[0m\n",
			ft_time_passed(data->start), id);
		return ;
	}
	else
		printf("%zu  %d %s\n", ft_time_passed(data->start),
			id, msg);
	sem_post(data->printing);
}

size_t	last_meal(t_philo *ph)
{
	size_t	last_meal;

	sem_wait(ph->data->check);
	last_meal = ph->last_meal;
	sem_post(ph->data->check);
	return (last_meal);
}

void	*thread_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if ((int)(ft_time() - last_meal(philo)) >= philo->data->time2die)
		{
			print_status(philo->data, philo->id, "", 'd');
			exit(1); 
		}
		usleep(500);
	}
	return (NULL);
}
