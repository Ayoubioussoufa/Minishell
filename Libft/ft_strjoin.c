/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:16:06 by aybiouss          #+#    #+#             */
/*   Updated: 2022/10/24 17:19:26 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s1[j])
		s[i++] = s1[j++];
	while (s2[k])
		s[i++] = s2[k++];
	s[i] = '\0';
	return (s);
}
