/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:18:13 by nbuhler           #+#    #+#             */
/*   Updated: 2018/03/31 17:18:14 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		parse_texture(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur)
{
	cur = cur->xmlChildrenNode;
	xml->scene = ft_strcat(xml->scene, "\n\n--Texture declaration\ntexture");
	while (cur != NULL)
	{
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"ID")))
			parse_scene_arg(xml, " id ", doc, cur);
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"IMAGE")))
			parse_scene_arg(xml, " image ", doc, cur);
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"ELARGE")))
			parse_scene_arg(xml, " elarge ", doc, cur);
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"BEGIN")))
			parse_scene_arg(xml, " begin ", doc, cur);
		cur = cur->next;
	}
}

void		material_arg_1(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur)
{
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"SPECULAR")))
		parse_scene_arg(xml, " specular ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"SHININESS")))
		parse_scene_arg(xml, " shininess ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"REFLEXION")))
		parse_scene_arg(xml, " reflexion ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"REFRACTION")))
		parse_scene_arg(xml, " refraction ", doc, cur);
}

void		material_arg(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur)
{
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"ID")))
		parse_scene_arg(xml, " id ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"COLOR1")))
		parse_scene_arg(xml, " color1 ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"COLOR2")))
		parse_scene_arg(xml, " color2 ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"PERTURBATION")))
		parse_scene_arg(xml, " perturbation ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"TEXTURE")))
		parse_scene_arg(xml, " texture ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"AMBIANT")))
		parse_scene_arg(xml, " ambiant ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"DIFFUSE")))
		parse_scene_arg(xml, " diffuse ", doc, cur);
	material_arg_1(xml, doc, cur);
}

void		parse_material(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur)
{
	cur = cur->xmlChildrenNode;
	xml->scene = ft_strcat(xml->scene, "\n\n--Material declaration\nmaterial");
	while (cur != NULL)
	{
		material_arg(xml, doc, cur);
		cur = cur->next;
	}
}
