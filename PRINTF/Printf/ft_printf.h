/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:18:39 by mtaleb            #+#    #+#             */
/*   Updated: 2025/02/17 10:40:47 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "LIBFT/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

//  csuxXdip
// 012345678
typedef struct flags {
	bool	zero;
	bool	minus;
	bool	plus;
	bool	precision_exist;
	bool	negative;
	bool	space;
	bool	hashtag;
	int		specifier;
	int		precision;
	int		width;
}	t_flag;

// INIT
void	initflags(t_flag *flag);
int		initstruct(char **str, t_flag *flag);

//PRINT 
char	*printmemory(void *addr);
char	*printunsigned(unsigned int n);
char	*printstring(const char *s);
char	*printint(int n, t_flag *params);
int		printchar(int c, int width, bool minus);
char	*printhexa(unsigned int n, char *base, t_flag *params);

// CHECK ERRORS
int		checkorder(char *s);
int		checkoverflow(char *s);
char	*checknull(t_flag *params);

// BONUS FUNCTIONS
int		width(char *ptr, t_flag *params);
char	*flags(char *ptr, t_flag *params);
char	*precision(t_flag *flag, char *str);

// UTILS 
void	ft_putchar(char c);
void	ft_putstr(char *s);
long	ft_pratoi(char **nptr);

// PRINTF
int		ft_printf(const char *s, ...);

#endif