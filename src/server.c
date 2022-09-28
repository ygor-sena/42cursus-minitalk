/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:56:38 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/28 03:57:23 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	print_pid(void);
static void	print_message(int sig, siginfo_t *info, void *context);

int	main(void)
{
	print_pid();
	ft_signal(SIGUSR1, print_message);
	ft_signal(SIGUSR2, print_message);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

static void	print_pid(void)
{
	ft_putstr_fd("Server PID is: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(".\n", 1);
}

static void	print_message(int sig, siginfo_t *info, void *context)
{
	static size_t	byte;
	static t_byte	decoded_char;

	(void) context;
	if (sig == SIGUSR1)
		sig = 1;
	else if (sig == SIGUSR2)
		sig = 0;
	if (byte == 0 && decoded_char == 0)
		byte = 8;
	byte--;
	decoded_char += (sig & 1) << byte;
	if (byte == 0)
	{
		if (!decoded_char)
		{
			ft_putchar_fd('\n', 1);
			ft_kill(info->si_pid, SIGUSR1);
		}
		ft_putchar_fd(decoded_char, 1);
		byte = 8;
		decoded_char = 0;
	}
}
