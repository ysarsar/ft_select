/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:18:09 by ysarsar           #+#    #+#             */
/*   Updated: 2020/01/11 20:50:40 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static	void	list_size(t_term *term)
{
	int		max_len;
	int		nb_elements;
	int		len;
	t_lst	*tmp;

	max_len = 0;
	nb_elements = 0;
	len = 0;
	tmp = term->list;
	while (tmp)
	{
		len = ft_strlen(tmp->name);
		if (len > max_len)
			max_len = len;
		nb_elements++;
		tmp = tmp->next;
	}
	term->info.max_len = max_len;
	term->info.nb_elem = nb_elements;
}

void			get_terminal_size(t_term *term)
{
	ioctl(0, TIOCGWINSZ, &(term->win));
	term->info.nb_col = term->win.ws_col;
	term->info.nb_row = term->win.ws_row;
	list_size(term);
}

static	int		check_line(t_term *term)
{
	int		x;
	int		y;
	t_lst	*tmp;

	x = 0;
	y = 0;
	tmp = term->list;
	while (tmp)
	{
		if (x + term->info.max_len + 1 > term->info.nb_col)
		{
			x = 0;
			y++;
		}
		if (term->info.nb_col < term->info.max_len + 1)
			return (0);
		if (y > term->info.nb_row - 1)
			return (0);
		x = x + term->info.max_len + 1;
		tmp = tmp->next;
	}
	return (1);
}

int				check_size(t_term *term)
{
	if (!check_line(term))
	{
		ft_putendl_fd("Window size is too small.", 2);
		return (0);
	}
	if ((term->info.nb_elem * (term->info.max_len + 1)) >
		(term->info.nb_col * term->info.nb_row))
	{
		ft_putendl_fd("Window size is too small.", 2);
		return (0);
	}
	return (1);
}
