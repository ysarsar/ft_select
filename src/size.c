/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:18:09 by ysarsar           #+#    #+#             */
/*   Updated: 2020/01/08 22:48:23 by ysarsar          ###   ########.fr       */
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

int				check_size(t_term *term)
{
	if ((term->info.nb_col * term->info.nb_row) <
		(term->info.nb_elem * (term->info.max_len + 1)))
	{
		ft_putendl_fd("Window size is too small.", 2);
		return (0);
	}
	return (1);
}
