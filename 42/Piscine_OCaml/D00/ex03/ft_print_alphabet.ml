(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_print_alphabet.ml                               :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/13 11:32:54 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/13 11:40:25 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec ft_print_chars_range x y =
  if x <= y then (
    print_char (char_of_int x);
    ft_print_chars_range (x+1) y
  ) else
    print_char '\n'

let ft_print_alphabet () =
  ft_print_chars_range 0x61 0x7a


let main () =
  ft_print_alphabet ()

let () = main ()
