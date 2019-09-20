(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   sequence.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/15 18:39:13 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/16 18:35:17 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)



let rec sequence n =

  let encode lst = (
    let rec encode_map lst = (
      match lst with
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
  ) in

  let decode lst = (
    let rec decode_aux lst acc = (
      match lst with
      | head::tail -> (
        let (n, x) = head in
        decode_aux tail (acc @ [n; x])
      )
      | [] -> acc
    ) in decode_aux lst []
  ) in

  let rec lst_int_to_str lst acc = (
    match lst with
    | x::tail -> lst_int_to_str tail (acc ^ string_of_int x)
    | [] -> acc
  ) in

  if n = 0 then
    lst_int_to_str [1] ""
  else (
    let rec sequence_aux n acc = (
      if n <= 0 then
        acc
      else
        sequence_aux (n-1) (decode @@ encode acc)
    ) in
    lst_int_to_str (sequence_aux n [1]) ""
  )


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

let test_lst_int n =
  print_string "Test with : ";
  print_int n; print_char '\n';
  print_endline @@ sequence n

let () =
  test_lst_int 0;
  test_lst_int 1;
  test_lst_int 2;
  test_lst_int 3;
  test_lst_int 4;
  test_lst_int 5;
  test_lst_int 6;
  test_lst_int 7;
  test_lst_int 8
