/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:24:28 by jazevedo          #+#    #+#             */
/*   Updated: 2024/08/09 17:24:29 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

static size_t	house_places(int n)
{
	size_t	places;

	places = 0;
	if (n < 0)
		places++;
	while (n != 0)
	{
		n /= 10;
		places++;
	}
	return (places);
}

char	*ft_itoa(int n)
{
	size_t	size_n;
	char	*new_s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!n)
		return (ft_strdup("0"));
	size_n = house_places(n);
	new_s = malloc(sizeof(char) * (size_n + 1));
	if (!new_s)
		return (NULL);
	new_s[size_n--] = '\0';
	if (n < 0)
	{
		new_s[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		new_s[size_n--] = n % 10 + '0';
		n /= 10;
	}
	return (new_s);
}
