/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturbation_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 12:41:32 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/02 19:27:41 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		ft_init_perturbation(t_phpa *ph, t_obj *obj,
	t_perturbation *perturbation, t_color (*fct_call)(t_phpa *, t_obj *))
{
	int	width;
	int	height;

	width = ph->camera->res.width;
	height = ph->camera->res.height;
	perturbation->obj = obj;
	perturbation->fct_call = fct_call;
	perturbation->frequence[0] = rand() % (width / 5) + 1;
	perturbation->frequence[1] = rand() % (height / 5) + 1;
	if (fct_call == &ft_perturbation_a_trous)
		perturbation->frequence[1] = rand() %
		(perturbation->frequence[0] / 2 + 1);
}

static int		ft_create_perturbation(t_perturbation **ret_perturbation)
{
	if ((*ret_perturbation =
		(t_perturbation *)ft_memalloc(sizeof(t_perturbation))) == NULL)
	{
		return (0);
		ft_putendl("malloc error: perturbation in phong");
	}
	return (1);
}

static void		ft_add_to_list(t_phpa *ph, t_list **lst_new)
{
	if (ph->perturbation == NULL)
		ph->perturbation = *lst_new;
	else
		ft_lstadd(&ph->perturbation, *lst_new);
}

t_perturbation	*get_perturbation(t_phpa *ph, t_obj *obj,
	t_color (*fct_call)(t_phpa *, t_obj *))
{
	t_list			*actuel;
	t_list			*lst_new;
	t_perturbation	*ret_perturbation;

	actuel = ph->perturbation;
	while (actuel != NULL)
	{
		ret_perturbation = (t_perturbation *)actuel->content;
		if (ret_perturbation->obj == obj &&
			ret_perturbation->fct_call == fct_call)
			return (ret_perturbation);
		actuel = actuel->next;
	}
	if (!ft_create_perturbation(&ret_perturbation))
		return (NULL);
	ft_init_perturbation(ph, obj, ret_perturbation, fct_call);
	if ((lst_new = ft_lstnew((void *)ret_perturbation,
		sizeof(t_perturbation))) == NULL)
	{
		free(ret_perturbation);
		return (NULL);
	}
	ft_add_to_list(ph, &lst_new);
	free(ret_perturbation);
	return ((t_perturbation *)lst_new->content);
}
