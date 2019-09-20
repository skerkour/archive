(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   fibonacci.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/14 13:58:35 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/15 21:33:34 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let fibonacci n =
  if n < 0 then
    -1
  else (
    let rec fibonacci_aux x y n = (
      if n <= 0 then
        x
      else
        fibonacci_aux y (x+y) (n-1)
    )
    in fibonacci_aux 0 1 n
  )



let () =
  print_string "Test with [-42] : "; print_int (fibonacci (-42));
  print_char '\n';
  print_string "Test with [0] : "; print_int (fibonacci 0);
  print_char '\n';
  print_string "Test with [1] : "; print_int (fibonacci 1);
  print_char '\n';
  print_string "Test with [3] : "; print_int (fibonacci 3);
  print_char '\n';
  print_string "Test with [6] : "; print_int (fibonacci 6);
  print_char '\n';
  print_string "Test with [42] : "; print_int (fibonacci 42);
  print_char '\n';
  print_string "Test with [75] : "; print_int (fibonacci 75);
  print_char '\n';
