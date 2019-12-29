/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:30:20 by ysarsar           #+#    #+#             */
/*   Updated: 2019/12/29 21:48:39 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "./libft/libft.h"
# include <sys/ioctl.h>
# include <termios.h>
# include <termcap.h>
# include <signal.h>
# include <fcntl.h>
# include <term.h>
# include <curses.h>

# define K_DEL 2117294875
# define K_RIGHT 4414235
# define K_LEFT	4479771
# define K_DOWN 4348699
# define K_UP 4283163
# define K_ESC 27
# define K_SP 32

typedef struct winsize	t_win;
typedef struct termios	t_termio;

typedef struct			s_lst
{
	char                *color;
	char				*name;
	struct s_lst		*next;
}						t_lst;

int     fd_putchar(int c);
int     init_term();
void    print_error(char *str);
t_lst   *init_list(char **av);
void    display(t_lst *list, int fd, int index);

#endif