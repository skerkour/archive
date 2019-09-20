(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/17 10:14:45 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/17 10:24:20 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  print_endline @@ Color.toString Color.Spade;
  print_endline @@ Color.toString Color.Heart;
  print_endline @@ Color.toString Color.Diamond;
  print_endline @@ Color.toString Color.Club;
  print_endline @@ Color.toStringVerbose Color.Spade;
  print_endline @@ Color.toStringVerbose Color.Heart;
  print_endline @@ Color.toStringVerbose Color.Diamond;
  print_endline @@ Color.toStringVerbose Color.Club;
