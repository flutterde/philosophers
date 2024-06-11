/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:11:55 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/09 18:06:09 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

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

int	ft_sleep(size_t time)
{
	size_t	start;
	size_t	end;

	start = ft_time();
	end = start + time;
	while (ft_time() < end)
		usleep(200);
	return (1);
}
