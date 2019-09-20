/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 21:17:25 by skerkour          #+#    #+#             */
/*   Updated: 2016/01/21 16:21:23 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include "../libft.h"

typedef struct	s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*data;
	size_t			size;
}				t_btree;

void			ft_btree_apply_infix(t_btree *root,
					void (*applyf)(t_btree*));

void			ft_btree_apply_prefix(t_btree *root,
					void (*applyf)(t_btree*));

void			ft_btree_apply_suffix(t_btree *root,
					void (*applyf)(t_btree*));

t_btree			*ft_btree_create_node(void *data, size_t size);

void			ft_btree_insert_data(t_btree **root, void *data,
					int (*cmpf)(void*, void*, size_t));

int				ft_btree_lvl_c(t_btree *root);

void			*ft_btree_search_item(t_btree *root, void *data_ref,
					size_t size, int (*cmpf)(void*, void*, size_t));

#endif
