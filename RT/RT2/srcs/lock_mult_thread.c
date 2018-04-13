/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_mult_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:41:10 by agrosset          #+#    #+#             */
/*   Updated: 2018/02/16 14:22:53 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_lock_mult_thread(t_env *env)
{
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	if (env->n_threads > 1)
		pthread_mutex_lock(&env->mutex);
}

void	ft_unlock_mult_thread(t_env *env)
{
	if (env->n_threads > 1)
		pthread_mutex_unlock(&env->mutex);
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	pthread_testcancel();
}
