/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:02:26 by mtomomit          #+#    #+#             */
/*   Updated: 2022/05/27 21:38:27 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	hex_conversion(unsigned int nb, char type)
{
	char	*nbr;
	size_t	len_nbr;

	if (type == 'X')
		nbr = ft_itoa_base(nb, "0123456789ABCDEF");
	if (type == 'x')
		nbr = ft_itoa_base(nb, "0123456789abcdef");
	ft_putstr_fd(nbr, 1);
	len_nbr = ft_strlen(nbr);
	free(nbr);
	return (len_nbr);
}
