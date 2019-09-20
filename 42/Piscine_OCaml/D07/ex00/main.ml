(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/22 10:31:37 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/23 23:13:41 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  let jmorien = new People.people "julien" in
  print_endline jmorien#to_string;
  jmorien#talk;
  ignore (jmorien#take_damage 100)
