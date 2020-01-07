/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 18:13:13 by ysarsar           #+#    #+#             */
/*   Updated: 2020/01/07 02:00:38 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static	void	check_args(int ac)
{
	if (ac < 2)
	{
		ft_putendl("ft_select: usage: ./ft_select [arg1] [arg2] ...");
		exit(0);
	}
}

static	int		get_key(t_term *term, int index)
{
	int		r;

	r = 0;
	if (read(0, &r, 4) < 0)
		print_error("read");
	if (r == K_LEFT)
		{
			if (index == 1)
				return (term->info.nb_elem - 1);
			return (index - 1);
		}
	else if (r == K_RIGHT)
	{
		if (index == (term->info.nb_elem - 1))
			return (1);
		return (index + 1);
	}
	else if (r == K_SP)
	{
		ft_selected(term, index);
		if (index == term->info.nb_elem - 1)
			return (1);
		return (index + 1);
	}
	else if (r == K_ESC)
		return (0);
	else if (r == K_RET)
	{
		ft_return(term);
		return (0);
	}
	else if (r == K_DEL || r == K_BSP)
	{
		ft_remove_node(term, index);
		if (index == term->info.nb_elem - 1)
			return (index - 1);
	}
	else if (r == K_DOWN)
		return (move_down(term, index));
	else if (r == K_UP)
		return (move_up(term, index));
	return (index);
}

static	void	display_loop(t_term *term)
{
	int		index;

	index = 1;
	get_terminal_size(term);
	term = stock_term(term, 0);
	display_list(term, index);
	while (index)
	{
		index = get_key(term, index);
		if (index == 0)
			break ;
		display_list(term, index);
	}
}

int				main(int ac, char **av)
{
	t_term	term;

	check_args(ac);
	catch_signal();
	init_term(&term);
	init_list(&term, av);
	display_loop(&term);
	tputs(tgetstr("te", NULL), 0, fd_putchar);
	tputs(tgetstr("ve", NULL), 0, fd_putchar);
	return (0);
}