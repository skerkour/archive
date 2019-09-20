(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   repeat_string.ml                                   :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/14 12:00:23 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/15 21:24:54 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let repeat_string ?str:(str="x") n =
  if n < 0 then
    "Error"
  else if n == 0 then
    ""
  else (
    let rec repeat_string_aux n acc = (
      if n <= 0 then
        acc
      else
        repeat_string_aux (n-1) (acc^str)
    )
    in repeat_string_aux (n-1) str
  )


let () =
  print_string "Test with [-1] : "; print_string (repeat_string (-1));
  print_char '\n';
  print_string "Test with [0] : "; print_string (repeat_string 0);
  print_char '\n';
  print_string "Test with [1] : ";
  print_string (repeat_string 1); print_char '\n';
  print_string "Test with [Toto 1] : ";
  print_string (repeat_string ~str:"Toto" 1); print_char '\n';
  print_string "Test with [2] : "; print_string (repeat_string 2);
  print_char '\n';
  print_string "Test with [Toto 2] : ";
  print_string (repeat_string ~str:"Toto" 2); print_char '\n';
  print_string "Test with [5] : "; print_string (repeat_string 5);
  print_char '\n';
  print_string "Test with [Toto 5] : ";
  print_string (repeat_string ~str:"Toto" 5); print_char '\n'
