/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:39:28 by ysarsar           #+#    #+#             */
/*   Updated: 2020/01/09 22:35:11 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static	void	print_list(t_lst *list, int i)
{
	char	*under;

	under = tgetstr("us", NULL);
	if (i == 0)
	{
		ft_putstr_fd(list->color, 2);
		ft_putstr_fd(list->name, 2);
		ft_putstr_fd(RESET, 2);
	}
	else
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd(under, 2);
		ft_putstr_fd(list->color, 2);
		ft_putstr_fd(list->name, 2);
		ft_putstr_fd(RESET, 2);
	}
}

static	void	dsp_lst(t_term *term, int index)
{
	t_lst		*tmp;
	int			x;
	int			y;
	int			i;

	tmp = term->list;
	x = 0;
	y = 0;
	i = -1;
	while (tmp)
	{
		if (x + term->info.max_len + 1 > term->info.nb_col)
		{
			x = 0;
			y++;
			tputs(tgoto(tgetstr("cm", NULL), x, y), 0, fd_putchar);
		}
		if (index == ++i)
			print_list(tmp, 1);
		else
			print_list(tmp, 0);
		x = x + term->info.max_len + 1;
		tputs(tgoto(tgetstr("cm", NULL), x, y), 0, fd_putchar);
		tmp = tmp->next;
	}
}

void			display_list(t_term *term, int index)
{
	static	int	k;

	if (index == -1)
		k = k;
	else
		k = index;
	get_terminal_size(term);
	tputs(tgetstr("cl", NULL), 0, fd_putchar);
	if (!check_size(term))
		return ;
	dsp_lst(term, k);
}
