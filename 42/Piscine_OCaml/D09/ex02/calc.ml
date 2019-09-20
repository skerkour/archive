(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   calc.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/06/25 15:17:38 by skerkour          #+#    #+#             *)
(*   Updated: 2016/06/25 17:56:42 by skerkour         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type MONOID =
sig
  type element
  val zero1 : element
  val zero2 : element
  val mul : element -> element -> element
  val add : element -> element -> element
  val div : element -> element -> element
  val sub : element -> element -> element
end

module INT =
struct
  type element = int
  let zero1 = 0
  let zero2 = 1
  let add = ( + )
  let sub = ( - )
  let mul = ( * )
  let div = ( / )
end

module FLOAT =
struct
  type element = float
  let zero1 = 0.
  let zero2 = 1.
  let add = ( +. )
  let sub = ( -. )
  let mul = ( *. )
  let div = ( /. )
end

module Calc =
  functor (M:MONOID) -> struct

  let add x y = M.add x y
  let sub x y = M.sub x y
  let mul x y = M.mul x y
  let div x y = M.div x y

  let rec power x p = (
    let rec power_aux acc x p = (
      if p >= 1 then power_aux (M.mul acc x) x (p-1)
      else acc
    ) in
    if  p == 0 then M.zero1
    else power_aux M.zero2 x p
  )

  let rec fact (n:M.element) = (
    match n with
    | (n:M.element) when (n <= M.zero2) -> M.zero2
    | _ -> M.mul n (fact (M.sub (n:M.element) M.zero2))
  )
end

module Calc_int = Calc(INT)
module Calc_float = Calc(FLOAT)

let () =
  print_endline (string_of_int (Calc_int.power 3 3));
  print_endline (string_of_float (Calc_float.power 3.0 3));
  print_endline (string_of_int (Calc_int.mul (Calc_int.add 20 1) 2));
  print_endline (string_of_float (Calc_float.mul (Calc_float.add 20.0 1.0) 2.0));
  print_endline (string_of_float (Calc_float.power 2. 10));
  print_endline (string_of_float (Calc_float.fact 13.));
  print_endline (string_of_int (Calc_int.fact 13));
  print_endline (string_of_float (Calc_float.sub 63. 21.));
  print_endline (string_of_float (Calc_float.div 42. 2.))
