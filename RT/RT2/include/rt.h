/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 13:02:41 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/08 15:27:05 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <libxml/xmlmemory.h>
# include <libxml/parser.h>

# include "keycodes.h"
# include "libft.h"
# include "libmtx.h"
# include "libbmp.h"
# include "SDL.h"

# include "rt_class.h"
# include "rt_fct.h"

# define LIMIT_MIN 0.00001
# define POW2(x) (x*x)
# define DOTV(a, b) (a.mtx[0]*b.mtx[0] + a.mtx[1]*b.mtx[1] + a.mtx[2]*b.mtx[2])
# define NEAR(a, b) (a - LIMIT_MIN < b && b < a + LIMIT_MIN)
# define MIN(a, b) ((a < b) ? a : b)
# define MAX(a, b) ((a > b) ? a : b)
# define FILEPATH "./res/audio/223.wav"

#endif
