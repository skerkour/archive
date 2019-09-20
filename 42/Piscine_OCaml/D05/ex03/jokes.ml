(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   jokes.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/20 13:27:50 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/20 14:19:09 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let get_jokes file_name =
  let jokes = ref [||] in
  let continue = ref true in
  let file = open_in file_name in
  ( try 
    while !continue = true do
      let line = input_line file in
      jokes := Array.append !jokes [|line|];
    done;
  with
  | _ -> continue := false
  );
  close_in file;
  !jokes

let () =
  Random.self_init ();
  let argc = Array.length Sys.argv in
  let argv = Sys.argv in
  if argc <> 2 then ()
  else
    let jokes = get_jokes argv.(1) in
    print_endline (Array.get jokes (Random.int (Array.length jokes)))
