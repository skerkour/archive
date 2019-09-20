(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   gray.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/15 17:45:14 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/16 21:33:28 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let gray n =
  let rec lst_print_string lst = (
    match lst with
    | h::t -> (
      print_string h; print_char ' ';
      lst_print_string t
    )
    | [] -> print_char '\n'
  ) in

  let rec concat a b = (
    match a with
    | h::t -> h :: (concat t b)
    | [] -> b
  ) in

  let rec lst_map lst fn = (
    match lst with
    | h::t -> fn h :: (lst_map t fn)
    | [] -> []
  ) in
 
  let rec lst_rev lst acc = (
    match lst with
    | h::t -> lst_rev t (h :: acc)
    | [] -> acc
  ) in

  let rec gray_aux n = (
    if n <= 1 then
      ["0"; "1"]
    else
      let g = gray_aux (n-1) in
    concat (lst_map g ((^) "0")) (lst_map (lst_rev [] g) ((^) "1"))
  ) in

  if n <= 0 then
    print_char '\n'
  else
    lst_print_string @@ gray_aux n


(* tests *)
let () =
  print_string "Test with -1 : "; gray (-1);
  print_string "Test with 0 : "; gray (0);
  print_string "Test with 1 : "; gray (1);
  print_string "Test with 2 : "; gray (2);
  print_string "Test with 3 : "; gray (3);
  print_string "Test with 4 : "; gray (4);
  print_string "Test with 12 : "; gray (12)
