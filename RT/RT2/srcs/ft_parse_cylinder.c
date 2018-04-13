/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:28:51 by agrosset          #+#    #+#             */
/*   Updated: 2016/09/13 16:21:38 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_parse_cylinder_3(char **line, int *i, t_cylinder *obj)
{
	if (!ft_strcmp(line[i[0]], "radius"))
	{
		if (!parse_double(line, i, &obj->radius, 0))
			return (return_print("Error parsing cylinder radius", 0));
		else
		{
			if (obj->radius < 0)
				return (return_print("Error, radius can't be negative", 0));
			obj->radius = POW2(obj->radius);
		}
	}
	else if (!ft_strcmp(line[i[0]], "height"))
	{
		if (!parse_double(line, i, &obj->h, 0))
			return (return_print("Error parsing cylinder height", 0));
		else if (obj->h < 0)
			return (return_print("Error, height can't be negative", 0));
	}
	return (1);
}

static int	ft_parse_cylinder_2(char **line, int *i, t_objenv objenv)
{
	t_material	*mat;

	if (!ft_strcmp(line[i[0]], "position"))
	{
		if (!parse_mtx_trans(line, i, &objenv.tobj->trans))
			return (return_print("Error parsing cylinder position", 0));
		else
			i[1] |= 1;
	}
	else if (!ft_strcmp(line[i[0]], "rotation"))
	{
		if (!parse_mtx_rot(line, i, &objenv.tobj->rot))
			return (return_print("Error parsing cylinder rotation", 0));
	}
	else if (!ft_strcmp(line[i[0]], "material"))
	{
		if (line[i[0] + 1] == NULL || !(ft_strlen(line[i[0] + 1]) > 0)
			|| !(mat = get_material(objenv.env, line[++i[0]])))
			return (return_print("Error parsing cylinder material", 0));
		else
			objenv.obj->mat = mat;
	}
	return (ft_parse_cylinder_3(line, i, (t_cylinder *)objenv.obj));
}

int			ft_parse_cylinder(t_env *env, char **line)
{
	int			i[2];
	t_tobj		tobj;
	t_cylinder	*obj;
	t_list		*lst;

	if (env->scene == NULL)
		return (return_print("Error, a scene must be declared first", 0));
	if (!ft_alloc_cylinder(&obj, &lst))
		return (0);
	ft_init_cylinder(env, &tobj, obj, i);
	while (line[++i[0]])
		if (ft_parse_cylinder_2(line, i,
			set_objenv(env, (t_obj *)obj, &tobj)) == 0)
			ft_delete_cylinder(&lst, &obj);
	transform_object((t_obj *)obj, &tobj);
	obj->inter = cylinder_inter;
	obj->normal = cylinder_normal;
	if (env->scene->objects == NULL)
		env->scene->objects = lst;
	else
		ft_lstadd(&(env->scene->objects), lst);
	return (i[1] == 1 ? 1 : return_print("error cylinder imcomplete", 0));
}
