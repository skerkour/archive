(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   repeat_x.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/14 11:43:45 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/15 21:16:25 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let repeat_x n =
  let rec repeat_x_aux n acc = (
    if n < 0 then
      "Error"
    else if n == 0 then
      acc
    else
      repeat_x_aux (n-1) (acc^"x")
  )
  in repeat_x_aux n ""

let () =
  print_string "Test with [-1] : "; print_string (repeat_x (-1));
  print_char '\n';
  print_string "Test with [0] : "; print_string (repeat_x 0); print_char '\n';
  print_string "Test with [1] : "; print_string (repeat_x 1); print_char '\n';
  print_string "Test with [2] : "; print_string (repeat_x 2); print_char '\n';
  print_string "Test with [12] : "; print_string (repeat_x 12); print_char '\n';
  print_string "Test with [5] : "; print_string (repeat_x 5); print_char '\n'
