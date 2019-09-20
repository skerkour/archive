(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   helix.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/15 22:32:03 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/16 18:44:50 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | None

type nucleotide = {
  phosphate : phosphate;
  deoxyribose : deoxyribose;
  nucleobase : nucleobase
}

type helix = nucleotide list

let generate_helix n : helix =
  let int_to_nucleobase i = (
    match i with
    | 0 -> A
    | 1 -> T
    | 2 -> C
    | 3 -> G
    | _ -> None
  ) in

  let create_random_nucleotide () = (
    {
      phosphate = "phosphate";
      deoxyribose = "deoxyribose";
      nucleobase = int_to_nucleobase (Random.int 4)
    }
  ) in

  let rec generate_helix_aux n acc = (
    if n <= 0 then
      acc
    else
      generate_helix_aux (n-1) (create_random_nucleotide () :: acc)
  ) in generate_helix_aux n []


let helix_to_string (h : helix) =
  let nucleobase_to_string = ( function
    | A -> "A"
    | T -> "T"
    | C -> "C"
    | G -> "G"
    | _ -> "None"
  ) in

  let rec helix_to_string_aux h acc = (
    match h with
    | he::t -> helix_to_string_aux t (acc ^ (nucleobase_to_string he.nucleobase))
    | [] -> acc
  ) in helix_to_string_aux h ""


let complementary_helix (h : helix) =
  let create_nucleotide_from_nuclobase n = (
    {
      phosphate = "phosphate";
      deoxyribose = "deoxyribose";
      nucleobase = n
    }
  ) in

  let complementary_nucleotide n = (
    match n.nucleobase with
    | A -> create_nucleotide_from_nuclobase T
    | T -> create_nucleotide_from_nuclobase A
    | C -> create_nucleotide_from_nuclobase G
    | G -> create_nucleotide_from_nuclobase C 
    | _ -> create_nucleotide_from_nuclobase None
  ) in

  let rec complementary_helix_aux h acc = (
    match h with
    | he::t -> complementary_helix_aux t (acc @ [complementary_nucleotide he])
    | [] -> acc
  ) in complementary_helix_aux h []


(* tests *)
let () =
  Random.self_init ();
  let h1 = generate_helix 420 in
  let c1 = complementary_helix h1 in
  print_endline @@ helix_to_string h1;
  print_endline @@ helix_to_string c1;
  print_endline "-----------------------------------";
  let h2 = generate_helix 42 in
  let c2 = complementary_helix h2 in
  print_endline @@ helix_to_string h2;
  print_endline @@ helix_to_string c2;
  print_endline "-----------------------------------";
  let h3 = generate_helix 42 in
  let c3 = complementary_helix h3 in
  print_endline @@ helix_to_string h3;
  print_endline @@ helix_to_string c3;
  print_endline "-----------------------------------";
  let h4 = generate_helix 0 in
  let c4 = complementary_helix h4 in
  print_endline @@ helix_to_string h4;
  print_endline @@ helix_to_string c4;
  print_endline "-----------------------------------";
  let h5 = generate_helix (-42) in
  let c5 = complementary_helix h5 in
  print_endline @@ helix_to_string h5;
  print_endline @@ helix_to_string c5
