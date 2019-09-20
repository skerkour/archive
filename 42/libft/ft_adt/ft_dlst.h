/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 21:20:00 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/21 15:52:10 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLST_H
# define FT_DLST_H

# include <stdlib.h>

# include "../libft.h"

typedef struct	s_dlst
{
	void			*data;
	size_t			size;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}				t_dlst;

t_dlst			*ft_dlstmew(void *data, size_t size);

void			ft_dlst_del(t_dlst **lst);

size_t			ft_dlstlen(t_dlst *list);

#endif
