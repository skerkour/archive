(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   rna.ml                                             :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/16 11:54:20 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/16 19:44:33 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | U | None
type rna = nucleobase list

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
    | U -> "U"
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

  let complementary_nucleotide nucleotide = (
    match nucleotide.nucleobase with
    | A -> create_nucleotide_from_nuclobase U
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

(* ex06 *)
let generate_rna (h : helix) : rna =
  let rec generate_rna_aux h acc = (
    match h with
    | head::tail -> generate_rna_aux tail (acc @ [head.nucleobase])
    | [] -> acc
  ) in generate_rna_aux (complementary_helix h) []



(* tests *)

let print_rna r =
  let nucleobase_to_string = ( function
    | A -> "A"
    | T -> "T"
    | C -> "C"
    | G -> "G"
    | U -> "U"
    | _ -> "None"
  ) in

  let rec print_rna_aux  = ( function
    | head::tail -> print_string @@ nucleobase_to_string head; print_rna_aux tail
    | [] -> print_char '\n'
  ) in print_rna_aux r


let () =
  Random.self_init ();
  let h1 = [{nucleobase=A;phosphate="";deoxyribose=""};
  {nucleobase=T;phosphate="";deoxyribose=""};
  {nucleobase=C;phosphate="";deoxyribose=""};
  {nucleobase=G;phosphate="";deoxyribose=""};
  {nucleobase=A;phosphate="";deoxyribose=""}] in
  let r1 = generate_rna h1 in
  print_endline @@ helix_to_string h1;
  print_rna r1;
  print_endline "---------------------------";
  let h2 = generate_helix 42 in
  let r2 = generate_rna h2 in
  print_endline @@ helix_to_string h2;
  print_rna r2;
  print_endline "---------------------------";
  let h3 = generate_helix 12 in
  let r3 = generate_rna h3 in
  print_endline @@ helix_to_string h3;
  print_rna r3;
  print_endline "---------------------------"
