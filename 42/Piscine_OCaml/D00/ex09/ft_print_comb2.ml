(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_print_comb2.ml                                  :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/13 14:49:57 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/13 15:01:27 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)


let print_n x y =
  if x < 10 then
    print_char '0';
  print_int x;
  print_char ' ';
  if y < 10 then
    print_char '0';
  print_int y


let rec ft_print_comb2_rec x y =
  if x <= y && x < 98 then (
    print_n x y; print_char ','; print_char ' ';
    if y >= 99 then
      ft_print_comb2_rec (x+1) (x+2)
    else
      ft_print_comb2_rec x (y+1)
  ) else (
    print_n x y;
    print_char '\n'
  )

let ft_print_comb2 () =
  ft_print_comb2_rec 0 0

let main () =
  ft_print_comb2 ()

let () = main ()
