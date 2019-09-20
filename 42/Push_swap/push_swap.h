/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 16:25:28 by skerkour          #+#    #+#             */
/*   Updated: 2015/03/30 17:36:42 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef PS
#  define PS(x) ps_putchar(x, ' ')
# endif

enum
{
	PS_FLAG_c = 1 << 0,
	PS_FLAG_h = 1 << 1,
	PS_FLAG_l = 1 << 2,
	PS_FLAG_n = 1 << 3,
	PS_FLAG_v = 1 << 4,
	PS_FLAG_V = 1 << 5,
	PS_FLAG_d = 1 << 6
};

typedef struct	s_ps_stack
{
	int					n;
	struct s_ps_stack	*next;
}				t_ps_stack;

typedef struct	s_ps_ctx
{
	int			flags;
	t_ps_stack	*a;
	t_ps_stack	*b;
	t_uint		n_ops;
	t_uint		a_len;
	t_uint		a_mid;
	t_uint		n_sorted;
}				t_ps_ctx;

/*
** main.c
*/
void			ps_error(void);
void			ps_putchar(t_ps_ctx *ctx, char c);

/*
** ps_args.c
*/
void			ps_parse_args(t_ps_ctx *ctx, char **av, int ac);
t_uint			ps_stack_get_len(t_ps_stack *stck);

/*
** ps_ops.c
***
** - sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a.
**	(ne fait rien s’il n’y en a qu’un ou aucun).
** - sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b.
**	(ne fait rien s’il n’y en a qu’un ou aucun).
** - ss : sa et sb en même temps.
** - pa : push a - prend le premier élément au sommet de b et le met sur a.
**	(ne fait rien si b est vide).
** - pb : push b - prend le premier élément au sommet de a et le met sur b.
**	(ne fait rien si a est vide).
*/
void			ps_sa(t_ps_ctx *ctx, t_ps_stack **a, t_bool print);
void			ps_sb(t_ps_ctx *ctx, t_ps_stack **b, t_bool print);
void			ps_ss(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b);
void			ps_pa(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b);
void			ps_pb(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b);

/*
** ps_ops2.c
***
** - ra : rotate a - décale d’une position tous les élements de la pile a.
**	(vers le haut, le premier élément devient le dernier).
** - rb : rotate b - décale d’une position tous les élements de la pile b.
** (vers le haut, le premier élément devient le dernier).
** - rr : ra et rb en meme temps.
*/
void			ps_ra(t_ps_ctx *ctx, t_ps_stack **a, t_bool print);
void			ps_rb(t_ps_ctx *ctx, t_ps_stack **b, t_bool print);
void			ps_rr(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b);

/*
** ps_ops3.c
***
** - rra : reverse rotate a (vers le bas, le dernier élément devient le premi
** - rrb : reverse rotate b (vers le bas, le dernier élément devient le premi
** - rrr : rra et rrb en même temps.
*/
void			ps_rra(t_ps_ctx *ctx, t_ps_stack **a, t_bool print);
void			ps_rrb(t_ps_ctx *ctx, t_ps_stack **b, t_bool print);
void			ps_rrr(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b);

/*
** ps_push_swap.c
*/
void			ps_sort_only_bot(t_ps_ctx *ctx, t_ps_stack **a);
void			ps_push_swap(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b);

/*
** ps_stack.c
*/
void			ps_stack_print_both(t_ps_stack *a, t_ps_stack *b);
int				ps_stack_peek(t_ps_stack *stack);
int				ps_stack_pop(t_ps_stack **stck);
void			ps_stack_push(t_ps_stack **stck, int n);
int				ps_stack_is_already_in(t_ps_stack *stck, int n);

/*
** ps_stack2.c
*/
t_uint			ps_stack_getmin_pos(t_ps_ctx *ctx, t_ps_stack *stck);
t_uint			ps_stack_get_nsorted(t_ps_stack *stck);

/*
** ps_stack3.c
*/
int				ps_stack_is_sorted_exceptbot(t_ps_stack *stck);
int				ps_stack_is_sorted_excepttop(t_ps_stack *stck);
int				ps_stack_is_sorted_inv(t_ps_stack *stck);
int				ps_stack_is_sorted(t_ps_stack *stck);
int				ps_stack_getmin_value(t_ps_stack *stck);

/*
** ps_stack4.c
*/
void			ps_sort_3(t_ps_ctx *ctx, t_ps_stack **a);
void			ps_sort_5(t_ps_ctx *ctx, t_ps_stack **a, t_ps_stack **b);
int				ps_nomiddlevalu(t_ps_stack *stck, int n, int n2);

#endif
