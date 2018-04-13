/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:11:45 by nbuhler           #+#    #+#             */
/*   Updated: 2018/03/31 17:11:48 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		parse_scene_arg(t_xml *xml, char *arg,
	xmlDocPtr doc, xmlNodePtr cur)
{
	char	*text;
	char	*tmp;
	char	*cpytext;
	xmlChar	*key;

	if (!(cpytext = (char *)malloc(sizeof(char) * 10000000)))
		exit(-1);
	key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
	text = ft_strjoin(arg, (char*)key);
	tmp = ft_strjoin(xml->scene, text);
	xml->scene = ft_strcpy(cpytext, tmp);
	free(cpytext);
	free(tmp);
	free(text);
	xmlFree(key);
}

void		scene_arg(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur)
{
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"AMBIANT")))
		parse_scene_arg(xml, " ambiant ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"BACKGROUND")))
		parse_scene_arg(xml, " background ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"AMBIANT_BASE_IMPACT")))
		parse_scene_arg(xml, " ambiant_base_impact ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"AMBIANT_COEF_IMPACT")))
		parse_scene_arg(xml, " ambiant_coef_impact ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"MAX_REFLEXION")))
		parse_scene_arg(xml, " max_reflexion ", doc, cur);
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"FILTER")))
		parse_scene_arg(xml, " filter ", doc, cur);
}

void		parse_scene_1(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur)
{
	while (cur != NULL)
	{
		scene_arg(xml, doc, cur);
		cur = cur->next;
	}
}

void		parse_scene(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur)
{
	cur = cur->xmlChildrenNode;
	xml->scene = "--Scene declaration, must be the first thing\nscene";
	parse_scene_1(xml, doc, cur);
}
