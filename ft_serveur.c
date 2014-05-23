/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serveur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thequem <thequem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 12:10:26 by ytailor           #+#    #+#             */
/*   Updated: 2014/02/09 17:40:40 by thequem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_serveur.h"

void		ft_get_c(int i)
{
	static int				count = 8;
	static unsigned char	c = 0;
	static t_list			*list = NULL;

	if (count >= 0)
	{
		c += (i << --count);
		if (count == 0)
		{
			list = ft_add_elem(c, list);
			count = 8;
			if (c == '\0')
			{
				ft_print_list(list);
				list = NULL;
			}
			c = 0;
		}
	}
}

void		ft_check_signal(int sig)
{
	if (sig == SIGUSR1)
		ft_get_c(0);
	if (sig == SIGUSR2)
		ft_get_c(1);
}

int			main(void)
{
	int		pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, ft_check_signal);
	signal(SIGUSR2, ft_check_signal);
	while (42)
		pause();
	return (0);
}
