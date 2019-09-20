(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   jokes.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/20 13:27:50 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/21 14:26:03 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let jokes =
  [|
    "Why was the guitar teacher arrested ? For fingering a minor.";
    "What's the difference between a hooker and a drug dealer ? A hooker can wash her crack and resell it.";
    "What's the difference between a Catholic priest and a zit ? A zit will wait until you’re twelve before it comes on your face.";
    "5/4 of people admit that they’re bad with fractions.";
    "I asked your dad for his best dad joke and he said, 'You'.";
    "What's the difference between a woman with PMS and a terrorist ? You can negotiate with a terrorist."
  |]

let () =
  Random.self_init ();
  print_endline (Array.get jokes (Random.int (Array.length jokes)))
