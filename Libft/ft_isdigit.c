/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:07:06 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:14:33 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	return ((c >= 48 && c <= 57));
}
/*
#include <unistd.h>

int	main(void)
{
	if (ft_isdigit('g'))
		write(1, "Is digit", 8);
	else
		write(1, "Is not digit", 12);
	return (0);
}
*/
