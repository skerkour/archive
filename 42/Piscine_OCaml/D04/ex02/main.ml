(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/17 15:06:24 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/18 14:30:05 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let print_title title =
  print_endline "-----------------------------------";
  print_endline title;
  print_endline "-----------------------------------"

let () =
  print_title "NEWCARD";
  let c1 = Card.newCard Card.Value.As Card.Color.Spade in
  
  let rec print_all = ( function
    | head::tail -> print_endline @@ Card.toStringVerbose head; print_all tail 
    | [] -> ()
  ) in
  print_title "PRINT ALL SPADE";
  print_all Card.allSpades;
  print_title "PRINT ALL HEARTS";
  print_all Card.allHearts;
  print_title "PRINT ALL DIAMONDS";
  print_all Card.allDiamonds;
  print_title "PRINT ALL CLUBS";
  print_all Card.allClubs;
  print_title "PRINT ALL";
  print_all Card.all;

  print_title "GETVALUE";
  print_endline @@ Card.Value.toStringVerbose @@ Card.getValue c1;
  print_title "GETCOLOR";
  print_endline @@ Card.Color.toStringVerbose @@ Card.getColor c1;
  
  print_title "TOSTRING";
  print_endline @@ Card.toString c1;
  print_title "TOSTRINGVERBOSE";
  print_endline @@ Card.toStringVerbose c1;

  print_title "COMPARE";
  let c2 = Card.newCard Card.Value.King Card.Color.Spade in
  let c3 = Card.newCard Card.Value.King Card.Color.Heart in
  print_endline (Printf.sprintf "Testing with %s %s : %d" (Card.toStringVerbose
  c1) (Card.toStringVerbose c2) (Card.compare c1 c2));
  print_endline (Printf.sprintf "Testing with %s %s : %d" (Card.toStringVerbose
  c2) (Card.toStringVerbose c1) (Card.compare c2 c1));
  print_endline (Printf.sprintf "Testing with %s %s : %d" (Card.toStringVerbose
  c1) (Card.toStringVerbose c1) (Card.compare c1 c1));
  print_endline (Printf.sprintf "Testing with %s %s : %d" (Card.toStringVerbose
  c1) (Card.toStringVerbose c3) (Card.compare c1 c3));
  print_endline (Printf.sprintf "Testing with %s %s : %d" (Card.toStringVerbose
  c2) (Card.toStringVerbose c3) (Card.compare c2 c3));

  print_title "MAX";
  print_endline (Printf.sprintf "Testing with %s %s : %s" (Card.toStringVerbose
  c1) (Card.toStringVerbose c2) (Card.toStringVerbose @@ Card.max c1 c2));
  print_endline (Printf.sprintf "Testing with %s %s : %s" (Card.toStringVerbose
  c2) (Card.toStringVerbose c3) (Card.toStringVerbose @@ Card.max c2 c3));
  
  print_title "MIN";
  print_endline (Printf.sprintf "Testing with %s %s : %s" (Card.toStringVerbose
  c1) (Card.toStringVerbose c2) (Card.toStringVerbose @@ Card.min c1 c2));
  print_endline (Printf.sprintf "Testing with %s %s : %s" (Card.toStringVerbose
  c2) (Card.toStringVerbose c3) (Card.toStringVerbose @@ Card.min c2 c3));

  print_title "BEST";
  let d1 = [c2; Card.newCard Card.Value.T2 Card.Color.Heart; c1; c2; c3] in
  print_endline "Test with : ";
  print_all d1;
  print_endline " -> ";
  print_endline @@ Card.toStringVerbose @@ Card.best d1;

  print_title "ISOF";
  print_endline (Printf.sprintf "Test with %s %s : %B" (Card.toStringVerbose c1)
  (Card.Color.toStringVerbose Card.Color.Spade) (Card.isOf c1
  Card.Color.Spade));
  print_endline (Printf.sprintf "Test with %s %s : %B" (Card.toStringVerbose c3)
  (Card.Color.toStringVerbose Card.Color.Spade) (Card.isOf c3
  Card.Color.Spade));
  print_endline (Printf.sprintf "Test with %s %s : %B" (Card.toStringVerbose c2)
  (Card.Color.toStringVerbose Card.Color.Spade) (Card.isOf c2
  Card.Color.Heart));

  print_title "ISSPADE";
  print_endline (Printf.sprintf "Test with %s : %B" (Card.toStringVerbose c2)
  (Card.isSpade c2));
  print_endline (Printf.sprintf "Test with %s : %B" (Card.toStringVerbose c3)
  (Card.isSpade c3));
  
  print_title "ISHEART";
  print_endline (Printf.sprintf "Test with %s : %B" (Card.toStringVerbose c2)
  (Card.isHeart c2));
  print_endline (Printf.sprintf "Test with %s : %B" (Card.toStringVerbose c3)
  (Card.isHeart c3));
  

  let c4 = Card.newCard Card.Value.T2 Card.Color.Diamond in
  let c5 = Card.newCard Card.Value.T2 Card.Color.Club in
  print_title "ISDIAMOND";
  print_endline (Printf.sprintf "Test with %s : %B" (Card.toStringVerbose c4)
  (Card.isDiamond c4));
  print_endline (Printf.sprintf "Test with %s : %B" (Card.toStringVerbose c3)
  (Card.isSpade c3));

  print_title "ISCLUB";
  print_endline (Printf.sprintf "Test with %s : %B" (Card.toStringVerbose c5)
  (Card.isClub c5));
  print_endline (Printf.sprintf "Test with %s : %B" (Card.toStringVerbose c3)
  (Card.isSpade c3))
