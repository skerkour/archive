(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   encode.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/15 11:33:24 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/16 18:18:39 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let encode lst = 
  let rec encode_map = ( function
    | head::tail -> (1, head) :: encode_map tail
    | [] -> []
  ) in

  let rec encode_reduce lst acc = (
    match lst with
    | head::second::tail -> (
      let (n, x) = head in
      let (nn, xx) = second in

      if x = xx  && tail = [(1, x)] then encode_reduce [] (acc @ [(n + 2, x)])
      else if x = xx  then encode_reduce ([(n + 1, x)] @ tail) acc
      else encode_reduce ([second] @ tail) (acc @ [head]) 
    )
    | head::tail -> encode_reduce tail (acc @ [head])
    | [] -> acc
  ) in

  let mapped = encode_map lst in
  encode_reduce mapped []

(* tests *)
let print_list_int_encoded lst =
  print_char '[';
  let rec print_int_aux lst = (
    match lst with
      | head::tail -> (
        let (n, x) = head in
        print_char '('; print_int n; print_string ", "; print_int x;
        print_char ')';
        if tail <> [] then print_string "; "; 
        print_int_aux tail
      )
      | [] -> print_endline "]"
  ) in print_int_aux lst

let print_list_int lst =
  print_char '[';
  let rec print_int_aux lst = (
    match lst with
      | head::tail -> (
        print_int head;
        if tail <> [] then print_string "; "; 
        print_int_aux tail
      )
      | [] -> print_endline "]"
  ) in print_int_aux lst

let test_lst_int lst =
  print_string "Test with : ";
  print_list_int lst;
  print_list_int_encoded @@ encode lst;
  print_endline "----------------------"

let print_list_char_encoded lst =
  print_char '[';
  let rec print_char_aux lst = (
    match lst with
      | head::tail -> (
        let (n, x) = head in
        print_char '('; print_int n; print_string ", "; print_char x;
        print_char ')';
        if tail <> [] then print_string "; "; 
        print_char_aux tail
      )
      | [] -> print_endline "]"
  ) in print_char_aux lst

let print_list_char lst =
  print_char '[';
  let rec print_char_aux lst = (
    match lst with
      | head::tail -> (
        print_char head;
        if tail <> [] then print_string "; "; 
        print_char_aux tail
      )
      | [] -> print_endline "]"
  ) in print_char_aux lst

let test_lst_char lst =
  print_string "Test with : ";
  print_list_char lst;
  print_list_char_encoded @@ encode lst;
  print_endline "----------------------"

let () =
  test_lst_int [1; 2; 3; 4; 5];
  test_lst_int [1; 2];
  test_lst_int [1; 1];
  test_lst_int [1; 1; 1];
  test_lst_int [1; 2; 3];
  test_lst_int [1; 2; 2; 3];
  test_lst_int [1; 2; 2; 2; 3];
  test_lst_int [1; 2; 2; 2; 2; 3];
  test_lst_int [1; 2; 2; 2; 2; 2; 2; 2; 2; 2; 3];
  test_lst_int [1; 1; 3; 4; 5];
  test_lst_int [1; 1; 1; 3; 4; 5];
  test_lst_int [1; 1; 1; 3; 4; 5; 5];
  test_lst_int [1; 1; 1; 3; 4; 5; 5 ;5];
  test_lst_int [1; 1; 1; 3; 4; 5; 5 ;5];
  test_lst_char ['a'; 'b'; 'b'; 'c'; 'e'; 'e'; 'e']
