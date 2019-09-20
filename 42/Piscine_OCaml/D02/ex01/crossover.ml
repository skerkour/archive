(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   crossover.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/15 16:14:35 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/16 21:07:32 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let crossover l1 l2 = 
  let rec contains x s = (
    match s with
    | h::t -> (x = h) || contains x t
    | [] -> false
  ) in
  
  let rec crossover_aux l1 l2 = (
    match l1 with
    | h::t -> if (contains h l2) then h::(crossover_aux t l2)
      else crossover_aux t l2
    | [] -> []
  ) in

  crossover_aux l1 l2


(* tests *)
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


let test_lst_int a b =
  print_endline "Test with : ";
  print_list_int a;
  print_list_int b;
  print_endline "=";
  print_list_int @@ crossover a b;
  print_endline "---------------------"

let () =
  test_lst_int [1; 2; 3] [];
  test_lst_int [] [1; 2; 3];
  test_lst_int [1; 1; 2; 3; 4] [1; 2];
  test_lst_int [1; 1; 2; 3; 4] [1; 2];
  test_lst_int [1; 1; 2; 3; 4; 4; 5; 6; 7; 8; 9; 0] [1; 2; 1; 2; 4]
