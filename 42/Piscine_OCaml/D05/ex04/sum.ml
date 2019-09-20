(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   sum.ml                                             :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/20 14:29:13 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/21 15:03:54 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let sum = (+.)

(* tests *)
let () =
  print_float @@ sum 12. 12.; print_char '\n';
  print_float @@ sum 21. 21.; print_char '\n';
  print_float @@ sum 84. (-42.); print_char '\n';
  print_float @@ sum 42. 0.; print_char '\n'
