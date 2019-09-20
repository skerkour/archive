(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/22 10:31:37 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/23 23:12:38 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  let jmorien = new People.people "julien" in
  let who = new Doctor.doctor "pi" 42 jmorien in
  print_endline jmorien#to_string;
  jmorien#talk;
  jmorien#die;
  print_endline "--------------------------------";
  print_endline who#to_string;
  who#travel_in_time 42 42;
  who#talk;
  who#use_sonic_screwdriver;
  let who = who#take_damage 42 in
  who#print_hp;
  let who = who#heal in
  who#print_hp;
  ignore (who#take_damage 100)
