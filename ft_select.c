/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 11:19:06 by ysarsar           #+#    #+#             */
/*   Updated: 2019/12/22 12:33:07 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <curses.h>
#include <term.h>

# define MAGENTA "\033[35m"
# define YELLOW "\033[33m"
# define GREEN "\033[32m"
# define WHITE "\033[37m"
# define RESET "\033[00m"
# define BLACK "\033[30m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define RED "\033[31m"

int		init_term()
{
	int		ret;
	char	*term_type;

	term_type = getenv("TERM");
	if (term_type == NULL)
	{
		fprintf(stderr, "TERM must be set (see 'env').\n");
		return (-1);
	}
	ret = tgetent(NULL, term_type);
	if (ret == -1)
	{
		fprintf(stderr, "Could not access to the termcap database..\n");
		return (-1);
	}
	else if (ret == 0)
	{
		fprintf(stderr, "Terminal type '%s' is not defined in termcap database (or have too few informations).\n", term_type);
		return (-1);
	}

	return (0);
}

void	test_text_color()
{
	tputs(tgetstr("so", NULL), 1, putchar);
	printf("%sRED TEXT%s\n", RED, RESET);
	tputs(tgetstr("se", NULL), 1, putchar);

	printf("%sGREEN TEXT%s\n", GREEN, RESET);

	char *bold_cmd = tgetstr("md", NULL);
	char *reset_cmd = tgetstr("me", NULL);
	tputs(bold_cmd, 1, putchar);
	printf("BOLD text.\n");

	char *underline_cmd = tgetstr("us", NULL);
	tputs(underline_cmd, 1, putchar);
	printf("%stext underlined.%s\n", CYAN, RESET);
	tputs(reset_cmd, 1, putchar);
}

int		main()
{
	int		ret;
	
	ret = init_term();
	if (ret == 0)
	{
		fprintf(stderr, "the terminal is initialised.\n");
		test_text_color();
	}
	return (ret);
}