/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:46:36 by mtomomit          #+#    #+#             */
/*   Updated: 2022/05/27 21:55:56 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static void	conversion(t_args *args)
{
	if (args->type == 'c')
	{
		args->format_len += 1;
		write(1, &args->ch, 1);
	}
	else if (args->type == 's')
		args->format_len += str_conversion(args->str);
	else if (args->type == 'p')
		args->format_len += ptr_conversion(args->hex_ptr);
	else if (args->type == 'd')
		args->format_len += int_conversion(args->nb);
	else if (args->type == 'i')
		args->format_len += int_conversion(args->nb);
	else if (args->type == 'u')
		args->format_len += unsigint_conversion(args->unsigint);
	else if (args->type == 'x')
		args->format_len += hex_conversion(args->unsigint, args->type);
	else if (args->type == 'X')
		args->format_len += hex_conversion(args->unsigint, args->type);
	else if (args->type == '%')
	{
		write(1, "%", 1);
		args->format_len += 1;
	}
}

static void	args_init(t_args *args, va_list ap)
{
	if (args->type == 'c')
		args->ch = va_arg(ap, int);
	else if (args->type == 's')
		args->str = va_arg(ap, char *);
	else if (args->type == 'p')
		args->hex_ptr = va_arg(ap, void *);
	else if (args->type == 'd')
		args->nb = va_arg(ap, int);
	else if (args->type == 'i')
		args->nb = va_arg(ap, int);
	else if (args->type == 'u')
		args->unsigint = va_arg(ap, unsigned int);
	else if (args->type == 'x')
		args->unsigint = va_arg(ap, unsigned int);
	else if (args->type == 'X')
		args->unsigint = va_arg(ap, unsigned int);
	else if (args->type != '\0')
	{
		if (args->type >= 32 && args->type < 127)
			write(1, "%", 1);
		write(1, &args->type, 1);
	}
	else
		return ;
}

static int	write_format(const char *format, t_args *args)
{
	size_t	i;

	i = 0;
	while (format[i] != '%' && format[i])
	{
		write(1, &format[i], 1);
		i++;
	}
	args->format_len += i;
	if (format[i] == '\0')
		i--;
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_args	args;
	size_t	i;

	i = 0;
	args.format_len = i;
	va_start(ap, format);
	while (format[i])
	{
		i += write_format(&format[i], &args) + 1;
		args.type = format[i];
		if (args.type != '%' && format[i] != '\0')
			args_init(&args, ap);
		if (format[i] != '\0')
			conversion(&args);
		if (format[i] != '\0')
			i++;
	}
	va_end(ap);
	return (args.format_len);
}
