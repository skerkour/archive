(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/24 00:32:29 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/24 12:25:34 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  let c = new Carbon.carbon in
  let h = new Hydrogen.hydrogen in
  let o = new Oxygen.oxygen in
  let k = new Potassium.potassium in
  let kr = new Krypton.krypton in
  let hg = new Mercury.mercury in
  let au = new Gold.gold in
  let pt = new Platinium.platinium in
  let pu = new Plutonium.plutonium in
  let n = new Nitrogen.nitrogen in
  let fr = new Francium.francium in
  let na = new Sodium.sodium in
  let cl = new Chlorine.chlorine in
  print_endline c#to_string;
  print_endline h#to_string;
  print_endline o#to_string;
  print_endline k#to_string;
  print_endline kr#to_string;
  print_endline hg#to_string;
  print_endline au#to_string;
  print_endline pt#to_string;
  print_endline pu#to_string;
  print_endline n#to_string;
  print_endline fr#to_string;
  print_endline na#to_string;
  print_endline cl#to_string;
  print_endline @@ string_of_bool @@ cl#equals cl;
  print_endline @@ string_of_bool @@ fr#equals n;
  print_endline @@ string_of_bool @@ au#equals au;
  print_endline @@ string_of_bool @@ na#equals hg;
  print_endline @@ string_of_bool @@ pt#equals pu;
  print_endline @@ string_of_bool @@ cl#equals na
