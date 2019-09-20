(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_string_all.ml                                   :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/13 13:38:03 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/14 20:56:40 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec ft_string_all_rec fn str length =
  if length >= 0 then
    fn str.[length] && ft_string_all_rec fn str (length-1)
  else
    true

let ft_string_all fn str =
  ft_string_all_rec fn str ((String.length str)-1)



let is_digit c = c >= '0' && c <= '9'

let main () =
  print_string "Test with [0123456789] : ";
  print_endline (string_of_bool (ft_string_all is_digit "0123456789"));
  print_string "Test with [0123456789B] : ";
  print_endline (string_of_bool (ft_string_all is_digit "0123456789B"));
  print_string "Test with [B0123456789] : ";
  print_endline (string_of_bool (ft_string_all is_digit "B0123456789"));
  print_string "Test with [a] : ";
  print_endline (string_of_bool (ft_string_all is_digit "a"));
  print_string "Test with [Bbbbbbbbbbbbbbbbbb] : ";
  print_endline (string_of_bool (ft_string_all is_digit "Bbbbbbbbbbbbbbbbbb"));
  print_string "Test with [] : ";
  print_endline (string_of_bool (ft_string_all is_digit ""));
  print_string "Test with [1] : ";
  print_endline (string_of_bool (ft_string_all is_digit "1"))


let () = main ()
