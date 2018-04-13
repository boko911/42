/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:24:06 by agrosset          #+#    #+#             */
/*   Updated: 2018/01/29 13:40:00 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	#include <fcntl.h>
*/

static char	ft_strstartwith(char *str, char *start)
{
	while (ft_isspace(*str))
		str++;
	while (*start)
	{
		if (*start != *str)
			return (0);
		start++;
		str++;
	}
	return (1);
}

static int	ft_parse_args_p2(t_env *env, int *i, char **argv)
{
	if (ft_strstartwith(argv[*i], "-w"))
	{
		if (!parse_int(argv, i, &env->width))
			return (return_print("Error parsing -w [n]", -1));
		else if (env->width <= 0)
			return (return_print("Width can't be below 1!", -1));
	}
	else if (ft_strstartwith(argv[*i], "-h"))
	{
		if (!parse_int(argv, i, &env->height))
			return (return_print("Error parsing -h [n]", -1));
		else if (env->height <= 0)
			return (return_print("Height can't be below 1!", -1));
	}
	else
	{
		ft_putendl("Unknown parameter : ");
		return (return_print(argv[*i], -1));
	}
	return (0);
}

static int	ft_parse_arg(t_env *env, int argc, int *i, char **argv)
{
	if (ft_strstartwith(argv[*i], "-t") && *i + 1 < argc)
	{
		if (!parse_int(argv, i, &env->n_threads))
			return (return_print("Error parsing -t [n]", -1));
		else if (env->n_threads <= 0)
			return (return_print("Number of threads can't be below 1!", -1));
	}
	else if (ft_strstartwith(argv[*i], "-T"))
		env->print_time = 1;
	else if (ft_strstartwith(argv[*i], "-H") || ft_strstartwith(argv[*i], "-?"))
		print_usage(argv[0]);
	else if (ft_strstartwith(argv[*i], "-o"))
	{
		if (env->outputname)
			return (return_print("One file at time!", -1));
		env->outputname = argv[++*i];
	}
	else if (ft_strstartwith(argv[*i], "-p"))
		env->play_sound = 1;
	else
		ft_parse_args_p2(env, i, argv);
	return (0);
}

int			ft_parse_args(t_env *env, int argc, char **argv)
{
	int		i;
	int		file_parsed;

	i = 0;
	file_parsed = -1;
	while (++i < argc)
	{
		if (ft_strstartwith(argv[i], "-"))
		{
			if (ft_parse_arg(env, argc, &i, argv) == -1)
				return (-1);
		}
		else if (i == argc - 1)
		{
			if (ft_parse_file(env, argv[i]) == -1)
				return (-1);
			else
				file_parsed = 0;
		}
	}
	return (file_parsed);
}
