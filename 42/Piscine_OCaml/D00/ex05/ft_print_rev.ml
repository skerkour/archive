(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_print_rev.ml                                    :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/13 12:22:44 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/14 20:54:02 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec ft_print_rev_rec str length =
  if length >= 0 then (
    print_char str.[length];
    ft_print_rev_rec str (length-1)
  ) else
    print_char '\n'

let ft_print_rev str =
  ft_print_rev_rec str ((String.length str)-1)

let main () =
  ft_print_rev "lol";
  ft_print_rev "";
  ft_print_rev "abcd";
  ft_print_rev "abcde";
  ft_print_rev "Hello world !"

let () = main ()
