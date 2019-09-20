(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ribosome.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/16 15:21:01 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/16 22:32:07 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | U | None
type rna = nucleobase list
type aminoacid =  Stop | Ala | Arg | Asn | Asp | Cys | Gln | Glu | Gly | His |
  Ile | Leu | Lys | Met | Phe | Pro | Ser | Thr | Trp | Tyr | Val
type protein = aminoacid list 

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

let generate_rna (h : helix) : rna =
  let rec generate_rna_aux h acc = (
    match h with
    | head::tail -> generate_rna_aux tail (acc @ [head.nucleobase])
    | [] -> acc
  ) in generate_rna_aux (complementary_helix h) []


(* ex07 *)
let generate_bases_triplets (r : rna) =
  let rec generate_bases_triplets_aux r acc = (
    match r with
    | h::s::t::tail -> generate_bases_triplets_aux tail (acc @ [(h, s, t)])
    | _ -> acc
  ) in generate_bases_triplets_aux r []

(*
LOOOOOOOL, taht doesn't wok...
let decode_arn (r : rna) : protein =
  let rec decode_arn_aux triplets acc = (
    match triplets with
    | h::s::tail -> (
      match (h, s) with
      | ((A, A, C), (A, A, U)) -> decode_arn_aux tail (acc @ [Asn])
      | ((G, A, C), (G, A, U)) -> decode_arn_aux tail (acc @ [Asp])
      | ((U, G, C), (U, G, U)) -> decode_arn_aux tail (acc @ [Cys])
      | ((C, A, A), (C, A, G)) -> decode_arn_aux tail (acc @ [Gln])
      | ((G, A, A), (G, A, G)) -> decode_arn_aux tail (acc @ [Glu])
      | ((C, A, C), (C, A, U)) -> decode_arn_aux tail (acc @ [His])
      | ((A, A, A), (A, A, G)) -> decode_arn_aux tail (acc @ [Lys])
      | ((U, U, C), (U, U, U)) -> decode_arn_aux tail (acc @ [Phe])
      | ((U, A, C), (U, A, U)) -> decode_arn_aux tail (acc @ [Tyr])
      | _ -> decode_arn_aux (h :: s :: tail) acc
    )
    | h::s::t::tail -> (
      match (h, s, t) with
      | ((U, A, A), (U, A, G), (U, G, A)) -> acc
      | ((A, U, A), (A, U, C), (A, U, U)) -> decode_arn_aux tail (acc @ [Ile])
      | _ -> decode_arn_aux (h :: s :: t :: tail) acc
    )
    | h::s::t::f::tail -> (
      match (h, s, t, f) with
      | ((G, C, A), (G, C, C), (G, C, G), (G, C, U)) ->
        decode_arn_aux tail (acc @ [Ala])
      | ((G, G, A), (G, G, C), (G, G, G), (G, G, U)) ->
        decode_arn_aux tail (acc @ [Gly])
      | ((C, C, C), (C, C, A), (C, C, G), (C, C, U)) ->
        decode_arn_aux tail (acc @ [Pro])
      | ((A, C, A), (A, C, C), (A, C, G), (A, C, U)) ->
        decode_arn_aux tail (acc @ [Thr])
      | ((G, U, A), (G, U, C), (G, U, G), (G, U, U)) ->
        decode_arn_aux tail (acc @ [Val])
      | _ -> decode_arn_aux (h :: s :: t :: f :: tail) acc
    )
    | h::s::t::f::ff::ss::tail -> (
      match (h, s, t, f, ff, ss) with
      | ((A, G, A), (A, G, G), (C, G, A), (C, G, C), (C, G, G), (C, G, U)) ->
        decode_arn_aux tail (acc @ [Arg])
      | ((C, U, A), (C, U, C), (C, U, G), (C, U, U), (U, U, A), (U, U, G)) ->
        decode_arn_aux tail (acc @ [Leu])
      | ((U, C, A), (U, C, C), (U, C, G), (U, C, U), (A, G, U), (A, G, C)) ->
        decode_arn_aux tail (acc @ [Ser])
      | _ -> decode_arn_aux (h :: s :: t :: f :: ff :: ss :: tail) acc
    )
    | h::tail -> (
      match h with
      | (A, U, G) -> decode_arn_aux tail (acc @ [Met])
      | (U, G, G) -> decode_arn_aux tail (acc @ [Trp])
      | _ -> decode_arn_aux tail acc
    )
    | [] -> acc


  ) in

  let triplets = generate_bases_triplets r in
  decode_arn_aux triplets []
*)

let decode_arn (r: rna) : protein =
  let rec decode_arn_aux r = (
    match r with
    | (U, A, A) :: n | (U, A, G) :: n | (U, G, A) :: n -> Stop :: []
    | (G, C, A) :: n | (G, C, C) :: n | (G, C, G) :: n | (G, C, U) :: n -> Ala :: (decode_arn_aux n)
    | (A, G, A) :: n | (A, G, G) :: n | (C, G, A) :: n | (C, G, C) :: n | (C, G, G) :: n | (C, G, U) :: n -> Arg :: (decode_arn_aux n)
    | (A, A, C) :: n | (A, A, U) :: n -> Asn :: (decode_arn_aux n)
    | (G, A, C) :: n | (G, A, U) :: n -> Asp :: (decode_arn_aux n)
    | (U, G, C) :: n | (U, G, U) :: n -> Cys :: (decode_arn_aux n)
    | (C, A, A) :: n | (C, A, G) :: n -> Gln :: (decode_arn_aux n)
    | (G, A, A) :: n | (G, A, G) :: n -> Glu :: (decode_arn_aux n)
    | (G, G, A) :: n | (G, G, C) :: n | (G, G, G) :: n | (G, G, U) :: n -> Gly :: (decode_arn_aux n)
    | (C, A, C) :: n | (C, A, U) :: n -> His :: (decode_arn_aux n)
    | (A, U, A) :: n | (A, U, C) :: n | (A, U, U) :: n -> Ile :: (decode_arn_aux n)
    | (C, U, A) :: n | (C, U, C) :: n | (C, U, G) :: n | (C, U, U) :: n | (U, U, A) :: n | (U, U, G) :: n -> Leu :: (decode_arn_aux n)
    | (A, A, A) :: n | (A, A, G) :: n -> Lys :: (decode_arn_aux n)
    | (A, U, G) :: n -> Met :: (decode_arn_aux n)
    | (U, U, C) :: n | (U, U, U) :: n -> Phe :: (decode_arn_aux n)
    | (C, C, C) :: n | (C, C, A) :: n | (C, C, G) :: n | (C, C, U) :: n -> Pro :: (decode_arn_aux n)
    | (U, C, A) :: n | (U, C, C) :: n | (U, C, G) :: n | (U, C, U) :: n | (A, G, U) :: n | (A, G, C) :: n -> Ser :: (decode_arn_aux n)
    | (A, C, A) :: n | (A, C, C) :: n | (A, C, G) :: n | (A, C, U) :: n -> Thr :: (decode_arn_aux n)
    | (U, G, G) :: n -> Trp :: (decode_arn_aux n)
    | (U, A, C) :: n |  (U, A, U) :: n -> Tyr :: (decode_arn_aux n)
    | (G, U, A) :: n | (G, U, C) :: n | (G, U, G) :: n | (G, U, U) :: n -> Val :: (decode_arn_aux n)
    | h::t -> decode_arn_aux t
    | [] -> []
  ) in decode_arn_aux @@ generate_bases_triplets r

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


let rec print_protein p =
  match p with
  | Ala :: t -> print_string "Ala "; print_protein t
  | Arg :: t -> print_string "Arg "; print_protein t
  | Asn :: t -> print_string "Asn "; print_protein t
  | Asp :: t -> print_string "Asp "; print_protein t
  | Cys :: t -> print_string "Cys "; print_protein t
  | Gln :: t -> print_string "Gln "; print_protein t
  | Glu :: t -> print_string "Glu "; print_protein t
  | Gly :: t -> print_string "Gly "; print_protein t
  | His :: t -> print_string "his "; print_protein t
  | Ile :: t -> print_string "ile "; print_protein t
  | Leu :: t -> print_string "Leu "; print_protein t
  | Lys :: t -> print_string "Lys "; print_protein t
  | Met :: t -> print_string "Met "; print_protein t
  | Phe :: t -> print_string "Phe "; print_protein t
  | Pro :: t -> print_string "Pro "; print_protein t
  | Ser :: t -> print_string "Ser "; print_protein t
  | Thr :: t -> print_string "Thr "; print_protein t
  | Trp :: t -> print_string "Trp "; print_protein t
  | Tyr :: t -> print_string "Tyr "; print_protein t
  | Val :: t -> print_string "Val "; print_protein t
  | Stop :: t -> print_char '\n'
  | _ -> print_char '\n'

let () =
  Random.self_init ();
  let h1 = generate_helix 4200 in
  let r1 = generate_rna h1 in
  print_endline @@ helix_to_string h1;
  print_rna r1;
  print_protein @@ decode_arn r1
