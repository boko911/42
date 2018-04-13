/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_shortcuts.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 13:41:58 by agrosset          #+#    #+#             */
/*   Updated: 2016/07/21 14:32:51 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUADRIC_SHORTCUTS_H
# define QUADRIC_SHORTCUTS_H

# define XO mtxs[0].mtx[0]
# define YO mtxs[0].mtx[1]
# define ZO mtxs[0].mtx[2]
# define XD mtxs[1].mtx[0]
# define YD mtxs[1].mtx[1]
# define ZD mtxs[1].mtx[2]

# define AX obj->mtx.mtx[0]
# define BX obj->mtx.mtx[5]
# define CX obj->mtx.mtx[10]
# define DX (obj->mtx.mtx[6] + obj->mtx.mtx[9])
# define EX (obj->mtx.mtx[2] + obj->mtx.mtx[8])
# define FX (obj->mtx.mtx[1] + obj->mtx.mtx[4])
# define GX (obj->mtx.mtx[12] + obj->mtx.mtx[3])
# define HX (obj->mtx.mtx[13] + obj->mtx.mtx[7])
# define IX (obj->mtx.mtx[14] + obj->mtx.mtx[11])
# define JX obj->mtx.mtx[15]

#endif
