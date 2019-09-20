(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   dalek.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/23 11:50:50 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/23 23:07:03 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class dalek =
object (self)

  val _name : string = (
    Random.self_init ();
    let set = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" in
    "Dalek" ^ (String.sub set (Random.int (String.length set)) 1)
    ^ (String.sub set (Random.int (String.length set)) 1)
    ^ (String.sub set (Random.int (String.length set)) 1)
  )
  val _hp : int = 100
  val mutable _shield : bool = true

  method to_string =
    _name ^ " : hp : " ^ (string_of_int _hp) ^
    "; shield : " ^ (string_of_bool _shield)

  method talk =
    Random.self_init ();
    let str = match (Random.int 4) with
      | 0 -> "Explain! Explain!"
      | 1 -> "Exterminate! Exterminate!"
      | 2 -> "I obey!"
      | _ -> "You are the Doctor! You are the enemy of the Daleks!"
     in
     print_endline str

  method exterminate (person : People.people) =
    _shield <- if _shield then false else true;
    person#take_damage 100

  method die =
    print_endline "Emergency Temporal Shift!"

  method take_damage x =
    let hp = if _hp - x <= 0 then 0 else _hp - x in
    if hp <= 0 then self#die;
    {< _hp = hp >}
end
