(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   doctor.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/22 11:31:25 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/23 23:11:46 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class doctor name age sidekick =
object (self)
  initializer print_endline (name ^ " has born (doctor)")

  val _name : string = name
  val _age : int = age
  val _sidekick : People.people = sidekick
  val _hp : int = 100

  method to_string =
    _name ^ " : age : " ^ (string_of_int _age) ^ "; sidekick : " ^
      _sidekick#to_string ^ "; hp : " ^ (string_of_int _hp)

  method talk =
    print_endline "Hi! I'm the Doctor!"

  method travel_in_time (start : int) (arrival : int) = (
    print_endline "        ___";
    print_endline "_______(_@_)_______";
    print_endline "| POLICE      BOX |";
    print_endline "|_________________|";
    print_endline " | _____ | _____ |";
    print_endline " | |###| | |###| |";
    print_endline " | |###| | |###| |";
    print_endline " | _____ | _____ |";
    print_endline " | || || | || || |";
    print_endline " | ||_|| | ||_|| |";
    print_endline " | _____ |$_____ |";
    print_endline " | || || | || || |";
    print_endline " | ||_|| | ||_|| |";
    print_endline " | _____ | _____ |";
    print_endline " | || || | || || |";
    print_endline " | ||_|| | ||_|| |";
    print_endline " |       |       |";
    print_endline " *****************"
  )

  method  use_sonic_screwdriver =
    print_endline "Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii"

  method private regenerate =
    new doctor _name _age _sidekick

  method heal =
    self#regenerate
  
  method die =
    print_endline "A doctor passed away"
  
  method take_damage x =
    let hp = if _hp - x <= 0 then 0 else _hp - x in
    if hp <= 0 then self#die;
    {< _hp = hp >}

  method print_hp =
    print_endline @@ string_of_int _hp
end
