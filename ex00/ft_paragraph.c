/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paragraph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdal-gra <kdal-gra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:24:19 by kdal-gra          #+#    #+#             */
/*   Updated: 2026/10/26 17:13:35 by kdal-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_paragraph.h"

int	put_error(char *inputerror)
{
	while (*inputerror != '\0')
	{
		write(2, inputerror, 1);
		inputerror++;
	}
	return (1);
}

int	ft_l_len(char *input, t_config *config)
{
	int i;

	i = 0;
	while(i < config->l_len && input[i] != '\0')
	{
		write(1, &input[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return(i);
}

int ft_p_len(char *input, t_config *config)
{
	int i;
	int len;
	int total_len;

	i = 0;
	total_len = 0;
	while(i < config->p_len)
	{
		len = ft_l_len(input, config);
		input += len;
		total_len += len;
		i++;
	}
	write(1, "\n", 1);
	return(total_len);
}

void	ft_make_paragraph(char *input, t_config *config)
{
	int i;
	int len;
	int total_len;

	i = 0;
	total_len = 0;
	while(i < config->p_nbr)
	{
		len = ft_p_len(input, config);
		input += len;
		total_len += len;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_config	config;

	config.l_len = 5;
	config.p_len = 2;
	config.p_nbr = 3;
	if (argc != 2)
		return (put_error("Error : usage ./a.out <text>\n"));
	ft_make_paragraph(argv[1], &config);
	return(0);
}
