/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 22:44:09 by kbarahon          #+#    #+#             */
/*   Updated: 2021/09/18 20:06:38 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*snew;

	len = ft_strlen((char *)s1) + 1;
	snew = (char *)malloc(len);
	if (snew == NULL)
		return (NULL);
	snew = ft_memcpy(snew, s1, len);
	return ((char *)snew);
}
