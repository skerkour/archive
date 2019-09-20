(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_print_comb.ml                                   :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/13 11:42:20 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/13 12:19:21 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let print_n x y z str =
    print_int x; print_int y; print_int z; print_string str

let rec ft_print_comb_rec x y z =
  if x < y && y < z  && x < 7 then (
    print_n x y z ", ";
    if z >= 9 && y >=  8 then
      ft_print_comb_rec (x+1) (x+2) (x+3)
    else if z >= 9 then
      ft_print_comb_rec x (y+1) (y+2)
    else
      ft_print_comb_rec x y (z+1)
  ) else
    print_n x y z "\n"


let ft_print_comb () =
  ft_print_comb_rec 0 1 2


let main () =
  ft_print_comb ()

let () = main ()
