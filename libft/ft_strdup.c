/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:14:24 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/27 17:09:07 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len_s;
	char	*str;

	len_s = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len_s)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}
