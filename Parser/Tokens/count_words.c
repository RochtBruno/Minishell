/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:12:31 by btaveira          #+#    #+#             */
/*   Updated: 2024/08/30 07:55:22 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

int	count_words_loop(char *input, int i)
{
	while (input[i] && !is_separator(input, i))
	{
		if ((input[i] == '\'' || input[i] == '\"') && \
			verify_quote(input, i))
			i = is_quote(input, i);
		else if (input[i] == '(' && verify_parenthesis(input, i))
			i = skip_parenthesis(input, i);
		else
			i++;
	}
	return (i);
}

int	is_double_separator(char *input, int i)
{
	if (!ft_strncmp(input + i, "&&", 2))
		return (1);
	else if (!ft_strncmp(input + i, "||", 2))
		return (1);
	else if (!ft_strncmp(input + i, ">>", 2))
		return (1);
	else if (!ft_strncmp(input + i, "<<", 2))
		return (1);
	return (0);
}

int	count_words(char *input)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (input[i])
	{
		while (input[i] && input[i] == ' ')
			i++;
		if (input[i] == '\0')
			break ;
		words++;
		if (is_separator(input, i))
		{
			if (is_double_separator(input, i))
				i += 2;
			else
				i++;
		}
		else
			i = count_words_loop(input, i);
	}
	return (words);
}
