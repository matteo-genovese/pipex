/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:37:30 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/25 16:56:19 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*w;

	i = 0;
	w = (char *)s;
	while (i < n)
	{
		w[i] = c;
		++i;
	}
	return (s);
}
