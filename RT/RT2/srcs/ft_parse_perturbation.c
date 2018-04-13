/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_perturbation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:08:38 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/29 17:55:38 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_color	(*ft_rand_perturbation_p2(int rnd))(t_phpa *, t_obj *)
{
	if (rnd == 6)
		return (&ft_perturbation_colone);
	if (rnd == 7)
		return (&ft_perturbation_line);
	if (rnd == 8)
		return (&ft_perturbation_dam);
	if (rnd == 9)
		return (&ft_perturbation_sqare);
	if (rnd == 10)
		return (&ft_perturbation_a_trous);
	return (&ft_perturbation_uni);
}

static t_color	(*ft_rand_perturbation(void))(t_phpa *, t_obj *)
{
	int	rnd;

	rnd = rand() % 11;
	if (rnd == 0)
		return (&ft_perturbation_uni);
	if (rnd == 1)
		return (&ft_perturbation_random);
	if (rnd == 2)
		return (&ft_perturbation_half_rnd_two_color);
	if (rnd == 3)
		return (&ft_perturbation_colone_for_all);
	if (rnd == 4)
		return (&ft_perturbation_line_for_all);
	if (rnd == 5)
		return (&ft_perturbation_dam_for_all);
	return (ft_rand_perturbation_p2(rnd));
}

static void		ft_parse_perturbation_p2(char **line, int *i,
	t_color (**ft_perturbation)(t_phpa *, t_obj *))
{
	if (!ft_strcmp(line[*i + 1], "damfa"))
		*ft_perturbation = &ft_perturbation_dam_for_all;
	else if (!ft_strcmp(line[*i + 1], "dam"))
		*ft_perturbation = &ft_perturbation_dam;
	else if (!ft_strcmp(line[*i + 1], "lin"))
		*ft_perturbation = &ft_perturbation_line;
	else if (!ft_strcmp(line[*i + 1], "col"))
		*ft_perturbation = &ft_perturbation_colone;
	else if (!ft_strcmp(line[*i + 1], "square"))
		*ft_perturbation = &ft_perturbation_sqare;
	else if (!ft_strcmp(line[*i + 1], "atrou"))
		*ft_perturbation = &ft_perturbation_a_trous;
	else if (!ft_strcmp(line[*i + 1], "~"))
		*ft_perturbation = ft_rand_perturbation();
}

int				ft_parse_perturbation(char **line, int *i,
	t_color (**ft_perturbation)(t_phpa *, t_obj *))
{
	if (line[*i + 1] == NULL)
		return (0);
	if (!ft_strcmp(line[*i + 1], "uni"))
		*ft_perturbation = &ft_perturbation_uni;
	else if (!ft_strcmp(line[*i + 1], "rand*"))
		*ft_perturbation = &ft_perturbation_random;
	else if (!ft_strcmp(line[*i + 1], "hrndtc"))
		*ft_perturbation = &ft_perturbation_half_rnd_two_color;
	else if (!ft_strcmp(line[*i + 1], "colfa"))
		*ft_perturbation = &ft_perturbation_colone_for_all;
	else if (!ft_strcmp(line[*i + 1], "linfa"))
		*ft_perturbation = &ft_perturbation_line_for_all;
	ft_parse_perturbation_p2(line, i, ft_perturbation);
	*i += 1;
	return (1);
}
