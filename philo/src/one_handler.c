/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:37:51 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/07 15:49:07 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	*one_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	printf("%zu 	1  has taken a fork\n",
		ft_time_passed(data->start));
	ft_sleep(data->time2die, data);
	printf("%zu 	1  died\n", ft_time_passed(data->start));
	return (NULL);
}

// this function used when we have 1 philo only
void	one_handler(t_data *data)
{
	pthread_t	trd;

	pthread_create(&trd, NULL, one_routine, data);
	pthread_join(trd, NULL);
}
