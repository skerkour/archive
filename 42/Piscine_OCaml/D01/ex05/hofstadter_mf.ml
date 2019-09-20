(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   hofstadter_mf.ml                                   :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/14 14:24:29 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/15 21:36:11 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec hfs_f n =
  if n < 0 then
    (-1)
  else if n == 0 then
    1
  else
    (n - hfs_m (hfs_f (n-1)))

and hfs_m n =
  if n < 0 then
    (-1)
  else if n == 0 then
    0
  else
    (n - hfs_f (hfs_m (n-1)))

let () =
  print_string "Test with [M -42] : "; print_int (hfs_m (-1));
  print_char '\n';
  print_string "Test with [F -42] : "; print_int (hfs_f (-1));
  print_char '\n';
  print_string "Test with [M 0] : "; print_int (hfs_m 0);
  print_char '\n';
  print_string "Test with [F 0] : "; print_int (hfs_f 0);
  print_char '\n';
  print_string "Test with [M 4] : "; print_int (hfs_m 4);
  print_char '\n';
  print_string "Test with [F 4] : "; print_int (hfs_f 4);
  print_char '\n';
