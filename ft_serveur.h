/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serveur.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 16:42:35 by ytailor           #+#    #+#             */
/*   Updated: 2014/02/09 12:26:00 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SERVEUR_H
# define FT_SERVEUR_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

typedef struct		s_list
{
	char			c;
	struct s_list	*next;
	struct s_list	*last;
}					t_list;

/*
** main.c
*/

void				ft_get_c(int i);
void				ft_check_signal(int sig);

/*
**	ft_list.c
*/
t_list				*ft_create_elem(char c);
void				ft_print_list(const t_list *list);
t_list				*ft_add_elem(char c, t_list *list);

#endif
