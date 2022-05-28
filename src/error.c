/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvial <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:42:11 by gvial             #+#    #+#             */
/*   Updated: 2022/05/28 13:42:13 by gvial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	arg_error(void)
{
	ft_printf("Error:\nArgument error\n");
	exit(0);
}

void	map_error(void)
{
	ft_printf("Error:\nMap is not valid\n");
	exit(0);
}
