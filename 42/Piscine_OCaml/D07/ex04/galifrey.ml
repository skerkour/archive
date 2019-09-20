(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   galifrey.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/23 23:00:18 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/23 23:43:35 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class galifrey =
object (self)
  val _daleks : Dalek.dalek Army.army = new Army.army
  val _doctors : Doctor.doctor Army.army = new Army.army
  val _peoples : People.people Army.army = new Army.army


  method add_people x =
    {< _peoples = _peoples#add x >}
  
  method add_dalek x =
    {< _daleks = _daleks#add x >}
  
  method add_doctor x =
    {< _doctors = _doctors#add x >}

  method do_time_war = (
    if _daleks#length > 0 && _doctors#length > 0 && _peoples#length > 0 then (
      print_endline "THIS IS THE BEGINNING OF THE END !";
      let doc = _doctors#head in
      let dal = _daleks#head in
      let pe = _peoples#head in
      doc#use_sonic_screwdriver;
      let dal =  dal#take_damage 50 in
      let doc = doc#take_damage 42 in
      doc#travel_in_time 42 42;
      doc#use_sonic_screwdriver;
      let dal = dal#take_damage 42 in
      dal#exterminate pe;
      doc#use_sonic_screwdriver;
      ignore(dal#take_damage 42)
    ) else ()
  )

end
