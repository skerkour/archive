(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   eu_dist.ml                                         :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/20 14:32:46 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/21 15:08:55 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let eu_dist a b =
  let n = (Array.length a) - 1 in
  let sum = ref 0. in
  for i = 0 to n do
    sum := !sum +. ((a.(i) -. b.(i)) ** 2.)
  done;
  sqrt !sum

let () =
  let a = [|1.; 2.; 3.; 4.; 5.; 6.|] in
  let b = [|1.; 2.; 3.; 4.; 5.; 6.|] in
  let c = [|2.; 2.; 4.; 4.; 5.; 6.|] in
  print_float @@ eu_dist a b; print_char '\n';
  print_float @@ eu_dist a c; print_char '\n'
