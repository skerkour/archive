(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   leibniz_pi.ml                                      :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/14 16:08:28 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/15 22:06:16 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let leibniz_pi delta =
  if delta < 0. then
    (-1)
  else (
    let pi_ref = 4. *. (atan 1.) in

    let rec compute i acc = (
      let ii = (float_of_int i) in
      let value =  ((-1.) ** ii) /. ((2. *. ii) +. 1.) in
      let computed = (4. *. (acc +. value)) in
      let d = pi_ref -. computed in
      let normalized_delta = if d < 0. then
        (-.d)
      else d in

      if normalized_delta <= delta then
        i + 1
      else
        compute (i+1) (acc +. value)
    ) in compute 0 0.
  )

let () =
  print_string "Test with [1.0] : "; print_int (leibniz_pi 1.0);
  print_char '\n';
  print_string "Test with [0.1] : "; print_int (leibniz_pi 0.1);
  print_char '\n';
  print_string "Test with [0.6] : "; print_int (leibniz_pi 0.6);
  print_char '\n';
  print_string "Test with [0.001] : "; print_int (leibniz_pi 0.001);
  print_char '\n'
