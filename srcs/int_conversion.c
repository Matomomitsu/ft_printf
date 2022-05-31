/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:27:52 by mtomomit          #+#    #+#             */
/*   Updated: 2022/05/27 21:38:30 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	int_conversion(int nb)
{
	char	*nbr;
	size_t	len_nbr;

	nbr = ft_itoa(nb);
	ft_putstr_fd(nbr, 1);
	len_nbr = ft_strlen(nbr);
	free(nbr);
	return (len_nbr);
}
