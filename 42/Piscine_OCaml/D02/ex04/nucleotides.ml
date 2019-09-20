(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   nucleotides.ml                                     :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/15 22:13:22 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/15 22:30:27 by skerkour         ###   ########.fr       *)
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

let generate_nucleotide c =
  let nucleobase_from_char c = (
    match c with
    | 'A' -> A
    | 'T' -> T
    | 'C' -> C
    | 'G' -> G
    | _ -> None
  ) in
  {
    phosphate = "phosphate";
    deoxyribose = "deoxyribose";
    nucleobase = nucleobase_from_char c
  }


(* tests *)

let print_nucleotide nuc =
  let print_nucleobase n = (
    match n with
    | A -> print_char 'A'
    | T -> print_char 'T'
    | C -> print_char 'C'
    | G -> print_char 'G'
    | None -> print_string "None"
  ) in
  print_char '{'; print_string nuc.phosphate; print_string ", ";
  print_string nuc.deoxyribose; print_string ", ";
  print_nucleobase nuc.nucleobase; print_endline "}"

let () =
  print_nucleotide (generate_nucleotide 'A');
  print_nucleotide (generate_nucleotide 'F');
  print_nucleotide (generate_nucleotide 'T');
  print_nucleotide (generate_nucleotide 'C');
  print_nucleotide (generate_nucleotide 'G')
