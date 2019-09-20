(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_is_palindrome.ml                                :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/13 14:04:22 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/14 21:05:49 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec ft_is_palindrome_rec str i length =
  if i <= length then
    str.[i] == str.[length] && ft_is_palindrome_rec str (i+1) (length-1)
  else
    true

let ft_is_palindrome str =
  ft_is_palindrome_rec str 0 ((String.length str)-1)


let main () =
  print_string "Test with [radar] : ";
  print_endline (string_of_bool (ft_is_palindrome "radar"));
  print_string "Test with [madam] : ";
  print_endline (string_of_bool (ft_is_palindrome "madam"));
  print_string "Test with [] : ";
  print_endline (string_of_bool (ft_is_palindrome ""));
  print_string "Test with [car] : ";
  print_endline (string_of_bool (ft_is_palindrome "car"));
  print_string "Test with [a] : ";
  print_endline (string_of_bool (ft_is_palindrome "a"));
  print_string "Test with [ab] : ";
  print_endline (string_of_bool (ft_is_palindrome "ab"));
  print_string "Test with [aba] : ";
  print_endline (string_of_bool (ft_is_palindrome "aba"));
  print_string "Test with [abab] : ";
  print_endline (string_of_bool (ft_is_palindrome "abab"));
  print_string "Test with [baba] : ";
  print_endline (string_of_bool (ft_is_palindrome "baba"));
  print_string "Test with [abba] : ";
  print_endline (string_of_bool (ft_is_palindrome "abba"));
  print_string "Test with [lol] : ";
  print_endline (string_of_bool (ft_is_palindrome "lol"));
  print_string "Test with [emilenuaunelime] : ";
  print_endline (string_of_bool (ft_is_palindrome "emilenuaunelime"))


let () = main ()
