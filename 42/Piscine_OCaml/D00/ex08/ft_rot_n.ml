(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_rot_n.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/13 14:20:10 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/14 20:59:45 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_rot_n n str =
  let ft_rot_char c = (
    if c >= 'a' && c <= 'z' then
      char_of_int (((((int_of_char c) - 0x61) + n) mod 26) + 0x61)
    else if c >= 'A' && c <= 'Z' then
      char_of_int (((((int_of_char c) - 0x41) + n) mod 26) + 0x41)
    else
      c
  ) in
  String.map ft_rot_char str

let main () =
  print_string "Test with [1 abcdefghijklmnopqrstuvwxyz] : ";
  print_endline (ft_rot_n 1 "abcdefghijklmnopqrstuvwxyz");
  print_string "Test with [13 abcdefghijklmnopqrstuvwxyz] : ";
  print_endline (ft_rot_n 13 "abcdefghijklmnopqrstuvwxyz");
  print_string "Test with [42 0123456789] : ";
  print_endline (ft_rot_n 42 "0123456789");
  print_string "Test with [2 OI2EAS67B9] : ";
  print_endline (ft_rot_n 2 "OI2EAS67B9");
  print_string "Test with [42 OI2EAS67B9] : ";
  print_endline (ft_rot_n 42 "OI2EAS67B9");
  print_string "Test with [0 Damned !] : ";
  print_endline (ft_rot_n 0 "Damned !");
  print_string "Test with [1 NBzlk qnbjr !] : ";
  print_endline (ft_rot_n 1 "NBzlk qnbjr !")


let () = main ()
