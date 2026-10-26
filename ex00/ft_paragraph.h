/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paragraph.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdal-gra <kdal-gra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:24:07 by kdal-gra          #+#    #+#             */
/*   Updated: 2026/10/26 16:28:00 by kdal-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARAGRAPH_H
# define FT_PARAGRAPH_H

typedef struct s_config
{
	int	p_nbr;
	int	p_len;
	int	l_len;
}	t_config;

void	ft_make_paragraph(char *input, t_config *config);

#endif