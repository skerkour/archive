(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   iter.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/14 14:42:13 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/15 21:48:22 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec iter fn x n =
  if n < 0 then
    -1
  else if n == 0 then
    x
  else
    iter fn (fn x) (n-1)

let () =
  print_string "Test with [(fun x -> x * x) 2 4] : ";
  print_int (iter (fun x -> x * x) 2 4);
  print_char '\n';
  print_string "Test with [(fun x -> x * 2) 2 4] : ";
  print_int (iter (fun x -> x * 2) 2 4);
  print_char '\n';
  print_string "Test with [(fun x -> x * 2) 2 10] : ";
  print_int (iter (fun x -> x * 2) 2 10);
  print_char '\n';
  print_string "Test with [(fun x -> x * 2) 2 14] : ";
  print_int (iter (fun x -> x * 2) 2 14);
  print_char '\n';
