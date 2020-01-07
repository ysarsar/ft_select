/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 18:42:29 by ysarsar           #+#    #+#             */
/*   Updated: 2020/01/07 02:09:21 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../includes/ft_select.h"

int			fd_putchar(int c)
{
	return (write(2, &c, 1));
}

t_term		*stock_term(t_term *term, int i)
{
	static	t_term	*tmp;

	//tmp = NULL;
	if (i == 0)
		tmp = term;
	return (tmp);
}

void		print_error(char *str)
{
	exit(1);
}