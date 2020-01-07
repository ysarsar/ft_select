/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 18:12:42 by ysarsar           #+#    #+#             */
/*   Updated: 2020/01/07 02:19:16 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/libft.h"
# include <sys/ioctl.h>
# include <termios.h>
# include <termcap.h>
# include <signal.h>
# include <fcntl.h>
# include <term.h>
#include <stdio.h>

# define K_DEL 2117294875
# define K_RIGHT 4414235
# define K_LEFT	4479771
# define K_DOWN 4348699
# define K_UP 4283163
# define K_BSP 127
# define K_RET 10
# define K_ESC 27
# define K_SP 32

# define RESET "\033[00m"
# define RED "\033[31m"

typedef	struct	winsize	t_win;
typedef	struct	termios	t_termio;

typedef	struct		s_lst
{
	char			*name;
	char			*color;
	struct s_lst	*next;
}					t_lst;

typedef	struct		s_size
{
	int				nb_elem;
	int				max_len;
	int				nb_col;
	int				nb_row;
}					t_size;

typedef	struct		s_term
{
	int				fd;
	t_lst			*list;
	t_size			info;
	t_win			win;
	t_termio		termio;
}					t_term;

int					fd_putchar(int c);
void				print_error(char *str);
void				init_term(t_term *term);
void				init_list(t_term *term, char **av);
void				get_terminal_size(t_term *term);
t_term				*stock_term(t_term *term, int i);
int					check_size(t_term *term);
void				display_list(t_term *term, int index);
void				ft_selected(t_term *term, int index);
void				ft_return(t_term *term);
void				ft_remove_node(t_term *term, int index);
int					move_down(t_term *term, int index);
int					move_up(t_term *term, int index);
void				catch_signal(void);

#endif