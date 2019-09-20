(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   people.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/22 10:31:35 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/23 23:00:04 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class people name =
object (self)
  val _name : string = name
  val _hp : int = 100

  initializer print_endline (name ^ " has born")

  method to_string =
    _name ^ " : " ^ (string_of_int _hp) ^ " hp"

  method talk =
    print_endline ("I'm " ^ _name ^ "! Do you know the Doctor?")

  method die =
    print_endline "Aaaarghh!"

  method take_damage x =
    let hp = if _hp - x <= 0 then 0 else _hp - x in
    if hp <= 0 then self#die;
    {< _hp = hp >}
    
end
