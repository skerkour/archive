(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   uncipher.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/17 01:00:29 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/17 20:41:40 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let uncaesar str n =
  let caesar_char c = (
    if c >= 'a' && c <= 'z' then
      let cc = ((((int_of_char c) - 0x61) - n) mod 26) in
      if cc < 0 then char_of_int ((cc + (26 * (26 / n + 1))) + 0x61) else char_of_int (cc + 0x61)
    else if c >= 'A' && c <= 'Z' then
      let cc = ((((int_of_char c) - 0x41) - n) mod 26) in
      if cc < 0 then char_of_int ((cc + (26 * (26 / n + 1))) + 0x41) else char_of_int (cc + 0x41)
    else
      c
  ) in
  String.map caesar_char str

let unrot42 str =
  uncaesar str 42

let rec ft_uncrypt (str : string) fns =
  match fns with
  | head::tail -> ft_uncrypt (head str) tail
  | [] -> str
