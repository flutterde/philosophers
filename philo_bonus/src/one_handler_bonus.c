/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:18:22 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/10 16:26:45 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	_one_handler(t_data *dt)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		printf("Can't Fork.\n");
		exit(1);
	}
	if (!pid)
	{
		printf("%zu  1 has taken a fork\n", ft_time_passed(dt->start));
		ft_sleep(dt->time2die);
		printf("%zu  1 died\n", ft_time_passed(dt->start));
	}
	waitpid(pid, NULL, 0);
}
