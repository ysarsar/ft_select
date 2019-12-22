/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 19:37:03 by ysarsar           #+#    #+#             */
/*   Updated: 2019/12/22 23:57:19 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void    check_args(int ac)
{
	if (ac < 2)
	{
		ft_putendl_fd("ft_select: usage: ./ft_select arg1 arg2 arg3 ...", 2);
		exit(1);
	}
}

// void	catch_signal(void)
// {
// 	signal(SIGWINCH, resize);
// 	signal(SIGTSTP, stop);
// 	signal(SIGQUIT, end);
// 	signal(SIGTERM, end);
// 	signal(SIGINT, end);
// }

int		init1_term(void)
{
	char	*term_type;
	int		ret;
	
	term_type = getenv("TERM");
	if (term_type == NULL)
	{
		ft_putendl_fd("ft_select: TERM must be set (see 'env').", 2);
		exit(1);
	}
	ret = tgetent(NULL, term_type);
	if (ret == -1)
	{
		ft_putendl_fd("ft_select: Could not access to the termcap database..", 2);
		exit (1);
	}
	else if (ret == 0)
	{
		ft_putendl_fd("ft_select: Terminal type is not defined in termcap database.", 2);
		exit (1);
	}
	return (0);
}

void	init2_term(void)
{
	int				ret;
	int				fd;
	struct	termios	win;

	if ((fd = open(ttyname(0), O_RDWR)) == -1)
	{
		ft_putendl_fd("ft_select: error: ttyname.", 2);
		exit (1);
	}
	ret = init1_term();
	if (tcgetattr(fd, &win) == -1)
	{
		ft_putendl_fd("ft_select: error: tcgetattr.", 2);
		exit (1);
	}
	win.c_lflag &= ~(ECHO | ICANON);
	if (tcsetattr(fd, TCSANOW, &win) == -1)
	{
		ft_putendl_fd("ft_select: error: tcsetattr.", 2);
		exit (1);
	}
	tputs(tgetstr("ti", NULL), 0, ft_putchar);
	tputs(tgetstr("cl", NULL), 0, ft_putchar);
}

int     main(int ac, char **av)
{
	int		r;
	t_term	*term;

	check_args(ac);
	//catch_signal();
	init2_term();
	term = stock_list(av);
		while (term)
		{
			ft_putendl_fd(term->arg, 2);
			term = term->next;
		}
	while (read(1, &r, sizeof(int)) > 0)
	{
		if (r == 27)
			break;
	}
	tputs(tgetstr("te", NULL), 0, ft_putchar);
	return (0);
}