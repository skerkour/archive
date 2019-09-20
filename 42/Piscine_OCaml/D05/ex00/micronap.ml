(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   micronap.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/20 10:31:21 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/21 14:13:26 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let my_sleep () = Unix.sleep 1

let main argc argv =
  if argc = 2 then (
    try 
      let x = int_of_string argv.(1) in
      for i = 0 to x - 1 do
        my_sleep ()
      done
    with
    | _ -> invalid_arg "argv 1 should be an integer"
  ) else
    invalid_arg "Two arguments are required"

let () =
  try main (Array.length Sys.argv) Sys.argv with
  | _ -> ()
