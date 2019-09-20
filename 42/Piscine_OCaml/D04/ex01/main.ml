(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/17 10:28:41 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/17 15:04:18 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let print_title title =
  print_endline "-----------------------------------";
  print_endline title;
  print_endline "-----------------------------------"

let () =
  print_title "ToXXX";
  let rec print_to_xxx = ( function
    | [] -> ()
    | head::tail -> (
      print_string @@ Value.toString head; print_string " -> ";
      print_string @@ Value.toStringVerbose head; print_string " -> ";
      print_int @@ Value.toInt head; print_char '\n';
      print_to_xxx tail
    )
  ) in
  print_to_xxx Value.all;

  print_title "NEXT";
  let rec print_next = ( function
    | [] -> ()
    | head::tail when head = Value.As -> print_next tail
    | head::tail -> (
      print_string @@ Value.toString head; print_string " -> ";
      print_string @@ Value.toString @@ Value.next head; print_char '\n';
      print_next tail
    )
  ) in
  print_next Value.all;
  
  print_title "PREVIOUS";
  let rec print_previous = ( function
    | [] -> ()
    | head::tail when head = Value.T2 -> print_previous tail
    | head::tail -> (
      print_string @@ Value.toString head; print_string " -> ";
      print_string @@ Value.toString @@ Value.previous head; print_char '\n';
      print_next tail
    )
  ) in
  print_previous Value.all
