/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:26:16 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/06 17:04:34 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

size_t	ft_time_passed(size_t start)
{
	return (ft_time() - start);
}

int	ft_sleep(size_t time, t_data *dt)
{
	size_t	start;
	size_t	end;

	start = ft_time();
	end = start + time;
	while (ft_time() < end)
	{
		if (is_death(dt))
			return (0);
		usleep(200);
	}
	return (1);
}
