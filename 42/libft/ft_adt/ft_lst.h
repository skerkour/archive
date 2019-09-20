/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 20:56:20 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/22 09:49:00 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

# include <stdlib.h>

# include "../libft.h"

typedef struct	s_lst
{
	void			*data;
	size_t			size;
	struct s_lst	*next;
}				t_lst;

void			ft_lstpush(t_lst **top, t_lst *elem);

t_lst			*ft_lstpop(t_lst **top);

void			ft_lstadd_end(t_lst **top, t_lst *elem);

t_lst			*ft_lstpeek(t_lst **top);

void			ft_lstdel_end(t_lst **top, void (*del)(t_lst*));

t_lst			*ft_lstnew(void *data, size_t size);

void			ft_lstadd_srt(t_lst **top, t_lst *elem,
					int (*cmp)(t_lst*, t_lst*));

void			ft_lstdelone(t_lst **alst, void (*del)(void *, size_t));

void			ft_lstadd_rev(t_lst **top, t_lst *elem,
						int (*cmp)(t_lst*, t_lst*));

void			ft_lstdeli(t_lst **top, size_t pos, void (*del)(t_lst*));

size_t			ft_lstlen(t_lst *lst);

void			ft_lstaddi(t_lst **top, t_lst *elem, size_t pos);

void			ft_lstrev(t_lst **begin_list);

void			ft_lstpush_back(t_lst **top, t_lst *elem);

/*
** Copy the list elements in an array
** this function assume that all the elements are of the same data type
*/
void			*ft_lst_to_array(t_lst *lst);

#endif
