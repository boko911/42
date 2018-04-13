/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_blindly_p2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:41:10 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/08 15:02:56 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_is_inscene_p2(t_mtx light_pos, t_mtx dir_beg, t_mtx dir_end)
{
	double	ecart_x;
	double	ecart_y;
	double	ecart_z;

	ecart_x = VOM(dir_end, 0, 0) - VOM(dir_beg, 0, 0);
	ecart_y = VOM(dir_end, 1, 0) - VOM(dir_beg, 1, 0);
	ecart_z = VOM(dir_end, 2, 0) - VOM(dir_beg, 2, 0);
	if (ecart_x <= ecart_y && ecart_x <= ecart_z)
	{
		ft_swap_double(&dir_beg.mtx[0], &dir_beg.mtx[2]);
		ft_swap_double(&dir_end.mtx[0], &dir_end.mtx[2]);
	}
	else if (ecart_y < ecart_x && ecart_y <= ecart_z)
	{
		ft_swap_double(&dir_beg.mtx[1], &dir_beg.mtx[2]);
		ft_swap_double(&dir_end.mtx[1], &dir_end.mtx[2]);
	}
	if (VOM(dir_beg, 0, 0) <= VOM(light_pos, 0, 0) &&
		VOM(light_pos, 0, 0) <= VOM(dir_end, 0, 0) &&
		VOM(dir_beg, 1, 0) <= VOM(light_pos, 1, 0) &&
		VOM(light_pos, 1, 0) <= VOM(dir_end, 1, 0) &&
		VOM(dir_beg, 2, 0) <= VOM(light_pos, 2, 0) &&
		VOM(light_pos, 2, 0) <= VOM(dir_end, 2, 0) * 2.0)
		return (1);
	return (0);
}

int			ft_is_inscene(t_mtx light_pos, t_mtx cam_pos, t_mtx *beg_end)
{
	t_mtx	dir_beg;
	t_mtx	dir_end;

	dir_beg = mtx_init_mtx(beg_end[0]);
	dir_end = mtx_init_mtx(beg_end[1]);
	light_pos = norm_vect(mtx_sub(light_pos, cam_pos));
	if (VOM(dir_beg, 0, 0) > VOM(dir_end, 0, 0))
		ft_swap_double(&dir_beg.mtx[0], &dir_end.mtx[0]);
	if (VOM(dir_beg, 1, 0) > VOM(dir_end, 1, 0))
		ft_swap_double(&dir_beg.mtx[1], &dir_end.mtx[1]);
	if (VOM(dir_beg, 2, 0) > VOM(dir_end, 2, 0))
		ft_swap_double(&dir_beg.mtx[2], &dir_end.mtx[2]);
	return (ft_is_inscene_p2(light_pos, dir_beg, dir_end));
}
