(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_graphics.ml                                     :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/16 14:00:30 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/16 16:06:02 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let draw_square x y size =
  let center = size / 2 in
  Graphics.moveto (x - center) (y - center);
  Graphics.lineto (x + center) (y - center);
  Graphics.lineto (x + center) (y + center);
  Graphics.lineto (x - center) (y + center);
  Graphics.lineto (x - center) (y - center)

let draw_tree_node tree =
	let square_size = 42 in
	let rec draw_tree_node x y = ( function
		| Node(v, left, right) -> (
			draw_square x y square_size;
			Graphics.moveto (x - (square_size / 3)) y;
			Graphics.draw_string v;
			draw_tree_node (x + 84) (y + square_size) left;
			Graphics.moveto (x + square_size / 2) y;
			Graphics.lineto (x + 84 - (square_size / 2)) (y + square_size);
			draw_tree_node (x + 84) (y - square_size) right;
			Graphics.moveto (x + square_size / 2) y;
			Graphics.lineto (x + 84 - (square_size / 2)) (y - square_size);
		)
		| Nil -> (
			draw_square x y square_size;
			Graphics.moveto (x - (square_size / 3)) y;
			Graphics.draw_string "Nil";
		)
	)in
	draw_tree_node 300 300 tree


let () =
  Graphics.open_graph " 600x600";
  draw_square 42 42 42;
	draw_tree_node (Node("value", Nil, Nil));
  ignore (Graphics.read_key ())
