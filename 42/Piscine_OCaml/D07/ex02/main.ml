(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/22 10:31:37 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/23 23:09:22 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  let jmorien = new People.people "julien" in
  let who = new Doctor.doctor "pi" 42 jmorien in
  let d = new Dalek.dalek in
  print_endline jmorien#to_string;
  print_endline who#to_string;
  print_endline d#to_string;

  who#use_sonic_screwdriver;
  let d = d#take_damage 50 in

  d#talk;
  d#talk;
  ignore (d#exterminate jmorien);
  who#use_sonic_screwdriver;
  ignore (d#take_damage 50)
