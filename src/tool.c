/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 18:42:29 by ysarsar           #+#    #+#             */
/*   Updated: 2020/01/08 22:50:35 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int				fd_putchar(int c)
{
	write(2, &c, 1);
	return (0);
}

t_term			*stock_term(t_term *term, int i)
{
	static	t_term	*tmp;

	if (i == 0)
		tmp = term;
	return (tmp);
}

static	void	free_list(t_term *term)
{
	t_lst	*tmp;
	t_lst	*prev;

	tmp = term->list;
	prev = NULL;
	while (tmp)
	{
		prev = tmp;
		free(tmp->color);
		ft_strdel(&tmp->name);
		tmp = tmp->next;
		free(prev);
	}
}

void			exit_term(t_term *term)
{
	tputs(tgetstr("ve", NULL), 0, fd_putchar);
	free_list(term);
	exit(0);
}

void			print_error(char *str)
{
	exit(1);
}
