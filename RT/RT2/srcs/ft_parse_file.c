/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 12:35:59 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/04 14:48:34 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			ft_delete_line_array(char **line, int return_state)
{
	char	**oline;

	oline = line;
	while (*line)
	{
		free(*line);
		line++;
	}
	free(oline);
	return (return_state);
}

int			ft_parse_file(t_env *env, char *file)
{
	int		fd;

	if (is_xml(file) == 1)
	{
		translate_xml_to_char(file);
		file = "cor/demotranslated";
	}
	if ((fd = open(file, O_RDONLY)) < 0)
		return (return_print("error while opening the file", -1));
	return (get_next_line_file(env, fd));
}
