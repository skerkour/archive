(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/17 17:38:11 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/18 15:37:19 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  Random.self_init ();
  let d1 = Deck.newDeck () in
  let ls1 = Deck.toStringList d1 in
  let lsv1 = Deck.toStringListVerbose d1 in
  List.iter print_endline ls1;
  print_endline "----------------------------------------------";
  List.iter print_endline lsv1;
  print_endline "----------------------------------------------";
  let c1 = Deck.Card.newCard Deck.Card.Value.T2 Deck.Card.Color.Heart in
  let c2 = Deck.Card.newCard Deck.Card.Value.As Deck.Card.Color.Spade in
  let (c3, _) = Deck.drawCard d1 in
  print_endline @@ Deck.Card.toStringVerbose c3;
  let (_, _) = (c1, c2) in
  ();
