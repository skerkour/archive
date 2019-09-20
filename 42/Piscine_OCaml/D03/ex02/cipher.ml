(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   cipher.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/17 01:00:26 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/17 20:43:51 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let caesar str n =
  let caesar_char c = (
    if c >= 'a' && c <= 'z' then
      char_of_int (((((int_of_char c) - 0x61) + n) mod 26) + 0x61)
    else if c >= 'A' && c <= 'Z' then
      char_of_int (((((int_of_char c) - 0x41) + n) mod 26) + 0x41)
    else
      c
  ) in
  String.map caesar_char str

let rot42 str =
  caesar str 42

let xor str key =
  let xor_char c = (
    char_of_int ((int_of_char c) lxor key)
  ) in
  String.map xor_char str

let rec ft_crypt (str : string) fns =
  match fns with
  | head::tail -> ft_crypt (head str) tail
  | [] -> str

let () =
print_endline @@ Uncipher.uncaesar (caesar "lol" 10) 10;
  print_endline @@ Uncipher.uncaesar (caesar "lol" 28) 28;
  print_endline @@ Uncipher.unrot42 @@ rot42 "HELLO world !! ici a 42";
  print_endline @@ xor (xor "lol" 20) 20;
  print_endline @@ Uncipher.ft_uncrypt (ft_crypt "YOOOOO lololol ## 42" [rot42])
  [Uncipher.unrot42]
