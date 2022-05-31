/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:32:58 by mtomomit          #+#    #+#             */
/*   Updated: 2022/05/30 13:53:01 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_args
{
	char			type;
	int				format_len;
	char			ch;
	int				nb;
	char			*str;
	void			*hex_ptr;
	unsigned int	unsigint;
}					t_args;

int	ft_printf(const char *format, ...);
int	hex_conversion(unsigned int nb, char type);
int	int_conversion(int nb);
int	unsigint_conversion(unsigned int nb);
int	str_conversion(char *str);
int	ptr_conversion(void *ptr);

#endif