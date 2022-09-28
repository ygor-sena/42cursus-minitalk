/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:07:47 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/28 00:36:36 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define SLEEP_TIME 800

# include "../libft/libft.h"
# include <signal.h>
# include <sys/types.h>

typedef void	t_handler(int, siginfo_t*, void*);

void			ft_kill(pid_t pid, int signum);
t_handler		*ft_signal(int signum, t_handler *handler);
#endif
