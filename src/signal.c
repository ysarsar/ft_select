/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:00:48 by ysarsar           #+#    #+#             */
/*   Updated: 2020/01/10 23:37:20 by ysarsar          ###   ########.fr       */
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

static	void	stop(int sig)
{
	t_term	*term;

	(void)sig;
	term = NULL;
	term = stock_term(term, 1);
	tputs(tgetstr("te", NULL), 0, fd_putchar);
	tputs(tgetstr("ve", NULL), 0, fd_putchar);
	signal(SIGTSTP, SIG_DFL);
	ioctl(3, TIOCSTI, "\032");
}

static	void	start(int sig)
{
	t_term	*term;

	(void)sig;
	term = NULL;
	term = stock_term(term, 1);
	term->termio.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(term->fd, TCSANOW, &(term->termio));
	tputs(tgetstr("ti", NULL), 0, fd_putchar);
	tputs(tgetstr("vi", NULL), 0, fd_putchar);
	catch_signal();
	display_list(term, -1);
}

static	void	end(int sig)
{
	t_term	*term;

	(void)sig;
	term = stock_term(term, 1);
	tputs(tgetstr("te", NULL), 0, fd_putchar);
	exit_term(term);
}

void			catch_signal(void)
{
	signal(SIGWINCH, resize);
	signal(SIGTSTP, stop);
	signal(SIGCONT, start);
	signal(SIGINT, end);
	signal(SIGQUIT, end);
	signal(SIGTERM, end);
	signal(SIGKILL, end);
	signal(SIGSEGV, end);
	signal(SIGABRT, end);
	signal(SIGBUS, end);
	signal(SIGHUP, end);
	signal(SIGILL, end);
	signal(SIGTRAP, end);
	signal(SIGEMT, end);
	signal(SIGFPE, end);
	signal(SIGSYS, end);
	signal(SIGPIPE, end);
	signal(SIGALRM, end);
	signal(SIGCHLD, end);
	signal(SIGXCPU, end);
	signal(SIGXFSZ, end);
	signal(SIGVTALRM, end);
	signal(SIGPROF, end);
	signal(SIGUSR1, end);
	signal(SIGUSR2, end);
}
