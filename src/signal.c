/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:00:48 by ysarsar           #+#    #+#             */
/*   Updated: 2020/01/08 18:44:40 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static	void	resize(int sig)
{
	static	t_term	*term;

	(void)sig;
	term = NULL;
	term = stock_term(term, 1);
	display_list(term, -1);
}

void			catch_signal(void)
{
	signal(SIGWINCH, resize);
}