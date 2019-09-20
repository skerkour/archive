(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   gardening.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/17 00:55:42 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/17 00:55:42 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let rec size = function
  | Nil -> 0
  | Node(_, l, r) -> 1 + (size l)  + (size r)

let rec height = function
  | Nil -> 0
  | Node(_, l, r) -> max (height l + 1) (height r + 1)

let draw_square x y size =
  let center = size / 2 in
  Graphics.moveto (x - center) (y - center);
  Graphics.lineto (x + center) (y - center);
  Graphics.lineto (x + center) (y + center);
  Graphics.lineto (x - center) (y + center);
  Graphics.lineto (x - center) (y - center)

let draw_tree tree =
	let square_size = 42 in
	let rec draw_tree x y = ( function
		| Node(v, left, right) -> (
			draw_square x y square_size;
			Graphics.moveto (x - (square_size / 3)) y;
			Graphics.draw_string v;
			if left <> Nil then (
				draw_tree (x + 84) (y + square_size) left;
				Graphics.moveto (x + square_size / 2) y;
				Graphics.lineto (x + 84 - (square_size / 2)) (y + square_size);
			);
			if right <> Nil then (
				draw_tree (x + 84) (y - square_size) right;
				Graphics.moveto (x + square_size / 2) y;
				Graphics.lineto (x + 84 - (square_size / 2)) (y - square_size);
			);
		)
		| Nil -> (
			draw_square x y square_size;
			Graphics.moveto (x - (square_size / 3)) y;
			Graphics.draw_string "Nil";
		)
	)in
	draw_tree 300 300 tree


let () =
  Graphics.open_graph " 600x600";
	draw_tree (Node("1", Node("2", Node("3", Nil, Nil), Nil), Node("lol", Nil, Nil)));
  ignore (Graphics.read_key ());
	print_int @@ height (Node("1", Node("2", Node("3", Nil, Nil), Nil), Node("lol", Nil, Nil)));
	print_char '\n';
	print_int @@ size (Node("1", Node("2", Node("3", Nil, Nil), Nil), Node("lol", Nil, Nil)));
	print_char '\n'
