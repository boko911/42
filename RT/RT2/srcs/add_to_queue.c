/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 13:13:38 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/16 16:26:03 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		add_to_queue(t_env *env, void (*method)(t_env *env))
{
	t_list		*list;

	list = ft_lstnewfrom(method, sizeof(method));
	pthread_mutex_lock(&env->queuemutex);
	if (!env->queue)
		env->queue = list;
	else
		ft_lstaddend(env->queue, list);
	pthread_mutex_unlock(&env->queuemutex);
}
