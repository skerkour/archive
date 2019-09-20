/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 16:36:13 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/13 18:31:10 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# define FT_RL_ESC 0x1b
# define FT_RL_DEL 0x7f
# define FT_RL_TAB 0x09

/*
** http://www.unix-manuals.com/refs/misc/ascii-table.html
*/

# define FT_RL_CTRL_K 0xb
# define FT_RL_CTRL_L 0x0c
# define FT_RL_CTRL_X 0x18
# define FT_RL_CTRL_D 0x4

# define FT_RL_UP 0x41
# define FT_RL_DOWN 0x42
# define FT_RL_RIGHT 0x43
# define FT_RL_LEFT 0x44

char	*ft_readline(char *header);

#endif
