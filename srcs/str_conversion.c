/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:30:16 by mtomomit          #+#    #+#             */
/*   Updated: 2022/05/27 21:38:35 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	str_conversion(char *str)
{
	size_t	len_str;

	if (!str)
		return (str_conversion("(null)"));
	else
	{
		ft_putstr_fd(str, 1);
		len_str = ft_strlen(str);
		return (len_str);
	}
}
