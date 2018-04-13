/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:19:20 by nbuhler           #+#    #+#             */
/*   Updated: 2018/04/04 14:48:04 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			parsedoc_1(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur)
{
	while (cur != NULL)
	{
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"SCENE")))
			parse_scene(xml, doc, cur);
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"CAMERA")))
			parse_camera(xml, doc, cur);
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"LIGHT")))
			parse_light(xml, doc, cur);
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"IMAGE")))
			parse_image(xml, doc, cur);
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"TEXTURE")))
			parse_texture(xml, doc, cur);
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"MATERIAL")))
			parse_material(xml, doc, cur);
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"SHAPE")))
			parse_shape(xml, doc, cur);
		cur = cur->next;
	}
}

static char		*parsedoc(t_xml *xml, char *docname)
{
	xmlDocPtr	doc;
	xmlNodePtr	cur;

	doc = xmlParseFile(docname);
	if (doc == NULL)
		return (NULL);
	cur = xmlDocGetRootElement(doc);
	if (cur == NULL)
	{
		ft_putendl("empty document\n");
		xmlFreeDoc(doc);
		return (NULL);
	}
	if (xmlStrcmp(cur->name, (const xmlChar *)"RT"))
	{
		ft_putendl("document of the wrong type, root node != RT");
		xmlFreeDoc(doc);
		return (NULL);
	}
	cur = cur->xmlChildrenNode;
	parsedoc_1(xml, doc, cur);
	xmlFreeDoc(doc);
	return (xml->scene);
}

void			translate_xml_to_char(char *file)
{
	FILE		*fichier;
	t_xml		*xml;

	if ((xml = (t_xml *)ft_memalloc(sizeof(t_xml))) == NULL)
	{
		ft_putendl("malloc error: env");
		exit(-1);
	}
	fichier = fopen("cor/demotranslated", "w");
	if (fichier != NULL)
	{
		fprintf(fichier, "%s", parsedoc(xml, file));
		fclose(fichier);
	}
	free(xml);
}
