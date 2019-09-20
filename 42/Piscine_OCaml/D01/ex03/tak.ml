(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   tak.ml                                             :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/14 13:47:55 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/14 13:57:34 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

(*
 * tak(tak(x - 1, y, z), tak(y - 1, z, x), tak(z - 1, x, y)) if y<x
 * z otherwise
 *)

let rec tak x y z =
  if y < x then
    tak (tak (x-1) y z) (tak (y-1) z x) (tak (z-1) x y)
  else
    z

let () =
  print_string "Test with [1 2 3] : "; print_int (tak 1 2 3);
  print_char '\n';
  print_string "Test with [5 23 7] : "; print_int (tak 5 23 7);
  print_char '\n';
  print_string "Test with [9 1 0] : "; print_int (tak 9 1 0);
  print_char '\n';
  print_string "Test with [1 1 1] : "; print_int (tak 1 1 1);
  print_char '\n';
  print_string "Test with [0 42 0] : "; print_int (tak 0 42 0);
  print_char '\n';
  print_string "Test with [23498 98734 98776] : ";
  print_int (tak 23498 98734 98776);
  print_char '\n';
