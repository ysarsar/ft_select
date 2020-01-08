/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 22:36:44 by ysarsar           #+#    #+#             */
/*   Updated: 2020/01/08 22:36:29 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void			ft_selected(t_term *term, int index)
{
	t_lst		*tmp;
	int			i;

	tmp = term->list;
	i = 0;
	while (tmp)
	{
		if (i == index)
		{
			if (!tmp->color)
				tmp->color = ft_strdup("\033[7m");
			else
				tmp->color = NULL;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
}

void			ft_return(t_term *term)
{
	t_lst		*tmp;

	tmp = term->list;
	tputs(tgetstr("te", NULL), 0, fd_putchar);
	while (tmp)
	{
		if (tmp->color)
		{
			ft_putstr(tmp->name);
			write(1, " ", 1);
		}
		tmp = tmp->next;
	}
	exit_term(term);
}

int				move_down(t_term *term, int index)
{
	int		nb_colom;

	nb_colom = (term->info.nb_col / (term->info.max_len + 1));
	if (index == term->info.nb_elem - 1)
		return (0);
	else if (nb_colom == term->info.nb_elem - 1)
		return (term->info.nb_elem - 1);
	else if (index < term->info.nb_elem - 1)
		if (index + nb_colom <= term->info.nb_elem - 1)
			return (index + nb_colom);
	return (term->info.nb_elem - 1);
}

int				move_up(t_term *term, int index)
{
	int		nb_colom;

	nb_colom = (term->info.nb_col / (term->info.max_len + 1));
	if (index == 0)
		return (term->info.nb_elem - 1);
	else if (index <= term->info.nb_elem - 1)
		if (index - nb_colom >= 1)
			return (index - nb_colom);
	return (0);
}
