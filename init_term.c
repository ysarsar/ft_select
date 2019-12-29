/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:44:58 by ysarsar           #+#    #+#             */
/*   Updated: 2019/12/29 21:09:26 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_select.h"

int    init_term()
{
    int fd;
    t_termio    termio;

    if (!isatty(2))
        print_error("isatty");
    if ((fd = open(ttyname(2), O_RDWR)) == -1)
        print_error("fd");
    if ((tgetent(NULL, getenv("TERM"))) == -1)
        print_error("tgetent");
    if ((tcgetattr(fd, &termio)) == -1)
        print_error("tcgetattr");
    termio.c_lflag &= ~(ECHO | ICANON);
    if ((tcsetattr(fd, TCSANOW, &termio)) == -1)
        print_error("tcsetattr");
    tputs(tgetstr("ti", NULL), 0, fd_putchar);   
    tputs(tgetstr("vi", NULL), 0, fd_putchar);
    return (fd);
}