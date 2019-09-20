(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   watchtower.ml                                      :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/25 19:28:55 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/25 19:40:34 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type MonoideWatchTower =
sig
  type hour
  val zero : hour
  val add : hour -> hour -> hour val sub : hour -> hour -> hour
end

module MonoideWatchTower =
struct
  type hour = int

  let zero : hour = 12

  let add (x : hour) (y : hour) : hour =
    if (x + y) mod 12 = 0 then 12
    else (x + y) mod 12

  let sub (x:hour) (y:hour) : hour = (
    if (x - y) mod 12 = 0 then 12
    else if (x - y) mod 12 < 0 then ((x - y) mod 12) * -1
    else (x - y) mod 12
  )
end


(* tests *)
let () =
  let h1 : MonoideWatchTower.hour = 12 in
  let h2 : MonoideWatchTower.hour = 13 in
  let h3 : MonoideWatchTower.hour = 42 in
  let h4 : MonoideWatchTower.hour = 6 in
  print_endline @@ string_of_int @@ MonoideWatchTower.add h1 h1;
  print_endline @@ string_of_int @@ MonoideWatchTower.add h4 h1;
  print_endline @@ string_of_int @@ MonoideWatchTower.add h3 h4;
  print_endline @@ string_of_int @@ MonoideWatchTower.add h1 h3;
  print_endline @@ string_of_int @@ MonoideWatchTower.add h1 h2;
  print_endline @@ string_of_int @@ MonoideWatchTower.sub h1 h1;
  print_endline @@ string_of_int @@ MonoideWatchTower.sub h4 h1;
  print_endline @@ string_of_int @@ MonoideWatchTower.sub h3 h4;
  print_endline @@ string_of_int @@ MonoideWatchTower.sub h1 h3;
  print_endline @@ string_of_int @@ MonoideWatchTower.sub h1 h2
