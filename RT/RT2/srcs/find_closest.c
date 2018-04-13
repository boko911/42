/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:58:52 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/08 15:04:17 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	find_closest(t_scene *scene, t_ray *ray)
{
	t_list	*current;
	t_obj	*obj;
	double	t;

	ray->obj_closest = NULL;
	current = scene->objects;
	while (current)
	{
		obj = (t_obj *)current->content;
		if ((t = obj->inter(obj, *ray)) > LIMIT_MIN
			&& (t < ray->t || ray->obj_closest == NULL))
		{
			ray->t = t;
			ray->obj_closest = (t_obj *)current->content;
		}
		current = current->next;
	}
	return (ray->obj_closest != NULL);
}

char	find_closest_blindly(t_scene *scene, t_ray *ray, double t,
	double *coef_refrac)
{
	t_list	*current;
	t_obj	*obj;
	double	t_inter;

	current = scene->objects;
	ray->obj_closest = NULL;
	while (current)
	{
		obj = (t_obj *)current->content;
		if (aabb(ray, obj) && (t_inter = obj->inter(obj, *ray)) > LIMIT_MIN &&
			t_inter < t)
		{
			*coef_refrac *= obj->mat->refra;
			if (*coef_refrac <= 0.001)
				return (0);
		}
		current = current->next;
	}
	return (1);
}

char	find_closest_light(t_scene *scene, t_ray *ray,
	double *t_coef_refrac, t_obj *obj_closet)
{
	t_list		*current;
	t_obj		*obj;
	double		dist_tmp;

	t_coef_refrac[1] = 1.0;
	current = scene->objects;
	ray->t = t_coef_refrac[0];
	ray->t = obj_closet->inter(obj_closet, *ray);
	ray->obj_closest = obj_closet;
	while (current)
	{
		obj = (t_obj *)current->content;
		if ((dist_tmp = obj->inter(obj, *ray)) > LIMIT_MIN &&
			(dist_tmp < ray->t))
		{
			t_coef_refrac[1] *= obj->mat->refra;
			if (t_coef_refrac[1] <= 0.001)
			{
				ray->obj_closest = (t_obj *)current->content;
				ray->t = dist_tmp;
			}
		}
		current = current->next;
	}
	return (ray->obj_closest != NULL);
}
