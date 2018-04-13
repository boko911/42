/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:11:52 by nbuhler           #+#    #+#             */
/*   Updated: 2018/03/31 17:11:54 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		parse_camera(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur)
{
	cur = cur->xmlChildrenNode;
	xml->scene = ft_strcat(xml->scene, "\n\n--Camera declaration\ncamera");
	while (cur != NULL)
	{
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"POSITION")))
			parse_scene_arg(xml, " position ", doc, cur);
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"ROTATION")))
			parse_scene_arg(xml, " rotation ", doc, cur);
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"SCREEN")))
			parse_scene_arg(xml, " screen ", doc, cur);
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"FOV")))
			parse_scene_arg(xml, " fov ", doc, cur);
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"ANTIALIASING")))
			parse_scene_arg(xml, " antialiasing ", doc, cur);
		cur = cur->next;
	}
}

void		shape_arg(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur)
{
	xmlChar	*key;

	if ((!xmlStrcmp(cur->name, (const xmlChar *)"TYPE")))
	{
		key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		xml->scene = ft_strcat(xml->scene, (char*)key);
		xmlFree(key);
	}
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"POSITION")))
		parse_scene_arg(xml, " position ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"ROTATION")))
		parse_scene_arg(xml, " rotation ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"RADIUS")))
		parse_scene_arg(xml, " radius ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"ANGLE")))
		parse_scene_arg(xml, " angle ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"MATERIAL")))
		parse_scene_arg(xml, " material ", doc, cur);
}

void		parse_shape(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur)
{
	cur = cur->xmlChildrenNode;
	xml->scene = ft_strcat(xml->scene, "\n\n--Shape declaration\n");
	while (cur != NULL)
	{
		shape_arg(xml, doc, cur);
		cur = cur->next;
	}
}

void		parse_light(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur)
{
	cur = cur->xmlChildrenNode;
	xml->scene = ft_strcat(xml->scene, "\n\n--Light declaration\nlight");
	while (cur != NULL)
	{
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"POSITION")))
			parse_scene_arg(xml, " position ", doc, cur);
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"COLOR")))
			parse_scene_arg(xml, " color ", doc, cur);
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"POWER")))
			parse_scene_arg(xml, " power ", doc, cur);
		cur = cur->next;
	}
}

void		parse_image(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur)
{
	cur = cur->xmlChildrenNode;
	xml->scene = ft_strcat(xml->scene, "\n\n--Image declaration\nimage");
	while (cur != NULL)
	{
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"ID")))
			parse_scene_arg(xml, " id ", doc, cur);
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"NAME")))
			parse_scene_arg(xml, " name ", doc, cur);
		cur = cur->next;
	}
}
