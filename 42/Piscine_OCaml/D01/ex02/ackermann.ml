(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ackermann.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/14 13:36:56 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/14 13:45:10 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec ackermann m n =
  if m < 0 || n < 0 then
    (-1)
  else if m == 0 then
    (n + 1)
  else if n == 0 && m > 0 then
    ackermann (m-1) 1
  else
    ackermann (m-1) (ackermann m (n-1))



let () =
  print_string "Test with [-1 7] : "; print_int (ackermann (-1) 7);
  print_char '\n';
  print_string "Test with [0 0] : "; print_int (ackermann 0 0);
  print_char '\n';
  print_string "Test with [2 3] : "; print_int (ackermann 2 3);
  print_char '\n';
  print_string "Test with [4 1] : "; print_int (ackermann 4 1);
  print_char '\n';
