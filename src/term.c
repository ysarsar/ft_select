/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 18:24:45 by ysarsar           #+#    #+#             */
/*   Updated: 2020/01/07 21:08:53 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		init_term(t_term *term)
{
	if (!isatty(2))
		print_error("isatty");
	if (((term->fd) = open("/dev/tty", O_RDWR)) == -1)
		print_error("ttyname");
	if (tgetent(NULL, getenv("TERM")) < 1)
		print_error("getenv");
	if (tcgetattr(term->fd, &(term->termio)) == -1)
		print_error("tcgetattr");
	term->termio.c_lflag &= ~(ECHO | ICANON);
	if (tcsetattr(term->fd, TCSANOW, &(term->termio)) == -1)
		print_error("tcsetattr");
	tputs(tgetstr("ti", NULL), 0, fd_putchar);
	tputs(tgetstr("vi", NULL), 0, fd_putchar);
}