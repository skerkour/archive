(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/22 10:31:37 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/23 23:34:12 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  let gal = new Galifrey.galifrey in
  let jmorien = new People.people "julien" in
  let who = new Doctor.doctor "pi" 42 jmorien in
  let d = new Dalek.dalek in

  let gal = gal#add_doctor who in
  let gal = gal#add_people jmorien in
  let gal = gal#add_dalek d in

  gal#do_time_war
