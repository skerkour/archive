(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/22 10:31:37 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/23 23:03:27 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  let jmorien = new People.people "julien" in
  let who = new Doctor.doctor "pi" 42 jmorien in
  let d = new Dalek.dalek in

  let ap = new Army.army in
  let ap = ap#add jmorien in
  let ap = ap#add jmorien in
  ap#print_length;
  let ap = ap#delete in
  let ap = ap#delete in
  ap#print_length;

  let dp = new Army.army in
  let dp = dp#add who in
  let dp = dp#add who in
  dp#print_length;
  let dp = dp#delete in
  let dp = dp#delete in
  dp#print_length;

  let dap = new Army.army in
  let dap = dap#add d in
  let dap = dap#add d in
  dap#print_length;
  let dap = dap#delete in
  let dap = dap#delete in
  dap#print_length
