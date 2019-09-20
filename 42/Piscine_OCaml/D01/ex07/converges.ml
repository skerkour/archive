(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   converges.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/14 15:21:20 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/15 21:52:31 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)


let rec converges fn x n =
  if n < 0 then
    false
  else if n == 0 then
    x == (fn x)
  else
    x == (fn x) || converges fn (fn x) (n-1)

let () =
  print_string "Test with [(( * ) 2) 2 5] : ";
  print_endline (string_of_bool (converges (( * ) 2) 2 5));
  print_string "Test with [(fun x -> x / 2) 2 3] : ";
  print_endline (string_of_bool (converges (fun x -> x / 2) 2 3));
  print_string "Test with [(fun x -> x / 2) 2 2] : ";
  print_endline (string_of_bool (converges (fun x -> x / 2) 2 2));
  print_string "Test with [(fun x -> x * x) 1 42] : ";
  print_endline (string_of_bool (converges (fun x -> x * x) 1 42));
  print_string "Test with [(fun x -> x * x - 3*x + 4) 2 1] : ";
  print_endline (string_of_bool (converges (fun x -> x * x - 3 * x + 4) 2 1));
  print_string "Test with [(fun x -> x * x - 3*x + 4) 2 42] : ";
  print_endline (string_of_bool (converges (fun x -> x * x - 3 * x + 4) 2 42));
  print_string "Test with [(fun x -> x * x - 3*x + 4) 3 42] : ";
  print_endline (string_of_bool (converges (fun x -> x * x - 3 * x + 4) 3 42));
