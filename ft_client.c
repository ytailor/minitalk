/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 13:13:33 by ytailor           #+#    #+#             */
/*   Updated: 2014/02/09 14:58:23 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/includes/libft.h"

void		ft_translate(char *str, int pid)
{
	int		i;
	int		size;
	int		j;

	size = ft_strlen(str);
	i = 0;
	while (i <= size)
	{
		j = 7;
		while (j >= 0)
		{
			usleep(200);
			if ((str[i] & (1 << j)) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
		}
		i++;
	}
}

int			main(int ac, char **av)
{
	int		pid_s;

	if (ac != 3)
	{
		ft_putstr("usage : pid message\n");
		return (0);
	}
	pid_s = ft_atoi(av[1]);
	ft_translate(av[2], pid_s);
	return (0);
}
